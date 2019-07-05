/*The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

Example 1:

Input: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

Output: 7 
Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
Example 2:

Input: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

Output: 9
Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.*/

/*Runtime: 24 ms, faster than 57.78% of C++ online submissions for House Robber III.
Memory Usage: 23.8 MB, less than 28.99% of C++ online submissions for House Robber III.*/

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
    unordered_map<TreeNode*, int> mp;
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        if (mp.count(root))return mp[root];
        int child = 0;
        int grandChild = 0;
        child = rob(root->left);
        child += rob(root->right);
        if (root->left)
        {
            grandChild = rob(root->left->left);
            grandChild += rob(root->left->right);
        }
        if (root->right)
        {
            grandChild += rob(root->right->left);
            grandChild += rob(root->right->right);
        }
        mp[root] = max(root->val + grandChild, child);
        return mp[root];
    }
};