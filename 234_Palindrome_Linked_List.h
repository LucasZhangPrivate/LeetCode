/*Given a singly linked list, determine if it is a palindrome.

Example 1:

Input: 1->2
Output: false
Example 2:

Input: 1->2->2->1
Output: true
Follow up:
Could you do it in O(n) time and O(1) space?*/

/*Runtime: 20 ms, faster than 97.67% of C++ online submissions for Palindrome Linked List.
Memory Usage: 12.7 MB, less than 57.15% of C++ online submissions for Palindrome Linked List.*/

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
    ListNode * reverse(ListNode* head)
    {
        ListNode* pre = nullptr;
        while (head != nullptr)
        {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return true;
        auto slow = head;
        auto fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto tail = reverse(slow);
        while (tail)
        {
            if (tail->val != head->val)return false;
            tail = tail->next;
            head = head->next;
        }
        return true;
    }
};