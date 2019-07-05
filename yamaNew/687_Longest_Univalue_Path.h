/*Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.

The length of path between two nodes is represented by the number of edges between them.

 

Example 1:

Input:

              5
             / \
            4   5
           / \   \
          1   1   5
Output: 2

 

Example 2:

Input:

              1
             / \
            4   5
           / \   \
          4   4   5
Output: 2

 

Note: The given binary tree has not more than 10000 nodes. The height of the tree is not more than 1000.*/

/*Runtime: 120 ms, faster than 95.92% of C++ online submissions for Longest Univalue Path.
Memory Usage: 49.6 MB, less than 68.88% of C++ online submissions for Longest Univalue Path.*/

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
    int help(TreeNode* root, int& res)
    {
        if (root == nullptr)return 0;
        int left = help(root->left, res);
        int right = help(root->right, res);
        int l = 0, r = 0;
        if (root->left && root->left->val == root->val)
        {
            l += left + 1;
        }
        if (root->right && root->right->val == root->val)
        {
            r += right + 1;
        }
        res = max(res, l + r);
        return max(r, l);
    }
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        help(root, res);
        return res;
    }
};