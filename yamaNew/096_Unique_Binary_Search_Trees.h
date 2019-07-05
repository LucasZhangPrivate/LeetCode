/*Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?

Example:

Input: 3
Output: 5
Explanation:
Given n = 3, there are a total of 5 unique BST's:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3*/

/*Runtime: 4 ms, faster than 72.19% of C++ online submissions for Unique Binary Search Trees.
Memory Usage: 8.5 MB, less than 9.51% of C++ online submissions for Unique Binary Search Trees.*/

class Solution {
public:
    unordered_map<int, int> mp;
    int num(int i, int j)
    {
        if (i>j)return 0;
        if (mp.count(j - i + 1))return mp[j - i + 1];
        int temp = 0;
        for (int x = i; x <= j; ++x)
        {
            auto a = num(i, x - 1);
            auto b = num(x + 1, j);
            auto l = a == 0 ? 1 : a;
            auto r = b == 0 ? 1 : b;
            temp += (l*r);
        }
        mp[j - i + 1] = temp;
        return temp;
    }
    int numTrees(int n) {
        mp.insert({ 1,1 });
        return num(1, n);
    }
};

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Unique Binary Search Trees.
Memory Usage: 8.2 MB, less than 79.69% of C++ online submissions for Unique Binary Search Trees.*/

class Solution {
public:
    int numTrees(int n) {
        if (n == 1)return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i)
        {
            for (int j = 0; j<i; ++j) //j代表左边的孩子的节点个数
            {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};