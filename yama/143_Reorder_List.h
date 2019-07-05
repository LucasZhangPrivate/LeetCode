/*Given a singly linked list L: L0¡úL1¡ú¡­¡úLn-1¡úLn,
reorder it to: L0¡úLn¡úL1¡úLn-1¡úL2¡úLn-2¡ú¡­

You may not modify the values in the list's nodes, only nodes itself may be changed.

Example 1:

Given 1->2->3->4, reorder it to 1->4->2->3.
Example 2:

Given 1->2->3->4->5, reorder it to 1->5->2->4->3.*/

/*Runtime: 44 ms, faster than 97.26% of C++ online submissions for Reorder List.
Memory Usage: 12 MB, less than 83.99% of C++ online submissions for Reorder List.*/

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
    void reorderList(ListNode* head) {
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        auto fast = pre;
        auto slow = pre;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto head1 = slow->next;
        slow->next = nullptr;
        ListNode* last = nullptr;
        while (head1)
        {
            auto temp = head1->next;
            head1->next = last;
            last = head1;
            head1 = temp;
        }
        auto l = head;
        auto r = last;

        while (l && r)
        {
            pre->next = l;
            l = l->next;
            pre = pre->next;
            pre->next = r;
            r = r->next;
            pre = pre->next;
        }
        if (l)pre->next = l;
    }
};