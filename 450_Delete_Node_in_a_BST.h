/*Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

    5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

    5
   / \
  2   6
   \   \
    4   7*/

/*untime: 32 ms, faster than 98.54% of C++ online submissions for Delete Node in a BST.
Memory Usage: 12.9 MB, less than 100.00% of C++ online submissions for Delete Node in a BST.*/

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
    TreeNode * deleteNode(TreeNode* root, int key) {
        if (root == nullptr)return root;
        if (root->val == key)
        {
            if (root->left == nullptr)return root->right;
            else if (root->right == nullptr) return root->left;
            else
            {
                auto node = root->right;
                while (node->left)node = node->left;
                node->left = root->left;
                return root->right;
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};