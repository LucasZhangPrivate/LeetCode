/*Given a non-empty special binary tree consisting of nodes with the non-negative value, where each node in this tree has exactly two or zero sub-node. If the node has two sub-nodes, then this node's value is the smaller value among its two sub-nodes. More formally, the property root.val = min(root.left.val, root.right.val) always holds.

Given such a binary tree, you need to output the second minimum value in the set made of all the nodes' value in the whole tree.

If no such second minimum value exists, output -1 instead.

Example 1:

Input: 
    2
   / \
  2   5
     / \
    5   7

Output: 5
Explanation: The smallest value is 2, the second smallest value is 5.
 

Example 2:

Input: 
    2
   / \
  2   2

Output: -1
Explanation: The smallest value is 2, but there isn't any second smallest value.*/

/*Runtime: 4 ms, faster than 86.53% of C++ online submissions for Second Minimum Node In a Binary Tree.
Memory Usage: 8.8 MB, less than 32.88% of C++ online submissions for Second Minimum Node In a Binary Tree.*/

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
    int help(TreeNode* root, int small)
    {
        if (root == nullptr) return -1;
        if (root->val != small)return root->val;
        else {
            auto l = help(root->left, small);
            auto r = help(root->right, small);
            if (l == -1)return r;
            else if (r == -1)return l;
            else return min(l, r);
        }
    }
    int findSecondMinimumValue(TreeNode* root) {
        if (root == nullptr || root->left == nullptr) return -1;
        return help(root, root->val);
    }
};
