/*Given a linked list, swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, only nodes itself may be changed.

 

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
Memory Usage: 8.8 MB, less than 51.02% of C++ online submissions for Swap Nodes in Pairs.*/

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
    ListNode * swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* pre = new ListNode(-1);
        ListNode* keep = pre;
        pre->next = head;

        while (head && head->next)
        {
            ListNode* keep = head->next->next;
            pre->next = head->next;
            head->next->next = head;
            pre = head;
            head = keep;
        }
        pre->next = head;
        return keep->next;
    }
};

/*Runtime: 4 ms, faster than 92.96% of C++ online submissions for Swap Nodes in Pairs.
Memory Usage: 8.7 MB, less than 55.28% of C++ online submissions for Swap Nodes in Pairs.*/
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
    ListNode * swapPairs(ListNode* head)
    {
        if ((head == nullptr) || head->next == nullptr)return head;
        ListNode *n = head->next;
        head->next = swapPairs(head->next->next);
        n->next = head;
        return n;
    }
};
