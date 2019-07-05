/*Remove all elements from a linked list of integers that have value val.

Example:

Input:  1->2->6->3->4->5->6, val = 6
Output: 1->2->3->4->5*/

/*Runtime: 28 ms, faster than 79.27% of C++ online submissions for Remove Linked List Elements.
Memory Usage: 10.8 MB, less than 89.43% of C++ online submissions for Remove Linked List Elements.*/

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
    ListNode * removeElements(ListNode* head, int val) {
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        auto keep = pre;
        while (pre->next)
        {
            if (pre->next->val == val)
            {
                pre->next = pre->next->next;
            }
            else pre = pre->next;
        }
        return keep->next;
    }
};