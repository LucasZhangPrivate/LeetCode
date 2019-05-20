/*Given a binary search tree and a node in it, find the in-order successor of that node in the BST.

The successor of a node p is the node with the smallest key greater than p.val.

 

Example 1:


Input: root = [2,1,3], p = 1
Output: 2
Explanation: 1's in-order successor node is 2. Note that both p and the return value is of TreeNode type.
Example 2:


Input: root = [5,3,6,2,4,null,null,1], p = 6
Output: null
Explanation: There is no in-order successor of the current node, so the answer is null.*/

/*Runtime: 32 ms, faster than 98.25% of C++ online submissions for Inorder Successor in BST.
Memory Usage: 25.5 MB, less than 12.67% of C++ online submissions for Inorder Successor in BST.*/

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
    TreeNode * next(TreeNode* root)
    {
        if (root == nullptr) return root;
        while (root->left)root = root->left;
        return root;
    }
    TreeNode* find(TreeNode* root, int val, bool& f)
    {
        if (root->left)
        {
            auto l = find(root->left, val, f);
            if (f)
            {
                return l == nullptr ? root : l;
            }
        }
        if (root->val == val)
        {
            f = true;
            return next(root->right);
        }
        if (root->right)
        {
            auto r = find(root->right, val, f);
            return r;
        }
        return nullptr;

    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        bool check = false;
        return find(root, p->val, check);
    }
};