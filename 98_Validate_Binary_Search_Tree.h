/*Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:

    2
   / \
  1   3

Input: [2,1,3]
Output: true
Example 2:

    5
   / \
  1   4
     / \
    3   6

Input: [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.*/

/*Runtime: 20 ms, faster than 86.99% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 20.7 MB, less than 31.46% of C++ online submissions for Validate Binary Search Tree.*/

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
    bool check(TreeNode* root, long min, long max)
    {
        if (root == nullptr) return true;
        if (root->val <= min || root->val >= max) return false;
        return (check(root->left, min, root->val) && check(root->right, root->val, max));
    }
    bool isValidBST(TreeNode* root) {
        return check(root, LONG_MIN, LONG_MAX); //注意用long，不然会超过界限
    }
};