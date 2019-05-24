/*Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.

Example:

Input: [1,2,3,null,5,null,4]
Output: [1, 3, 4]
Explanation:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---*/

/*Runtime: 4 ms, faster than 96.39% of C++ online submissions for Binary Tree Right Side View.
Memory Usage: 9.7 MB, less than 25.67% of C++ online submissions for Binary Tree Right Side View.*/

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
    void find(TreeNode* root, int level, vector<int>& res)
    {
        if (root == nullptr) return;
        if (res.size() == level)
        {
            res.push_back(root->val);
        }
        find(root->right, level + 1, res);
        find(root->left, level + 1, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        find(root, 0, res);
        return res;
    }
};