/*Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3
 

But the following [1,2,2,null,3,null,3] is not:

    1
   / \
  2   2
   \   \
   3    3
 

Note:
Bonus points if you could solve it both recursively and iteratively.*/

/*Runtime: 8 ms, faster than 90.86% of C++ online submissions for Symmetric Tree.
Memory Usage: 14.7 MB, less than 81.50% of C++ online submissions for Symmetric Tree.*/

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
    bool check(TreeNode* left, TreeNode* right)
    {
        if (left == nullptr && right == nullptr) return true;
        else if (left == nullptr || right == nullptr) return false;
        if (left->val != right->val)return false;
        return check(left->right, right->left) && check(left->left, right->right);

    }
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr) return true;
        return check(root->left, root->right);
    }
};