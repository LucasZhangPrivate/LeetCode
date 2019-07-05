/*Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
Memory Usage: 8.8 MB, less than 30.32% of C++ online submissions for Pascal's Triangle.*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 0)return res;
        res.push_back(vector<int>({ 1 }));
        for (int i = 2; i <= numRows; ++i)
        {
            res.push_back(vector<int>(i, 0));
            res[i - 1][0] = 1;
            res[i - 1][i - 1] = 1;
            for (int j = 1; j < i - 1; ++j)
            {
                res[i - 1][j] = res[i - 2][j - 1] + res[i - 2][j];
            }
        }
        return res;
    }
};