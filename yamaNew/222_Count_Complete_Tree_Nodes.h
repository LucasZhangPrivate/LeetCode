/*Given a complete binary tree, count the number of nodes.

Note:

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

Example:

Input: 
    1
   / \
  2   3
 / \  /
4  5 6

Output: 6*/

/*Runtime: 32 ms, faster than 85.07% of C++ online submissions for Count Complete Tree Nodes.
Memory Usage: 28.6 MB, less than 82.49% of C++ online submissions for Count Complete Tree Nodes.*/

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
    int countNodes(TreeNode* root) {
        if (root == nullptr) return 0;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};