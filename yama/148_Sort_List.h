/*Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5*/

/*Runtime: 48 ms, faster than 64.09% of C++ online submissions for Sort List.
Memory Usage: 25 MB, less than 11.14% of C++ online submissions for Sort List.*/

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
    ListNode * sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        auto fast = pre;
        auto slow = pre;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto temp = slow->next;
        slow->next = nullptr;
        auto l = sortList(pre->next);
        auto r = sortList(temp);
        auto cur = pre;
        while (l || r)
        {
            if (l && r)
            {
                if (l->val < r->val)
                {
                    cur->next = l;
                    l = l->next;
                }
                else
                {
                    cur->next = r;
                    r = r->next;
                }
            }
            else if (l)
            {
                cur->next = l;
                l = l->next;
            }
            else
            {
                cur->next = r;
                r = r->next;
            }
            cur = cur->next;
        }
        return pre->next;
    }
};