/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.*/

/*Runtime: 24 ms, faster than 91.70% of C++ online submissions for Add Two Numbers.
Memory Usage: 10.3 MB, less than 77.31% of C++ online submissions for Add Two Numbers.*/

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
        int carry = 0;
        ListNode* res = new ListNode(-1);
        auto head = res;
        while (l1 || l2 || carry != 0)
        {
            if (l1 && l2)
            {
                carry = l1->val + l2->val + carry;
                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1)
            {
                carry = l1->val + carry;
                l1 = l1->next;
            }
            else if (l2)
            {
                carry = l2->val + carry;
                l2 = l2->next;
            }
            head->next = new ListNode(carry % 10);
            head = head->next;
            carry /= 10;
        }
        return res->next;
    }
};