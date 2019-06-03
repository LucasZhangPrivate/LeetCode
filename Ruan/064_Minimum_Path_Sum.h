/*Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1¡ú3¡ú1¡ú1¡ú1 minimizes the sum.*/

/*Runtime: 12 ms, faster than 88.50% of C++ online submissions for Minimum Path Sum.
Memory Usage: 10.6 MB, less than 82.43% of C++ online submissions for Minimum Path Sum.*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        for (int i = 0; i< grid.size(); ++i)
        {
            for (int j = 0; j< grid[i].size(); ++j)
            {
                if (i == 0 && j == 0)continue;
                else if (i == 0)
                {
                    grid[i][j] = grid[i][j] + grid[i][j - 1];
                }
                else if (j == 0)
                {
                    grid[i][j] = grid[i][j] + grid[i - 1][j];
                }
                else
                {
                    grid[i][j] = min(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
                }
            }
        }
        return grid.back().back();
    }
};