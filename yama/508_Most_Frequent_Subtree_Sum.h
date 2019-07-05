/*Given the root of a tree, you are asked to find the most frequent subtree sum. The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself). So what is the most frequent subtree sum value? If there is a tie, return all the values with the highest frequency in any order.

Examples 1
Input:

  5
 /  \
2   -3
return [2, -3, 4], since all the values happen only once, return all of them in any order.
Examples 2
Input:

  5
 /  \
2   -5
return [2], since 2 happens twice, however -5 only occur once.
Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.*/

/*Runtime: 20 ms, faster than 91.95% of C++ online submissions for Most Frequent Subtree Sum.
Memory Usage: 23.4 MB, less than 79.12% of C++ online submissions for Most Frequent Subtree Sum.*/

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
    int sub(TreeNode* root, unordered_map<int, int>& mp)
    {
        if (root == nullptr) return 0;
        int l = sub(root->left, mp);
        int r = sub(root->right, mp);
        int sum = root->val + l + r;
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int>mp;
        sub(root, mp);
        int most = 0;
        vector<int> res;
        for (const auto& p : mp)
        {
            if (p.second>most)
            {
                most = p.second;
                res.clear();
                res.push_back(p.first);
            }
            else if (p.second == most)res.push_back(p.first);
        }
        return res;
    }
};