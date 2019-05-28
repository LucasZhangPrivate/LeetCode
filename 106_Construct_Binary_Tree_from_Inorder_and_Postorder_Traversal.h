/*Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.

For example, given

inorder = [9,3,15,20,7]
postorder = [9,15,7,20,3]
Return the following binary tree:

    3
   / \
  9  20
    /  \
   15   7*/

/*Runtime: 64 ms, faster than 9.20% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
Memory Usage: 91.2 MB, less than 7.19% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.*/

/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//最新的AC，但是效率有点低
class Solution {
public:
    TreeNode * buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty())return nullptr;
        int r = postorder.back();
        postorder.pop_back();
        TreeNode* root = new TreeNode(r);
        vector<int> toLeft;
        vector<int> toRight;
        bool mark = false;
        for (const auto& n : inorder)
        {
            if (n == r)
            {
                mark = true;
            }
            else if (mark == false)
            {
                toLeft.push_back(n);
            }
            else
            {
                toRight.push_back(n);
            }
        }


        TreeNode* right = buildTree(toRight, postorder);
        TreeNode* left = buildTree(toLeft, postorder);
        root->right = right;
        root->left = left;
        return root;
    }
};




/*Runtime: 12 ms, faster than 98.85% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.
Memory Usage: 14.4 MB, less than 98.02% of C++ online submissions for Construct Binary Tree from Inorder and Postorder Traversal.*/

//用栈做的，效率高一些
class Solution {
public:
    TreeNode * buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)return nullptr;
        TreeNode *root, *p;
        stack<TreeNode *>s;
        root = new TreeNode(postorder.back());
        s.push(root);
        postorder.pop_back();

        while (true)
        {
            if (inorder.back() == s.top()->val)
            {
                p = s.top();
                s.pop();
                inorder.pop_back();
                if (inorder.size() == 0)break;
                if (s.size()>0 && s.top()->val == inorder.back())
                    continue;
                p->left = new TreeNode(postorder.back());
                postorder.pop_back();
                s.push(p->left);
            }
            else
            {
                p = new TreeNode(postorder.back());
                s.top()->right = p;
                postorder.pop_back();
                s.push(p);
            }
        }
        return root;
    }
};