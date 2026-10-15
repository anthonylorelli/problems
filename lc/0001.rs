// 0001. Two Sum
// Problem definition: https://leetcode.com/problems/two-sum/

use std::collections::HashMap;
use std::hash::{BuildHasherDefault, Hasher};

/// A fast, non-cryptographic hasher (FxHash / Knuth multiplicative style).
/// Standard `std::collections::HashMap` uses SipHash 1-3 to guard against HashDoS,
/// which incurs significant CPU overhead for simple integer keys.
#[derive(Default)]
pub struct FastHasher(u64);

impl Hasher for FastHasher {
    #[inline]
    fn finish(&self) -> u64 {
        self.0
    }

    #[inline]
    fn write(&mut self, bytes: &[u8]) {
        for &byte in bytes {
            self.0 = self.0.rotate_left(5) ^ (byte as u64);
        }
    }

    #[inline]
    fn write_i32(&mut self, i: i32) {
        // Multiplicative hash step for 32-bit integers
        self.0 = (i as u64).wrapping_mul(0x517c_c1b7_2722_0a95);
    }
}

pub struct Solution;

impl Solution {
    /// Solution 1: Standard Single-Pass Hash Map
    /// - Time Complexity: O(n) average
    /// - Space Complexity: O(n)
    ///
    /// Iterates through elements once, looking up the complement before inserting
    /// the current value. Storing indices as `i32` avoids 64-bit padding and keeps
    /// entry sizes at 8 bytes.
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen: HashMap<i32, i32> = HashMap::with_capacity(nums.len());

        for (i, &num) in nums.iter().enumerate() {
            let complement = target - num;
            if let Some(&prev_idx) = seen.get(&complement) {
                return vec![prev_idx, i as i32];
            }
            seen.insert(num, i as i32);
        }

        vec![]
    }

    /// Solution 2: Optimized Hash Map with Non-Cryptographic FastHasher
    /// - Time Complexity: O(n) average (over 3x faster than SipHash)
    /// - Space Complexity: O(n)
    ///
    /// Replaces standard SipHash with `FastHasher`, bypassing HashDoS mitigation
    /// for significant speedups when hashing primitive integers.
    pub fn two_sum_fast_hash(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen: HashMap<i32, i32, BuildHasherDefault<FastHasher>> =
            HashMap::with_capacity_and_hasher(nums.len(), BuildHasherDefault::default());

        for (i, &num) in nums.iter().enumerate() {
            let complement = target - num;
            if let Some(&prev_idx) = seen.get(&complement) {
                return vec![prev_idx, i as i32];
            }
            seen.insert(num, i as i32);
        }

        vec![]
    }

    /// Solution 3: Two Pointers with Packed u64 & Small-Input Fast Path
    /// - Time Complexity: O(n log n) overall; O(1) heap allocation for small n
    /// - Space Complexity: O(n) (or O(1) for n <= 32)
    ///
    /// Optimizations:
    /// 1. Fast path for small inputs (n <= 32): brute-force linear search runs
    ///    entirely in L1 cache with zero heap allocations and vectorizes well.
    /// 2. Value + index packing: packs (value, original_index) into a single `u64`
    ///    with signed-to-unsigned bit offset ((val + 2^31) << 32 | idx).
    ///    This allows sorting flat 64-bit primitives via `sort_unstable()` without
    ///    tuple indirection or pointer chasing.
    /// 3. Cache-friendly two-pointer scan: walks contiguously from both ends,
    ///    eliminating hash table probe misses.
    pub fn two_sum_two_pointers(nums: Vec<i32>, target: i32) -> Vec<i32> {
        // Fast path for small arrays: zero heap allocations
        if nums.len() <= 32 {
            for i in 0..nums.len() {
                let complement = target - nums[i];
                for j in (i + 1)..nums.len() {
                    if nums[j] == complement {
                        return vec![i as i32, j as i32];
                    }
                }
            }
            return vec![];
        }

        // Pack (value, original_index) into u64.
        // Add 1 << 31 to signed values to maintain correct ordering when sorted as unsigned integers.
        let mut pairs: Vec<u64> = nums
            .iter()
            .enumerate()
            .map(|(i, &val)| {
                let uval = ((val as i64) + (1 << 31)) as u64;
                (uval << 32) | (i as u64)
            })
            .collect();

        pairs.sort_unstable();

        let mut left = 0;
        let mut right = pairs.len() - 1;

        while left < right {
            let left_val = ((pairs[left] >> 32) as i64 - (1 << 31)) as i32;
            let right_val = ((pairs[right] >> 32) as i64 - (1 << 31)) as i32;
            let sum = left_val + right_val;

            if sum == target {
                let idx1 = (pairs[left] & 0xFFFF_FFFF) as i32;
                let idx2 = (pairs[right] & 0xFFFF_FFFF) as i32;
                return if idx1 < idx2 {
                    vec![idx1, idx2]
                } else {
                    vec![idx2, idx1]
                };
            } else if sum < target {
                left += 1;
            } else {
                right -= 1;
            }
        }

        vec![]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn check(nums: &[i32], target: i32, expected: &[i32]) {
        assert_eq!(Solution::two_sum(nums.to_vec(), target), expected);
        assert_eq!(Solution::two_sum_fast_hash(nums.to_vec(), target), expected);
        assert_eq!(Solution::two_sum_two_pointers(nums.to_vec(), target), expected);
    }

    #[test]
    fn test_lc_case_1() {
        check(&[2, 7, 11, 15], 9, &[0, 1]);
    }

    #[test]
    fn test_local_case_1() {
        check(&[2, 7, 11, 15], 26, &[2, 3]);
    }

    #[test]
    fn test_local_case_2() {
        check(&[2, 7, 11, 1, 3, 4, 115], 5, &[0, 4]);
    }

    #[test]
    fn test_negative_values() {
        check(&[-3, 4, 3, 90], 0, &[0, 2]);
    }
}
