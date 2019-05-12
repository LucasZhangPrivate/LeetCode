/*Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

Example 1:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
Given tree t:
   4 
  / \
 1   2
Return true, because t has the same structure and node values with a subtree of s.
Example 2:
Given tree s:

     3
    / \
   4   5
  / \
 1   2
    /
   0
Given tree t:
   4
  / \
 1   2*/

/*Runtime: 28 ms, faster than 98.45% of C++ online submissions for Subtree of Another Tree.
Memory Usage: 21.3 MB, less than 96.14% of C++ online submissions for Subtree of Another Tree.*/

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
    bool isSame(TreeNode* l, TreeNode* r)
    {
        if (l == nullptr && r == nullptr)return true;
        else if (l == nullptr || r == nullptr) return false;
        else return(l->val == r->val && isSame(l->left, r->left) &&
            isSame(l->right, r->right));
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        if (isSame(s, t))return true;
        if (s == nullptr)return false;
        return s->left&&isSubtree(s->left, t) || s->right&&isSubtree(s->right, t);
    }
};