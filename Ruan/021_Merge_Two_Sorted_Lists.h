/*Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4*/

/*Runtime: 8 ms, faster than 94.87% of C++ online submissions for Merge Two Sorted Lists.
Memory Usage: 8.8 MB, less than 89.39% of C++ online submissions for Merge Two Sorted Lists.*/

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
    ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pre = new ListNode(-1);
        auto keep = pre;
        while (l1 || l2)
        {
            if (l1 && l2)
            {
                if (l1->val < l2->val)
                {
                    pre->next = l1;
                    l1 = l1->next;
                }
                else
                {
                    pre->next = l2;
                    l2 = l2->next;
                }

            }
            else if (l1)
            {
                pre->next = l1;
                l1 = l1->next;
            }
            else
            {
                pre->next = l2;
                l2 = l2->next;
            }
            pre = pre->next;
        }
        return keep->next;
    }
};