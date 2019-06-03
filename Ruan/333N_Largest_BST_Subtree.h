/*Given a binary tree, find the largest subtree which is a Binary Search Tree (BST), where largest means subtree with largest number of nodes in it.

Note:
A subtree must include all of its descendants.

Example:

Input: [10,5,15,1,8,null,7]

   10 
   / \ 
  5  15 
 / \   \ 
1   8   7

Output: 3
Explanation: The Largest BST Subtree in this case is the highlighted one.
             The return value is the subtree's size, which is 3.
Follow up:
Can you figure out ways to solve it with O(n) time complexity?*/

/*Runtime: 24 ms, faster than 54.36% of C++ online submissions for Largest BST Subtree.
Memory Usage: 28.9 MB, less than 16.17% of C++ online submissions for Largest BST Subtree.*/


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
    int largestBSTSubtree(TreeNode* root) {
        auto res = help(root);
        return res[2];
    }

    vector<int> help(TreeNode* root)
    {
        if (!root)return { INT_MAX, INT_MIN, 0 };
        auto l = help(root->left);
        auto r = help(root->right);
        if (l[1]<root->val && r[0]>root->val)
        {
            return { min(l[0], root->val), max(r[1], root->val), l[2] + r[2] + 1 };
        }
        return { INT_MIN, INT_MAX, max(l[2], r[2]) };
    }
};