/*Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example 1:

Given the following tree [3,9,20,null,null,15,7]:

    3
   / \
  9  20
    /  \
   15   7
Return true.

Example 2:

Given the following tree [1,2,2,3,3,null,null,4,4]:

       1
      / \
     2   2
    / \
   3   3
  / \
 4   4
Return false.*/

/*Runtime: 12 ms, faster than 96.82% of C++ online submissions for Balanced Binary Tree.
Memory Usage: 17.3 MB, less than 50.97% of C++ online submissions for Balanced Binary Tree.*/

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
    int deep(TreeNode* root)
    {
        if (root == nullptr) return 0;
        return 1 + max(deep(root->left), deep(root->right));
    }
    bool isBalanced(TreeNode* root) {
        if (root == nullptr) return true;
        auto l = deep(root->left);
        auto r = deep(root->right);
        if (abs(l - r)>1)return false;
        else
        {
            return isBalanced(root->left) && isBalanced(root->right);
        }
    }
};