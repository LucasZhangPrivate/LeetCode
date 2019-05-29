/*Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

Example:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]*/

/*Runtime: 480 ms, faster than 15.30% of C++ online submissions for Combinations.
Memory Usage: 167.1 MB, less than 8.29% of C++ online submissions for Combinations.*/

class Solution {
public:
    void help(vector<vector<int>>& res, vector<int> temp, int n, int k, int start)
    {
        if (temp.size() == k)
        {
            res.push_back(temp);
            return;
        }
        if (start>n)return;
        for (int i = start; i <= n; ++i)
        {
            temp.push_back(i);
            help(res, temp, n, k, i + 1);
            temp.pop_back();
        }

    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        if (k>n || n == 0)return res;
        vector<int> temp;
        help(res, temp, n, k, 1);
        return res;
    }
};