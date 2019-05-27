/*Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6*/

/*Runtime: 8 ms, faster than 92.28% of C++ online submissions for Flatten Binary Tree to Linked List.
Memory Usage: 9.8 MB, less than 67.77% of C++ online submissions for Flatten Binary Tree to Linked List.*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//新用的方法
class Solution {
public:
    TreeNode * help(TreeNode* root)
    {
        if (root == nullptr) return root;
        auto l = help(root->left);
        auto r = help(root->right);
        auto keep = root;
        if (l != nullptr)
        {
            root->right = l;
            while (root->right)root = root->right;
        }
        root->right = r;
        root = keep;
        root->left = nullptr;
        return root;
    }


    void flatten(TreeNode* root) {
        help(root);
    }
};


//之前比较巧妙的方法
class Solution {
public:
    void flatten(TreeNode* root)
    {
        while (root)
        {
            if (root->left == nullptr)root = root->right;
            else
            {
                TreeNode *temp = root->left;
                while (temp->right)
                    temp = temp->right;
                temp->right = root->right;

                root->right = root->left;
                root->left = nullptr;
                root = root->right;
            }
        }
    }
};