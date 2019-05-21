/*Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note: 
You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.

Example 1:

Input: root = [3,1,4,null,2], k = 1
   3
  / \
 1   4
  \
   2
Output: 1
Example 2:

Input: root = [5,3,6,2,4,null,null,1], k = 3
       5
      / \
     3   6
    / \
   2   4
  /
 1
Output: 3
Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?*/

/*Runtime: 16 ms, faster than 99.64% of C++ online submissions for Kth Smallest Element in a BST.
Memory Usage: 21.8 MB, less than 20.14% of C++ online submissions for Kth Smallest Element in a BST.*/

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
    int find(TreeNode* root, int& k)
    {
        if (root)
        {
            int res = find(root->left, k);
            if (k == 0)return res;
            if (--k == 0)return root->val;
            return find(root->right, k);
        }
        return 0;
    }
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
};


class Solution {   // do not use binary tree property
public:
    int kthSmallest(TreeNode* root, int k)
    {
        priority_queue<int> q;
        dfs(q, root, k);
        return q.top();
    }
    void dfs(priority_queue<int> &q, TreeNode *root, int k)
    {
        if (root == nullptr)return;
        q.push(root->val);
        if (q.size() > k)q.pop();
        dfs(q, root->left, k);
        dfs(q, root->right, k);
    }
};