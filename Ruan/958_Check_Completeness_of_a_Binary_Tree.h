/*Given a binary tree, determine if it is a complete binary tree.

Definition of a complete binary tree from Wikipedia:
In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 

Example 1:



Input: [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
Example 2:



Input: [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.
 
Note:

The tree will have between 1 and 100 nodes.*/

/*Runtime: 8 ms, faster than 98.84% of C++ online submissions for Check Completeness of a Binary Tree.
Memory Usage: 10.1 MB, less than 100.00% of C++ online submissions for Check Completeness of a Binary Tree.*/

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
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> q;
        q.push(root);
        bool end = false;
        while (!q.empty())
        {
            auto i = q.size();
            while (i>0)
            {
                auto node = q.front();
                q.pop();
                if (end && node->left != nullptr)return false;
                if (node->left != nullptr)
                {
                    q.push(node->left);
                }
                else
                {
                    end = true;
                }
                if (end&&node->right != nullptr)return false;
                if (node->right != nullptr)
                {
                    q.push(node->right);
                }
                else
                {
                    end = true;
                }
                i--;
            }

        }
        return true;
    }
};