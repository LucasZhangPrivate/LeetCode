/*Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]*/

/*Runtime: 8 ms, faster than 93.39% of C++ online submissions for Binary Tree Level Order Traversal II.
Memory Usage: 14.8 MB, less than 22.83% of C++ online submissions for Binary Tree Level Order Traversal II.*/

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
    void convert(vector<vector<int>>& res, TreeNode* root, int level)
    {
        if (root == nullptr) return;
        if (level == res.size())res.push_back(vector<int>());
        res[level].push_back(root->val);
        convert(res, root->left, level + 1);
        convert(res, root->right, level + 1);
    }
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        convert(res, root, 0);
        reverse(res.begin(), res.end());
        return res;
    }
};