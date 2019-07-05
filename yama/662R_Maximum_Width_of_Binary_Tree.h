/*Given a binary tree, write a function to get the maximum width of the given tree. The width of a tree is the maximum width among all levels. The binary tree has the same structure as a full binary tree, but some nodes are null.

The width of one level is defined as the length between the end-nodes (the leftmost and right most non-null nodes in the level, where the null nodes between the end-nodes are also counted into the length calculation.

Example 1:

Input: 

           1
         /   \
        3     2
       / \     \  
      5   3     9 

Output: 4
Explanation: The maximum width existing in the third level with the length 4 (5,3,null,9).
Example 2:

Input: 

          1
         /  
        3    
       / \       
      5   3     

Output: 2
Explanation: The maximum width existing in the third level with the length 2 (5,3).
Example 3:

Input: 

          1
         / \
        3   2 
       /        
      5      

Output: 2
Explanation: The maximum width existing in the second level with the length 2 (3,2).
Example 4:

Input: 

          1
         / \
        3   2
       /     \  
      5       9 
     /         \
    6           7
Output: 8
Explanation:The maximum width existing in the fourth level with the length 8 (6,null,null,null,null,null,null,7).*/

/*Runtime: 8 ms, faster than 82.48% of C++ online submissions for Maximum Width of Binary Tree.
Memory Usage: 16.6 MB, less than 19.54% of C++ online submissions for Maximum Width of Binary Tree.*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Maximum Width of Binary Tree.
Memory Usage: 16.6 MB, less than 18.58% of C++ online submissions for Maximum Width of Binary Tree.*/

class Solution {
public:
    void help(vector<vector<unsigned int>>& v, unsigned int level, unsigned int index, TreeNode* root)
    {
        if (root == nullptr) return;
        if (v.size() == level)
        {
            v.push_back(vector<unsigned int>({ INT_MAX, 0 }));
        }
        v[level][0] = min(v[level][0], index);
        v[level][1] = max(v[level][1], index);
        help(v, level + 1, index * 2, root->left);
        help(v, level + 1, index * 2 + 1, root->right);

    }
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) return 0;
        vector<vector<unsigned int>> v;
        help(v, 0, 0, root);
        unsigned int res = 0;
        for (const auto& list : v)
        {
            if (list[0] == INT_MAX)
            {
                res = 1;
            }
            else res = max(res, list[1] - list[0] + 1);

        }
        return res;

    }
};