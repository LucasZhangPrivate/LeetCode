/*Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Given linked list -- head = [4,5,1,9], which looks like following:



 

Example 1:

Input: head = [4,5,1,9], node = 5
Output: [4,1,9]
Explanation: You are given the second node with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
Example 2:

Input: head = [4,5,1,9], node = 1
Output: [4,5,9]
Explanation: You are given the third node with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.*/

/*Runtime: 12 ms, faster than 97.88% of C++ online submissions for Delete Node in a Linked List.
Memory Usage: 9.4 MB, less than 5.39% of C++ online submissions for Delete Node in a Linked List.*/

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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
        auto d = node->next;
        node->next = node->next->next;
        delete d;
    }
};