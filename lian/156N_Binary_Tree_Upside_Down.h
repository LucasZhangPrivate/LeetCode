/*Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.

Example:

Input: [1,2,3,4,5]

    1
   / \
  2   3
 / \
4   5

Output: return the root of the binary tree [4,5,2,#,#,3,1]

   4
  / \
 5   2
    / \
   3   1  
Clarification:

Confused what [4,5,2,#,#,3,1] means? Read more below on how binary tree is serialized on OJ.

The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as [1,2,3,#,#,4,#,#,5].*/

/*Runtime: 4 ms, faster than 88.62% of C++ online submissions for Binary Tree Upside Down.
Memory Usage: 9.1 MB, less than 5.12% of C++ online submissions for Binary Tree Upside Down.*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//„eÈËµÄ´ð°¸
class Solution {
public:
    TreeNode * upsideDownBinaryTree(TreeNode* root) {
        if (!root) return root;
        return helper(root, nullptr, nullptr);
    }
    TreeNode* helper(TreeNode* root, TreeNode* node_l, TreeNode* node_r) {
        if (!root) return root;
        TreeNode * curr = new TreeNode(root->val);
        curr->left = node_l;
        curr->right = node_r;
        if (!root->left && !root->right) {
            root->right = node_r;
            root->left = node_l;
            return root;
        }
        else
            return helper(root->left, root->right, curr);
    }
};