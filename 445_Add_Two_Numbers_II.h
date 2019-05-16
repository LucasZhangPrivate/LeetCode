/*You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Follow up:
What if you cannot modify the input lists? In other words, reversing the lists is not allowed.

Example:

Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 8 -> 0 -> 7*/
/*Runtime: 28 ms, faster than 96.20% of C++ online submissions for Add Two Numbers II.
Memory Usage: 13.1 MB, less than 99.00% of C++ online submissions for Add Two Numbers II.*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
    ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> a, b;
        while (l1)
        {
            a.push(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            b.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* res = nullptr;
        while (!a.empty() || !b.empty() || carry != 0)
        {
            if (!a.empty())
            {
                carry += a.top();
                a.pop();
            }
            if (!b.empty())
            {
                carry += b.top();
                b.pop();
            }
            int cur = carry % 10;
            ListNode* curN = new ListNode(cur);
            curN->next = res;
            res = curN;
            carry /= 10;
        }
        return res;
    }
};