/*Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.

Two trees are duplicate if they have the same structure with same node values.

Example 1:

        1
       / \
      2   3
     /   / \
    4   2   4
       /
      4
The following are two duplicate subtrees:

      2
     /
    4
and

    4
Therefore, you need to return above trees' root in the form of a list.*/

/*Runtime: 36 ms, faster than 97.21% of C++ online submissions for Find Duplicate Subtrees.
Memory Usage: 64.2 MB, less than 20.83% of C++ online submissions for Find Duplicate Subtrees.*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//不是自己做的，算法简单，开始没想到
class Solution {
public:
    unordered_map<string, int> m;
    string util(TreeNode *root, vector<TreeNode *> &res)
    {
        if (!root)
            return "";
        string left = util(root->left, res);
        string right = util(root->right, res);
        string curr = "l" + left + "r" + right + "c" + to_string(root->val);
        if (m[curr] == 1)
            res.push_back(root);
        m[curr]++;
        return curr;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if (!root)
            return {};
        vector<TreeNode *> res;
        if (!root)
            return res;
        util(root, res);
        return res;
    }
};