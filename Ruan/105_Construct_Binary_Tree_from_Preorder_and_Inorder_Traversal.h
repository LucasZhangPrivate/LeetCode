/*Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

preorder = [3,9,20,15,7]
inorder = [9,3,15,20,7]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7*/

/*Runtime: 68 ms, faster than 9.71% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.
Memory Usage: 92.2 MB, less than 6.79% of C++ online submissions for Construct Binary Tree from Preorder and Inorder Traversal.*/

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
    TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())return nullptr;
        int ro = preorder[0];
        TreeNode* root = new TreeNode(ro);
        preorder.erase(preorder.begin());

        vector<int> toLeft;
        vector<int> toRight;
        bool mark = false;
        for (const auto& c : inorder)
        {
            if (c == ro)mark = true;
            else if (mark == false)toLeft.push_back(c);
            else toRight.push_back(c);
        }
        auto l = buildTree(preorder, toLeft);
        auto r = buildTree(preorder, toRight);
        root->left = l;
        root->right = r;
        return root;
    }
};