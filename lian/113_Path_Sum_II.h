/*Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

Note: A leaf is a node with no children.

Example:

Given the below binary tree and sum = 22,

      5
     / \
    4   8
   /   / \
  11  13  4
 /  \    / \
7    2  5   1
Return:

[
   [5,4,11,2],
   [5,8,4,5]
]*/

/*Runtime: 20 ms, faster than 59.55% of C++ online submissions for Path Sum II.
Memory Usage: 36.4 MB, less than 21.23% of C++ online submissions for Path Sum II.*/

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
    void help(vector<vector<int>>& res, vector<int> temp, TreeNode* root, int sum)
    {
        if (root == nullptr)return;
        if (root->left == nullptr && root->right == nullptr)
        {
            if (sum == root->val)
            {
                temp.push_back(root->val);
                res.push_back(temp);
            }
            return;
        }
        temp.push_back(root->val);
        help(res, temp, root->left, sum - root->val);
        help(res, temp, root->right, sum - root->val);
        temp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        help(res, temp, root, sum);
        return res;
    }
};