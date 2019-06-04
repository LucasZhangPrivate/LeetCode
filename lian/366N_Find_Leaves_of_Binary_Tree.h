/*Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.

 

Example:

Input: [1,2,3,4,5]
  
          1
         / \
        2   3
       / \     
      4   5    

Output: [[4,5,3],[2],[1]]
 

Explanation:

1. Removing the leaves [4,5,3] would result in this tree:

          1
         / 
        2          
 

2. Now removing the leaf [2] would result in this tree:

          1          
 

3. Now removing the leaf [1] would result in the empty tree:

          []         */

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Leaves of Binary Tree.
Memory Usage: 9.5 MB, less than 79.52% of C++ online submissions for Find Leaves of Binary Tree.*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//总想着一次性递归完成删除，这个算法给了启发，循环删除，层层推进
class Solution {
public:
    bool remove(vector<int>& del, TreeNode* root)
    {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr)
        {
            del.push_back(root->val);
            return true;
        }
        root->left = remove(del, root->left) ? nullptr : root->left;
        root->right = remove(del, root->right) ? nullptr : root->right;
        return false;
    }


    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) return res;
        while (root->left || root->right)
        {
            vector<int> temp;
            remove(temp, root);
            res.push_back(temp);
        }
        res.push_back({ root->val });
        return res;
    }
};



class Solution {
public:
    int f(TreeNode* root, vector<vector<int>>& result) {
        if (root->left == nullptr&&root->right == nullptr) {
            if (result.empty()) {
                result.push_back({});
            }
            result[0].push_back(root->val);
            return 1;
        }
        auto l = 0, r = 0;
        if (root->left) {
            l = f(root->left, result);
        }
        if (root->right) {
            r = f(root->right, result);
        }
        auto level = max(l, r);
        while (result.size()<level + 1) {
            result.push_back({});
        }
        result[level].push_back(root->val);
        return level + 1;
    }


    vector<vector<int>> findLeaves(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> result;
        f(root, result);
        return result;

    }
};