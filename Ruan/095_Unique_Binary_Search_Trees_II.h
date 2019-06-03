/*Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.

Example:

Input: 3
Output:
[
  [1,null,3,2],
  [3,2,null,1],
  [3,1,null,null,2],
  [2,1,3],
  [1,null,2,null,3]
]
Explanation:
The above output corresponds to the 5 unique BST's shown below:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3*/

/*Runtime: 20 ms, faster than 87.52% of C++ online submissions for Unique Binary Search Trees II.
Memory Usage: 16.6 MB, less than 69.14% of C++ online submissions for Unique Binary Search Trees II.*/

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
    vector<TreeNode*> gen(int min, int max)
    {
        vector<TreeNode*> res;
        if (max<min)res.push_back(nullptr);
        else if (max == min)res.push_back(new TreeNode(max));
        else
        {
            for (int i = min; i <= max; ++i)
            {
                vector<TreeNode *> l = gen(min, i - 1);
                vector<TreeNode *> r = gen(i + 1, max);
                for (const auto& ll : l)
                {
                    for (const auto& rr : r)
                    {
                        TreeNode* root = new TreeNode(i);
                        root->left = ll;
                        root->right = rr;
                        res.push_back(root);
                    }
                }
            }
        }
        return res;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        if (n == 0) return res;
        return gen(1, n);
    }
};