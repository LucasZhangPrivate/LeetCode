/*Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

Example:
Given a binary tree 
          1
         / \
        2   3
       / \     
      4   5    
Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].

Note: The length of path between two nodes is represented by the number of edges between them.*/

/*Runtime: 8 ms, faster than 99.70% of C++ online submissions for Diameter of Binary Tree.
Memory Usage: 20.1 MB, less than 94.29% of C++ online submissions for Diameter of Binary Tree.*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//注意读题，长度并不是最长链中的节点个数，而是边的长度，导致了开始res = max(res, l + r + 1);
class Solution {
public:
    int longest(TreeNode* root, int& res)
    {
        if (root == nullptr)return 0;
        auto l = longest(root->left, res);
        auto r = longest(root->right, res);
        res = max(res, l + r);
        return max(l, r) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        longest(root, res);
        return res;
    }
};