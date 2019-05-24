/*Reverse a singly linked list.

Example:

Input: 1->2->3->4->5->NULL
Output: 5->4->3->2->1->NULL
Follow up:

A linked list can be reversed either iteratively or recursively. Could you implement both?*/

/*Runtime: 4 ms, faster than 99.83% of C++ online submissions for Reverse Linked List.
Memory Usage: 9.3 MB, less than 17.34% of C++ online submissions for Reverse Linked List.*/

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
    ListNode * reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

class Solution {
public:
    ListNode * reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};