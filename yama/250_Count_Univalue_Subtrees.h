/*Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

Example :

Input:  root = [5,1,5,5,5,null,5]

              5
             / \
            1   5
           / \   \
          5   5   5

Output: 4*/

/*Runtime: 8 ms, faster than 71.66% of C++ online submissions for Count Univalue Subtrees.
Memory Usage: 14.8 MB, less than 87.11% of C++ online submissions for Count Univalue Subtrees.*/

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
    bool search(TreeNode* root, int& res)
    {
        if (root == nullptr) return true;
        bool l = search(root->left, res);
        bool r = search(root->right, res);
        if (l && r)
        {
            if (root->left && root->val != root->left->val || root->right && root->val != root->right->val)
                return false;
            else
            {
                res++;
                return true;
            }
        }
        return false;
    }
    int countUnivalSubtrees(TreeNode* root) {
        int res = 0;
        search(root, res);
        return res;
    }
};