/*Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

Note:

All numbers will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: k = 3, n = 7
Output: [[1,2,4]]
Example 2:

Input: k = 3, n = 9
Output: [[1,2,6], [1,3,5], [2,3,4]]*/

/*Runtime: 4 ms, faster than 94.55% of C++ online submissions for Combination Sum III.
Memory Usage: 8.9 MB, less than 26.38% of C++ online submissions for Combination Sum III.*/

class Solution {
public:
    void find(vector<vector<int>>& res, vector<int> cur, int k, int n, int sum)
    {
        if (cur.size() == k)
        {
            if (n == sum)
            {
                res.push_back(cur);
            }
            return;
        }
        int i = cur.empty() ? 1 : cur.back() + 1;
        for (; i <= 9; ++i)
        {
            if (sum + i > n)return;
            sum += i;
            cur.push_back(i);
            find(res, cur, k, n, sum);
            cur.pop_back();
            sum -= i;
        }

    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        int sum = 0;
        find(res, temp, k, n, sum);
        return res;
    }
};