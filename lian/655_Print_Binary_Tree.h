/*Print a binary tree in an m*n 2D string array following these rules:

The row number m should be equal to the height of the given binary tree.
The column number n should always be an odd number.
The root node's value (in string format) should be put in the exactly middle of the first row it can be put. The column and the row where the root node belongs will separate the rest space into two parts (left-bottom part and right-bottom part). You should print the left subtree in the left-bottom part and print the right subtree in the right-bottom part. The left-bottom part and the right-bottom part should have the same size. Even if one subtree is none while the other is not, you don't need to print anything for the none subtree but still need to leave the space as large as that for the other subtree. However, if two subtrees are none, then you don't need to leave space for both of them.
Each unused space should contain an empty string "".
Print the subtrees following the same rules.
Example 1:
Input:
     1
    /
   2
Output:
[["", "1", ""],
 ["2", "", ""]]
Example 2:
Input:
     1
    / \
   2   3
    \
     4
Output:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]
Example 3:
Input:
      1
     / \
    2   5
   / 
  3 
 / 
4 
Output:

[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]*/

/*Runtime: 4 ms, faster than 92.64% of C++ online submissions for Print Binary Tree.
Memory Usage: 9.6 MB, less than 74.19% of C++ online submissions for Print Binary Tree.*/

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
    void maxlen(TreeNode* root, int level, int& max, int& len)
    {
        if (root == nullptr)return;
        if (level > max)
        {
            max = level;
            len *= 2;
        }
        maxlen(root->left, level + 1, max, len);
        maxlen(root->right, level + 1, max, len);

    }

    void help(vector<vector<string>>& res, TreeNode* root, int l, int r, int level)
    {
        if (root == nullptr)return;
        int mid = (l + r) / 2;
        res[level][mid] = to_string(root->val);
        help(res, root->left, l, mid - 1, level + 1);
        help(res, root->right, mid + 1, r, level + 1);
    }

    vector<vector<string>> printTree(TreeNode* root) {
        vector<vector<string>> res;
        if (root == nullptr)return res;
        int len = 2;
        int max = 1;
        maxlen(root, 1, max, len);
        len--;
        vector<string> line(len, "");
        while (max-->0)res.push_back(line);
        help(res, root, 0, len - 1, 0);
        return res;
    }
};