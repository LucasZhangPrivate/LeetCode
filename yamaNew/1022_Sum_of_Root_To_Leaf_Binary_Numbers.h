/*Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:



Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22
 

Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.*/

/*Runtime: 4 ms, faster than 98.75% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
Memory Usage: 17.1 MB, less than 55.09% of C++ online submissions for Sum of Root To Leaf Binary Numbers.*/

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
    void search(TreeNode* root, int& res, int cur)
    {
        if (root == nullptr) return;
        cur <<= 1;
        cur |= root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            res += cur;
            return;
        }

        search(root->left, res, cur);
        search(root->right, res, cur);
    }
    int sumRootToLeaf(TreeNode* root) {
        int res = 0;
        if (root == nullptr) return res;
        search(root, res, 0);
        return res;
    }
};