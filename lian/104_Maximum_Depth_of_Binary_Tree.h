/*Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Note: A leaf is a node with no children.

Example:

Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
return its depth = 3.*/

/*Runtime: 8 ms, faster than 96.13% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 19.5 MB, less than 47.63% of C++ online submissions for Maximum Depth of Binary Tree.*/

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
    void help(TreeNode* root, int& res, int level)
    {
        if (root == nullptr) return;
        res = max(res, level);
        help(root->left, res, level + 1);
        help(root->right, res, level + 1);
    }

    int maxDepth(TreeNode* root) {
        int res = 0;
        help(root, res, 1);
        return res;
    }
};

/*Runtime: 16 ms, faster than 76.47% of C++ online submissions for Maximum Depth of Binary Tree.
Memory Usage: 19.7 MB, less than 6.92% of C++ online submissions for Maximum Depth of Binary Tree.*/

class Solution {
public:

    int maxDepth(TreeNode *root)
    {
        if (root == nullptr) return 0;
        return  max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};
