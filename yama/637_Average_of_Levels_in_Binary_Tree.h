/*Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
Example 1:
Input:
    3
   / \
  9  20
    /  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
Note:
The range of node's value is in the range of 32-bit signed integer.*/

/*Runtime: 12 ms, faster than 99.09% of C++ online submissions for Average of Levels in Binary Tree.
Memory Usage: 21.7 MB, less than 62.69% of C++ online submissions for Average of Levels in Binary Tree.*/

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
    void help(vector<int>& n, vector<double>& res, TreeNode* root, int level)
    {
        if (root == nullptr) return;
        if (level == n.size())
        {
            n.push_back(1);
            res.push_back(root->val);
        }
        else
        {
            res[level] = (res[level] * n[level] + root->val) / (n[level] + 1);
            n[level]++;
        }
        help(n, res, root->left, level + 1);
        help(n, res, root->right, level + 1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        vector<int> n;
        vector<double> res;
        help(n, res, root, 0);
        return res;
    }
};