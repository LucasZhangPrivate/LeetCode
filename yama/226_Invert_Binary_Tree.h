/*Invert a binary tree.

Example:

Input:

     4
   /   \
  2     7
 / \   / \
1   3 6   9
Output:

     4
   /   \
  7     2
 / \   / \
9   6 3   1
Trivia:
This problem was inspired by this original tweet by Max Howell:

Google: 90% of our engineers use the software you wrote (Homebrew), but you can��t invert a binary tree on a whiteboard so f*** off.*/

/*Runtime: 4 ms, faster than 77.43% of C++ online submissions for Invert Binary Tree.
Memory Usage: 9.2 MB, less than 41.68% of C++ online submissions for Invert Binary Tree.*/

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
    TreeNode * invertTree(TreeNode* root) {
        if (root == nullptr) return root;
        auto l = invertTree(root->left);
        auto r = invertTree(root->right);
        root->left = r;
        root->right = l;
        return root;
    }
};