/*Given a sorted linked list, delete all duplicates such that each element appear only once.

Example 1:

Input: 1->1->2
Output: 1->2
Example 2:

Input: 1->1->2->3->3
Output: 1->2->3*/

/*Runtime: 12 ms, faster than 95.05% of C++ online submissions for Remove Duplicates from Sorted List.
Memory Usage: 9.3 MB, less than 27.92% of C++ online submissions for Remove Duplicates from Sorted List.*/

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
    ListNode * deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)return head;
        ListNode *p = head;
        while (p->next)
        {
            if (p->val != p->next->val)
                p = p->next;
            else
            {
                ListNode *temp = p->next;
                p->next = p->next->next;
                delete temp;
            }

        }
        return head;
    }
};


class Solution {
public:
    ListNode * deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        ListNode* keep = nullptr;
        while (pre->next && pre->next->next)
        {
            if (pre->next->val == pre->next->next->val)
            {
                pre->next = pre->next->next;
            }
            else
            {
                pre = pre->next;
                if (keep == nullptr) keep = pre;
            }

        }
        if (keep == nullptr) keep = pre->next;
        return keep;

    }
};


