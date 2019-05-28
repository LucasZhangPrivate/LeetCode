/*Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?*/

/*Runtime: 4 ms, faster than 93.02% of C++ online submissions for Binary Tree Inorder Traversal.
Memory Usage: 9.4 MB, less than 23.50% of C++ online submissions for Binary Tree Inorder Traversal.*/

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
    void tran(TreeNode* root, vector<int>& res)
    {
        if (root == nullptr)return;
        tran(root->left, res);
        res.push_back(root->val);
        tran(root->right, res);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        tran(root, res);
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode *> s;
        while (!s.empty() || root != nullptr)
        {
            if (root != nullptr)
            {
                s.push(root);
                root = root->left;
            }
            else
            {
                result.push_back(s.top()->val);
                root = s.top()->right;
                s.pop();
            }
        }
        return result;
    }
};