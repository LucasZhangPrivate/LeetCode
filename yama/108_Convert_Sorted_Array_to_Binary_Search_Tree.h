/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

Example:

Given the sorted array: [-10,-3,0,5,9],

One possible answer is: [0,-3,9,-10,null,5], which represents the following height balanced BST:

      0
     / \
   -3   9
   /   /
 -10  5*/

/*Runtime: 12 ms, faster than 99.04% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
Memory Usage: 21.1 MB, less than 38.77% of C++ online submissions for Convert Sorted Array to Binary Search Tree.*/

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
    TreeNode * sort(vector<int>& nums, int i, int j)
    {
        if (i>j)return nullptr;
        if (i == j)return new TreeNode(nums[i]);
        int mid = (i + j) / 2;
        TreeNode* cur = new TreeNode(nums[mid]);
        cur->left = sort(nums, i, mid - 1);
        cur->right = sort(nums, mid + 1, j);
        return cur;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sort(nums, 0, nums.size() - 1);
    }
};