/*You are given a binary tree in which each node contains an integer value.

Find the number of paths that sum to a given value.

The path does not need to start or end at the root or a leaf, but it must go downwards (traveling only from parent nodes to child nodes).

The tree has no more than 1,000 nodes and the values are in the range -1,000,000 to 1,000,000.

Example:

root = [10,5,-3,3,2,null,11,3,-2,null,1], sum = 8

      10
     /  \
    5   -3
   / \    \
  3   2   11
 / \   \
3  -2   1

Return 3. The paths that sum to 8 are:

1.  5 -> 3
2.  5 -> 2 -> 1
3. -3 -> 11*/

/*Runtime: 16 ms, faster than 95.30% of C++ online submissions for Path Sum III.
Memory Usage: 14.7 MB, less than 67.94% of C++ online submissions for Path Sum III.*/

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
    int pathSum(TreeNode* root, int sum) {
        if (root == nullptr) return 0;
        return pathSum(root->left, sum) + pathSum(root->right, sum) + cal(root, sum);
    }
    int cal(TreeNode* root, int sum)
    {
        if (root == nullptr) return 0;
        else if (root->val == sum)
        {
            return cal(root->left, 0) + cal(root->right, 0) + 1;
        }
        int temp = sum - root->val;
        return cal(root->left, temp) + cal(root->right, temp);
    }

};