// 0002. Add Two Numbers
// Problem definition: https://leetcode.com/problems/add-two-numbers/

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

impl ListNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

pub struct Solution;

impl Solution {
    /// Solution 1: Iterative solution using a dummy head.
    /// - Time Complexity: O(max(m, n))
    /// - Space Complexity: O(max(m, n))
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut l1, mut l2) = (l1, l2);
        let mut dummy = Box::new(ListNode::new(0));
        let mut tail = &mut dummy;
        let mut carry = 0;

        while l1.is_some() || l2.is_some() || carry != 0 {
            let v1 = match l1 {
                Some(node) => {
                    l1 = node.next;
                    node.val
                }
                None => 0,
            };
            let v2 = match l2 {
                Some(node) => {
                    l2 = node.next;
                    node.val
                }
                None => 0,
            };

            let total = v1 + v2 + carry;
            carry = total / 10;
            tail.next = Some(Box::new(ListNode::new(total % 10)));
            tail = tail.next.as_mut().unwrap();
        }

        dummy.next
    }

    /// Solution 2: Optimized In-Place Node Reuse with Early Exit
    /// - Time Complexity: O(min(m, n)) best case, O(max(m, n)) worst case
    /// - Space Complexity: O(1) auxiliary heap allocations
    ///
    /// Optimizations:
    /// 1. Mutates `l1`'s existing `Box<ListNode>` allocations in place instead of
    ///    allocating new nodes on every digit.
    /// 2. If `l1` is shorter than `l2`, splices the remaining tail of `l2` onto `l1`
    ///    in a single O(1) pointer move (`*curr = l2.take()`).
    /// 3. Short-circuits as soon as `l2` is exhausted and `carry == 0`, leaving the
    ///    remaining tail of `l1` untouched.
    /// 4. Replaces `/ 10` and `% 10` with a simple `sum >= 10` comparison and subtraction.
    pub fn add_two_numbers_in_place(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let (mut l1, mut l2) = (l1, l2);
        let mut curr = &mut l1;
        let mut carry = 0;

        loop {
            if curr.is_none() {
                *curr = l2.take();
            }

            match curr {
                Some(node) => {
                    if l2.is_none() && carry == 0 {
                        break;
                    }
                    let v2 = match l2 {
                        Some(n2) => {
                            l2 = n2.next;
                            n2.val
                        }
                        None => 0,
                    };

                    let sum = node.val + v2 + carry;
                    if sum >= 10 {
                        node.val = sum - 10;
                        carry = 1;
                    } else {
                        node.val = sum;
                        carry = 0;
                    }
                    curr = &mut node.next;
                }
                None => {
                    if carry > 0 {
                        *curr = Some(Box::new(ListNode::new(carry)));
                    }
                    break;
                }
            }
        }

        l1
    }

    /// Solution 3: Recursive solution (mirrors lc/0002.cpp).
    /// - Time Complexity: O(max(m, n))
    /// - Space Complexity: O(max(m, n)) call stack + heap
    pub fn add_two_numbers_recursive(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
    ) -> Option<Box<ListNode>> {
        Self::add(l1, l2, 0)
    }

    fn add(
        l1: Option<Box<ListNode>>,
        l2: Option<Box<ListNode>>,
        carry: i32,
    ) -> Option<Box<ListNode>> {
        if l1.is_none() && l2.is_none() && carry == 0 {
            return None;
        }

        let (v1, next1) = l1.map_or((0, None), |node| (node.val, node.next));
        let (v2, next2) = l2.map_or((0, None), |node| (node.val, node.next));

        let total = v1 + v2 + carry;
        Some(Box::new(ListNode {
            val: total % 10,
            next: Self::add(next1, next2, total / 10),
        }))
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    fn from_slice(vals: &[i32]) -> Option<Box<ListNode>> {
        let mut current = None;
        for &v in vals.iter().rev() {
            current = Some(Box::new(ListNode {
                val: v,
                next: current,
            }));
        }
        current
    }

    fn check(l1: &[i32], l2: &[i32], expected: &[i32]) {
        let exp = from_slice(expected);
        assert_eq!(
            Solution::add_two_numbers(from_slice(l1), from_slice(l2)),
            exp
        );
        assert_eq!(
            Solution::add_two_numbers_in_place(from_slice(l1), from_slice(l2)),
            exp
        );
        assert_eq!(
            Solution::add_two_numbers_recursive(from_slice(l1), from_slice(l2)),
            exp
        );
    }

    #[test]
    fn test_lc_case_1() {
        check(&[2, 4, 3], &[5, 6, 4], &[7, 0, 8]);
    }

    #[test]
    fn test_lc_case_2() {
        check(&[0], &[0], &[0]);
    }

    #[test]
    fn test_lc_case_3() {
        check(
            &[9, 9, 9, 9, 9, 9, 9],
            &[9, 9, 9, 9],
            &[8, 9, 9, 9, 0, 0, 0, 1],
        );
    }

    #[test]
    fn test_asymmetric_lengths() {
        check(&[1, 2], &[1, 2, 3, 4, 5], &[2, 4, 3, 4, 5]);
    }
}
