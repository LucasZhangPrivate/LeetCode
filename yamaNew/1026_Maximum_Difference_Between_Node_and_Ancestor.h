/*Given the root of a binary tree, find the maximum value V for which there exists different nodes A and B where V = |A.val - B.val| and A is an ancestor of B.

(A node A is an ancestor of B if either: any child of A is equal to B, or any child of A is an ancestor of B.)

 

Example 1:



Input: [8,3,10,1,6,null,14,null,null,4,7,13]
Output: 7
Explanation: 
We have various ancestor-node differences, some of which are given below :
|8 - 3| = 5
|3 - 7| = 4
|8 - 1| = 7
|10 - 13| = 3
Among all possible differences, the maximum value of 7 is obtained by |8 - 1| = 7.
 

Note:

The number of nodes in the tree is between 2 and 5000.
Each node will have value between 0 and 100000.*/

/*Runtime: 4 ms, faster than 99.06% of C++ online submissions for Maximum Difference Between Node and Ancestor.
Memory Usage: 13.7 MB, less than 40.75% of C++ online submissions for Maximum Difference Between Node and Ancestor.*/

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
    pair<int, int> small(TreeNode* root, int& res)
    {
        if (root->left == nullptr && root->right == nullptr)
        {
            return { root->val, root->val };
        }
        pair<int, int> temp(INT_MAX, INT_MIN);
        if (root->left)
        {
            auto l = small(root->left, res);
            temp.first = min(temp.first, l.first);
            temp.second = max(temp.second, l.second);
        }
        if (root->right)
        {
            auto r = small(root->right, res);
            temp.first = min(temp.first, r.first);
            temp.second = max(temp.second, r.second);
        }
        res = max(abs(root->val - temp.first), res);
        res = max(abs(root->val - temp.second), res);
        temp.first = min(root->val, temp.first);
        temp.second = max(root->val, temp.second);
        return temp;

    }
    int maxAncestorDiff(TreeNode* root) {
        int res = 0;
        small(root, res);
        return res;
    }
};