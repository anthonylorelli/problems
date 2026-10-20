// 0003. Longest Substring Without Repeating Characters
// Problem definition: https://leetcode.com/problems/longest-substring-without-repeating-characters/

pub struct Solution;

impl Solution {
    /// Solution 1: Sliding Window with Last-Seen Index Table (Optimized)
    /// - Time Complexity: O(n) single pass
    /// - Space Complexity: O(1) auxiliary space (fixed-size array on stack, zero allocations)
    ///
    /// Stores the 1-based index of the last occurrence of each character.
    /// When a duplicate character is encountered, the left boundary (`start`)
    /// jumps directly past the previous occurrence without shrinking one step at a time.
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut last_pos = [0usize; 128];
        let mut max_len = 0;
        let mut start = 0;

        for (i, &b) in s.as_bytes().iter().enumerate() {
            let idx = b as usize;
            if idx < 128 {
                start = start.max(last_pos[idx]);
                max_len = max_len.max(i - start + 1);
                last_pos[idx] = i + 1;
            }
        }

        max_len as i32
    }

    /// Solution 2: Sliding Window with Frequency Counts (Mirrors lc/0003.cpp)
    /// - Time Complexity: O(n) (at most 2n steps)
    /// - Space Complexity: O(1) auxiliary space
    ///
    /// Expands the `right` pointer while incrementing character counts.
    /// If a duplicate is detected (`count > 1`), advances `left` pointer
    /// and decrements counts until the window is valid again.
    pub fn length_of_longest_substring_counts(s: String) -> i32 {
        let bytes = s.as_bytes();
        let mut counts = [0i32; 128];
        let mut left = 0;
        let mut max_len = 0;

        for right in 0..bytes.len() {
            let r_idx = bytes[right] as usize;
            if r_idx < 128 {
                counts[r_idx] += 1;
                while counts[r_idx] > 1 {
                    let l_idx = bytes[left] as usize;
                    if l_idx < 128 {
                        counts[l_idx] -= 1;
                    }
                    left += 1;
                }
            }
            max_len = max_len.max(right - left + 1);
        }

        max_len as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn check(input: &str, expected: i32) {
        assert_eq!(
            Solution::length_of_longest_substring(input.to_string()),
            expected
        );
        assert_eq!(
            Solution::length_of_longest_substring_counts(input.to_string()),
            expected
        );
    }

    #[test]
    fn test_case_1() {
        check("abcabcbb", 3);
    }

    #[test]
    fn test_case_2() {
        check("bbbbb", 1);
    }

    #[test]
    fn test_case_3() {
        check("pwwkew", 3);
    }

    #[test]
    fn test_case_4() {
        check("abcdef", 6);
    }

    #[test]
    fn test_case_5() {
        check("", 0);
    }

    #[test]
    fn test_case_6() {
        check("a", 1);
    }
}
