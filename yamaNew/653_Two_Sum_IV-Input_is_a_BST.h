/*Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
 

Example 2:

Input: 
    5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False*/

/*Runtime: 48 ms, faster than 58.56% of C++ online submissions for Two Sum IV - Input is a BST.
Memory Usage: 26.2 MB, less than 50.11% of C++ online submissions for Two Sum IV - Input is a BST.*/

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
    bool help(unordered_set<int>& st, TreeNode* root, int k)
    {
        if (root == nullptr) return false;
        if (st.count(k - root->val))return true;
        st.insert(root->val);
        return help(st, root->left, k) || help(st, root->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> st;
        return help(st, root, k);
    }
};