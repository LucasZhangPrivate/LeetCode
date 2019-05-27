/*Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted linked list: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5*/

/*Runtime: 32 ms, faster than 90.69% of C++ online submissions for Convert Sorted List to Binary Search Tree.
Memory Usage: 27.4 MB, less than 5.00% of C++ online submissions for Convert Sorted List to Binary Search Tree.*/

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
    TreeNode * sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* pre = new ListNode(-1);
        pre->next = head;
        auto fast = head;
        auto slow = head;
        while (fast&& fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            pre = pre->next;
        }
        auto head2 = slow->next;
        slow->next = nullptr;
        TreeNode* cur = new TreeNode(slow->val);
        if (pre->next != head)
        {
            pre->next = nullptr;
        }
        else head = nullptr;
        cur->left = sortedListToBST(head);
        cur->right = sortedListToBST(head2);
        return cur;
    }
};