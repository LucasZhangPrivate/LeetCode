/*Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]*/

/*Runtime: 8 ms, faster than 89.91% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 14.2 MB, less than 12.19% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.*/

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
    void tra(vector<vector<int>>& res, TreeNode* root, int level)
    {
        if (root == nullptr) return;
        if (level == res.size())res.push_back(vector<int>());
        if (level % 2 == 0)res[level].push_back(root->val);
        else res[level].insert(res[level].begin(), root->val);
        tra(res, root->left, level + 1);
        tra(res, root->right, level + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        tra(res, root, 0);
        return res;
    }
};