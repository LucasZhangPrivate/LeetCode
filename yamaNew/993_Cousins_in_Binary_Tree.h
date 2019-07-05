/*In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.*/

/*Runtime: 4 ms, faster than 91.33% of C++ online submissions for Cousins in Binary Tree.
Memory Usage: 11.2 MB, less than 75.08% of C++ online submissions for Cousins in Binary Tree.*/

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
    void check(TreeNode* root, int x, int y, int& levelx, int& levely, int curlevel, bool& nocopare)
    {
        if (root == nullptr || levelx != -1 && levely != -1)return;
        if (root->left && root->right)
        {
            if (root->left->val == x && root->right->val == y || root->right->val == x && root->left->val == y)
            {
                nocopare = false;
                return;
            }
        }
        curlevel++;
        if (root->val == x)levelx = curlevel;
        if (root->val == y)levely = curlevel;
        check(root->left, x, y, levelx, levely, curlevel, nocopare);
        check(root->right, x, y, levelx, levely, curlevel, nocopare);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        bool nocopare = true;
        int levelx = -1;
        int levely = -1;
        check(root, x, y, levelx, levely, 0, nocopare);
        if (nocopare && levelx == levely)return true;
        else return false;
    }
};



class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        bool findOne = false;
        while (!q.empty()) {
            int n = q.size();
            while (n-->0)
            {
                auto node = q.front();
                q.pop();
                if (node == NULL) continue;
                if (node->left != NULL && node->right != NULL) {
                    if (node->left->val == x && node->right->val == y
                        || node->left->val == y && node->right->val == x)return false;
                }
                if (node->val == x || node->val == y) {
                    if (findOne)return true;
                    else findOne = true;
                }
                q.push(node->left);
                q.push(node->right);

            }
            if (findOne)return false;
        }
        return false;
    }
};