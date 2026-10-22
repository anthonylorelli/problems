// 0005. Longest Palindromic Substring
// Problem definition: https://leetcode.com/problems/longest-palindromic-substring/

pub struct Solution;

impl Solution {
    /// Solution 1: Manacher's Algorithm
    /// - Time Complexity: O(n) linear time
    /// - Space Complexity: O(n) auxiliary space
    ///
    /// Transforms the input string by interleaving delimiter `#` and sentinels `^` and `$`
    /// (`^#a#b#a#$`) so that odd- and even-length palindromes are treated uniformly and
    /// boundaries do not require explicit range checks. Uses previous palindrome symmetry
    /// to expand the radius in amortized linear time.
    pub fn longest_palindrome(s: String) -> String {
        if s.is_empty() {
            return String::new();
        }

        let bytes = s.as_bytes();
        let mut t = Vec::with_capacity(bytes.len() * 2 + 3);
        t.push(b'^');
        for &b in bytes {
            t.push(b'#');
            t.push(b);
        }
        t.push(b'#');
        t.push(b'$');

        let mut p = vec![0usize; t.len()];
        let mut c = 0;
        let mut r = 0;
        let mut max_len = 0;
        let mut center = 0;

        for i in 1..t.len() - 1 {
            if i < r {
                p[i] = (r - i).min(p[2 * c - i]);
            }

            // Expand palindrome centered at i
            while t[i + p[i] + 1] == t[i - p[i] - 1] {
                p[i] += 1;
            }

            // Update center and right boundary if expanded past current r
            if i + p[i] > r {
                c = i;
                r = i + p[i];
            }

            if p[i] > max_len {
                max_len = p[i];
                center = i;
            }
        }

        let start = (center - max_len) / 2;
        s[start..start + max_len].to_string()
    }

    /// Solution 2: Expand Around Center with Duplicate Run Skipping
    /// - Time Complexity: O(n^2) worst case, O(n) best/average case
    /// - Space Complexity: O(1) auxiliary space (zero heap allocations)
    ///
    /// Considers each unique contiguous run of identical characters as a single palindrome
    /// core, handling odd/even lengths together and jumping past duplicates before expanding outward.
    pub fn longest_palindrome_expand(s: String) -> String {
        if s.len() <= 1 {
            return s;
        }

        let bytes = s.as_bytes();
        let mut start = 0;
        let mut max_len = 1;

        let mut i = 0;
        while i < bytes.len() {
            let mut left = i;
            let mut right = i;

            // Expand through identical characters (the palindrome core)
            while right + 1 < bytes.len() && bytes[right + 1] == bytes[left] {
                right += 1;
            }
            // Next center search starts after identical run
            i = right + 1;

            // Expand outward while symmetric characters match
            while left > 0 && right + 1 < bytes.len() && bytes[left - 1] == bytes[right + 1] {
                left -= 1;
                right += 1;
            }

            let len = right - left + 1;
            if len > max_len {
                max_len = len;
                start = left;
            }
        }

        s[start..start + max_len].to_string()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn check(input: &str, expected: &str) {
        assert_eq!(
            Solution::longest_palindrome(input.to_string()),
            expected
        );
        assert_eq!(
            Solution::longest_palindrome_expand(input.to_string()),
            expected
        );
    }

    #[test]
    fn test_empty() {
        check("", "");
    }

    #[test]
    fn test_single_char() {
        check("a", "a");
    }

    #[test]
    fn test_two_chars() {
        check("ac", "a");
    }

    #[test]
    fn test_babad() {
        check("babad", "bab");
    }

    #[test]
    fn test_cbbd() {
        check("cbbd", "bb");
    }

    #[test]
    fn test_all_same() {
        check("aaaaaaa", "aaaaaaa");
    }
}
