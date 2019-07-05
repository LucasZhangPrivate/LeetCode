/*Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3*/

/*Runtime: 4 ms, faster than 86.94% of C++ online submissions for Binary Tree Paths.
Memory Usage: 12.3 MB, less than 23.21% of C++ online submissions for Binary Tree Paths.*/

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
    void search(vector<string>& res, TreeNode* root, string cur)
    {
        if (root == nullptr) return;
        cur = cur + "->" + to_string(root->val);
        if (!root->left && !root->right)
        {
            res.push_back(cur.substr(2));
            return;
        }
        search(res, root->left, cur);
        search(res, root->right, cur);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if (root == nullptr) return res;
        string s;
        search(res, root, s);
        return res;

    }
};