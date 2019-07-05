/*Find the sum of all left leaves in a given binary tree.

Example:

    3
   / \
  9  20
    /  \
   15   7

There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Sum of Left Leaves.
Memory Usage: 13.6 MB, less than 41.43% of C++ online submissions for Sum of Left Leaves.*/

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
    void sum(TreeNode* root, int& res)
    {
        if (root == nullptr || root->left == nullptr && root->right == nullptr)return;
        if (root->left && root->left->left == nullptr && root->left->right == nullptr)
        {
            res += root->left->val;
        }
        sum(root->left, res);
        sum(root->right, res);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        int res = 0;
        sum(root, res);
        return res;
    }
};