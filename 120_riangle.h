/*Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:

Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.*/

/*Runtime: 8 ms, faster than 92.88% of C++ online submissions for Triangle.
Memory Usage: 9.8 MB, less than 77.58% of C++ online submissions for Triangle.*/


//最近一次的输入
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> help(triangle.back().size(), INT_MAX);
        if (triangle.size() == 1)return triangle[0][0];
        if (triangle.empty())return 0;
        help[0] = triangle[0][0];
        for (int i = 1; i<triangle.size(); ++i)
        {
            for (int j = triangle[i].size() - 1; j >= 0; --j)
            {
                if (j == triangle[i].size() - 1)
                {
                    help[j] = triangle[i][j] + help[j - 1];
                }
                else if (j == 0)
                {
                    help[j] = triangle[i][j] + help[j];
                }
                else
                {
                    help[j] = min(help[j], help[j - 1]) + triangle[i][j];
                }
            }
        }
        int res = INT_MAX;
        for (const auto& h : help)
        {
            res = min(res, h);
        }
        return res;
    }
};


//历史记录里的，这个更简洁，更容易理解
class Solution {
public:
    int minimumTotal(vector<vector<int> > &triangle)
    {
        int row = triangle.size() - 1;
        //    int sum=0;
        for (int i = row - 1; i >= 0; i--)
        {
            for (int j = 0; j<triangle[i].size(); j++)
            {
                triangle[i][j] += min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};