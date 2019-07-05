/*Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

Note: A leaf is a node with no children.

Example:

Input: [1,2,3]
    1
   / \
  2   3
Output: 25
Explanation:
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.
Therefore, sum = 12 + 13 = 25.
Example 2:

Input: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
Output: 1026
Explanation:
The root-to-leaf path 4->9->5 represents the number 495.
The root-to-leaf path 4->9->1 represents the number 491.
The root-to-leaf path 4->0 represents the number 40.
Therefore, sum = 495 + 491 + 40 = 1026.*/

/*Runtime: 8 ms, faster than 51.50% of C++ online submissions for Sum Root to Leaf Numbers.
Memory Usage: 12.4 MB, less than 50.75% of C++ online submissions for Sum Root to Leaf Numbers.*/

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
    void sum(TreeNode* root, int& res, int temp)
    {
        if (root == nullptr) return;
        temp += root->val;
        if (root->left == nullptr && root->right == nullptr)
        {
            res += temp;
            return;
        }
        sum(root->left, res, temp * 10);
        sum(root->right, res, temp * 10);
    }
    int sumNumbers(TreeNode* root) {
        int res = 0;
        int temp = 0;
        sum(root, res, temp);
        return res;
    }
};