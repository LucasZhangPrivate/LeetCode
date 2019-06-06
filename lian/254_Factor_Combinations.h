/*Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note:

You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Example 1:

Input: 1
Output: []
Example 2:

Input: 37
Output:[]
Example 3:

Input: 12
Output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
Example 4:

Input: 32
Output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]*/

/*Runtime: 216 ms, faster than 5.10% of C++ online submissions for Factor Combinations.
Memory Usage: 9.3 MB, less than 18.33% of C++ online submissions for Factor Combinations.*/

class Solution {
public:
    void help(vector<vector<int>>& res, vector<int> temp, int n, int cur)
    {
        for (int i = cur; i <= n; ++i)
        {
            if (n%i == 0 && n / i == 1 && !temp.empty())
            {
                temp.push_back(i);
                res.push_back(temp);
                return;
            }
            else if (n%i == 0)
            {
                temp.push_back(i);
                help(res, temp, n / i, i);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> temp;
        help(res, temp, n, 2);
        return res;

    }
};