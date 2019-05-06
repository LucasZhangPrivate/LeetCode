//不是自己做的，值得藉鑒的是用map儲存父節點信息

/*We are given a binary tree (with root node root), a target node, and an integer value K.

Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.

 

Example 1:

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2

Output: [7,4,1]

Explanation: 
The nodes that are a distance 2 from the target node (with value 5)
have values 7, 4, and 1.



Note that the inputs "root" and "target" are actually TreeNodes.
The descriptions of the inputs above are just serializations of these objects.*/

/*Runtime: 16 ms, faster than 49.59% of C++ online submissions for All Nodes Distance K in Binary Tree.
Memory Usage: 17.7 MB, less than 48.61% of C++ online submissions for All Nodes Distance K in Binary Tree.*/

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
    void storePare(unordered_map<TreeNode*, TreeNode*>&pare, TreeNode* node)
    {
        if (node->left)
        {
            pare[node->left] = node;
            storePare(pare, node->left);
        }
        if (node->right)
        {
            pare[node->right] = node;
            storePare(pare, node->right);
        }

    }
    void find(vector<int>&res, TreeNode* target, int K, unordered_map<TreeNode*, TreeNode*>& pare)
    {
        if (target->val == -1)return;
        if (K == 0)
        {
            res.push_back(target->val);
            return;
        }
        target->val = -1;
        if (pare.count(target))
        {
            find(res, pare[target], K - 1, pare);
        }
        if (target->left)
        {
            find(res, target->left, K - 1, pare);
        }
        if (target->right)
        {
            find(res, target->right, K - 1, pare);
        }

    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> res;
        unordered_map<TreeNode*, TreeNode*> pare;
        storePare(pare, root);
        find(res, target, K, pare);
        return res;
    }
};