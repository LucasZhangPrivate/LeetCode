/*Reverse a linked list from position m to n. Do it in one-pass.

Note: 1 ¡Ü m ¡Ü n ¡Ü length of list.

Example:

Input: 1->2->3->4->5->NULL, m = 2, n = 4
Output: 1->4->3->2->5->NULL*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Linked List II.
Memory Usage: 8.7 MB, less than 60.97% of C++ online submissions for Reverse Linked List II.*/

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
    ListNode * reverseBetween(ListNode* head, int m, int n) {
        ListNode* keep = new ListNode(-1);
        keep->next = head;
        auto pre = keep;
        int count = m;
        while (count>1)
        {
            count--;
            pre = pre->next;
        }
        count = n - m;
        ListNode* temp = nullptr;
        auto pre2 = pre->next;
        auto cur = pre2;
        auto next = cur->next;
        while (count-->0)
        {
            temp = next->next;
            next->next = cur;
            cur = next;
            next = temp;
        }
        pre->next = cur;
        pre2->next = next;
        return keep->next;
    }
};