// 0004. Median of Two Sorted Arrays
// Problem definition: https://leetcode.com/problems/median-of-two-sorted-arrays/

pub struct Solution;

impl Solution {
    /// Solution 1: Optimized Binary Search with O(1) Fast Paths
    /// - Time Complexity: O(1) for empty or non-overlapping arrays; O(log(min(m, n))) general
    /// - Space Complexity: O(1) auxiliary space (zero heap allocations)
    ///
    /// Optimizations:
    /// 1. O(1) Empty Array Fast Path: If one array is empty, looks up median directly by index.
    /// 2. O(1) Non-Overlapping Fast Path: If all elements of one array precede the other,
    ///    directly indexes into the virtual concatenated array without binary searching.
    /// 3. Binary Search on Smaller Array: Partitions the smaller array with balanced left/right halves.
    pub fn find_median_sorted_arrays(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let (a, b) = if nums1.len() <= nums2.len() {
            (&nums1[..], &nums2[..])
        } else {
            (&nums2[..], &nums1[..])
        };

        let m = a.len();
        let n = b.len();

        // Fast-path 1: Empty array (O(1))
        if m == 0 {
            return if n % 2 == 1 {
                b[n / 2] as f64
            } else {
                (b[n / 2 - 1] + b[n / 2]) as f64 * 0.5
            };
        }

        // Fast-path 2: Non-overlapping arrays (O(1))
        if a[m - 1] <= b[0] {
            let mid1 = (m + n - 1) / 2;
            let mid2 = (m + n) / 2;
            let get = |idx: usize| if idx < m { a[idx] } else { b[idx - m] };
            return (get(mid1) + get(mid2)) as f64 * 0.5;
        }
        if b[n - 1] <= a[0] {
            let mid1 = (m + n - 1) / 2;
            let mid2 = (m + n) / 2;
            let get = |idx: usize| if idx < n { b[idx] } else { a[idx - n] };
            return (get(mid1) + get(mid2)) as f64 * 0.5;
        }

        // General Binary Search on partition of smaller array
        let total_left = (m + n + 1) / 2;
        let mut low = 0;
        let mut high = m;

        while low <= high {
            let i = low + (high - low) / 2;
            let j = total_left - i;

            let max_left_a = if i == 0 { i32::MIN } else { a[i - 1] };
            let min_right_a = if i == m { i32::MAX } else { a[i] };

            let max_left_b = if j == 0 { i32::MIN } else { b[j - 1] };
            let min_right_b = if j == n { i32::MAX } else { b[j] };

            if max_left_a > min_right_b {
                high = i - 1;
            } else if max_left_b > min_right_a {
                low = i + 1;
            } else {
                let max_left = max_left_a.max(max_left_b);
                if (m + n) % 2 == 1 {
                    return max_left as f64;
                }

                let min_right = min_right_a.min(min_right_b);
                return (max_left as f64 + min_right as f64) * 0.5;
            }
        }

        0.0
    }

    /// Solution 2: Pure Binary Search Partition (Mirrors lc/0004.cpp)
    /// - Time Complexity: O(log(min(m, n)))
    /// - Space Complexity: O(1) auxiliary space
    pub fn find_median_sorted_arrays_binary_search(nums1: Vec<i32>, nums2: Vec<i32>) -> f64 {
        let (a, b) = if nums1.len() <= nums2.len() {
            (&nums1[..], &nums2[..])
        } else {
            (&nums2[..], &nums1[..])
        };

        let m = a.len();
        let n = b.len();
        let total_left = (m + n + 1) / 2;

        let mut low = 0;
        let mut high = m;

        while low <= high {
            let i = low + (high - low) / 2;
            let j = total_left - i;

            let max_left_a = if i == 0 { i32::MIN } else { a[i - 1] };
            let min_right_a = if i == m { i32::MAX } else { a[i] };

            let max_left_b = if j == 0 { i32::MIN } else { b[j - 1] };
            let min_right_b = if j == n { i32::MAX } else { b[j] };

            if max_left_a > min_right_b {
                high = i - 1;
            } else if max_left_b > min_right_a {
                low = i + 1;
            } else {
                let max_left = max_left_a.max(max_left_b);
                if (m + n) % 2 == 1 {
                    return max_left as f64;
                }

                let min_right = min_right_a.min(min_right_b);
                return (max_left as f64 + min_right as f64) * 0.5;
            }
        }

        0.0
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn check(nums1: &[i32], nums2: &[i32], expected: f64) {
        let r1 = Solution::find_median_sorted_arrays(nums1.to_vec(), nums2.to_vec());
        let r2 = Solution::find_median_sorted_arrays_binary_search(nums1.to_vec(), nums2.to_vec());
        assert!((r1 - expected).abs() < 1e-9);
        assert!((r2 - expected).abs() < 1e-9);
    }

    #[test]
    fn test_case_1() {
        check(&[1, 3], &[2], 2.0);
    }

    #[test]
    fn test_case_2() {
        check(&[1, 2], &[3, 4], 2.5);
    }

    #[test]
    fn test_case_3() {
        check(&[0, 0], &[0, 0], 0.0);
    }

    #[test]
    fn test_case_4() {
        check(&[], &[1], 1.0);
    }

    #[test]
    fn test_case_5() {
        check(&[2], &[], 2.0);
    }

    #[test]
    fn test_non_overlapping_a_before_b() {
        check(&[1, 2], &[3, 4, 5], 3.0);
        check(&[1, 2], &[3, 4], 2.5);
    }

    #[test]
    fn test_non_overlapping_b_before_a() {
        check(&[4, 5], &[1, 2, 3], 3.0);
        check(&[3, 4], &[1, 2], 2.5);
    }
}
