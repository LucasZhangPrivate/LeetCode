/*Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.

Note:

Given target value is a floating point.
You are guaranteed to have only one unique value in the BST that is closest to the target.
Example:

Input: root = [4,2,5,1,3], target = 3.714286

    4
   / \
  2   5
 / \
1   3

Output: 4*/
/*Runtime: 16 ms, faster than 76.73% of C++ online submissions for Closest Binary Search Tree Value.
Memory Usage: 20.7 MB, less than 5.46% of C++ online submissions for Closest Binary Search Tree Value.*/

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
    int closestValue(TreeNode* root, double target) {
        int l = root->val;
        int r = root->val;
        if (!root->left && !root->right) return root->val;
        if (root->left)l = closestValue(root->left, target);
        if (root->right) r = closestValue(root->right, target);

        auto m = min(abs(root->val - target), min(abs(l - target), abs(r - target)));
        if (m == abs(root->val - target))return root->val;
        else if (m == abs(l - target))return l;
        else return r;
    }
};

/*Runtime: 24 ms, faster than 15.43% of C++ online submissions for Closest Binary Search Tree Value.
Memory Usage: 20.5 MB, less than 67.22% of C++ online submissions for Closest Binary Search Tree Value.*/

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
    int closestValue(TreeNode* root, double target) {
        int res = root->val;
        double diff = abs(root->val - target);
        while (root)
        {
            if (root->val == target)return root->val;
            if (root->left && abs(root->left->val - target) < diff)
            {
                res = root->left->val;
                diff = abs(root->left->val - target);
            }
            if (root->right && abs(root->right->val - target) < diff)
            {
                res = root->right->val;
                diff = abs(root->right->val - target);
            }
            if (target > root->val)root = root->right;
            else root = root->left;
        }
        return res;
    }
};