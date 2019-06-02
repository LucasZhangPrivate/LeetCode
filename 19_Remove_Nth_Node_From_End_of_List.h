/*Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?*/

/*Runtime: 4 ms, faster than 97.15% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 8.7 MB, less than 53.70% of C++ online submissions for Remove Nth Node From End of List.*/

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
    ListNode * removeNthFromEnd(ListNode* head, int n) {
        if (head == nullptr)return head;
        ListNode* post = new ListNode(-1);
        post->next = head;
        auto cur = post;
        auto keep = post;
        while (n-->0)
        {
            post = post->next;
        }
        while (post->next != nullptr)
        {
            post = post->next;
            cur = cur->next;
        }
        auto temp = cur->next;

        cur->next = cur->next->next;
        delete temp;
        return keep->next;
    }
};