/*In a 2 dimensional array grid, each value grid[i][j] represents the height of a building located there. We are allowed to increase the height of any number of buildings, by any amount (the amounts can be different for different buildings). Height 0 is considered to be a building as well. 

At the end, the "skyline" when viewed from all four directions of the grid, i.e. top, bottom, left, and right, must be the same as the skyline of the original grid. A city's skyline is the outer contour of the rectangles formed by all the buildings when viewed from a distance. See the following example.

What is the maximum total sum that the height of the buildings can be increased?

Example:
Input: grid = [[3,0,8,4],[2,4,5,7],[9,2,6,3],[0,3,1,0]]
Output: 35
Explanation: 
The grid is:
[ [3, 0, 8, 4], 
  [2, 4, 5, 7],
  [9, 2, 6, 3],
  [0, 3, 1, 0] ]

The skyline viewed from top or bottom is: [9, 4, 8, 7]
The skyline viewed from left or right is: [8, 7, 9, 3]

The grid after increasing the height of buildings without affecting skylines is:

gridNew = [ [8, 4, 8, 7],
            [7, 4, 7, 7],
            [9, 4, 8, 7],
            [3, 3, 3, 3] ]

Notes:

1 < grid.length = grid[0].length <= 50.
All heights grid[i][j] are in the range [0, 100].
All buildings in grid[i][j] occupy the entire grid cell: that is, they are a 1 x 1 x grid[i][j] rectangular prism.*/

/*Runtime: 4 ms, faster than 99.71% of C++ online submissions for Max Increase to Keep City Skyline.
Memory Usage: 9.4 MB, less than 54.51% of C++ online submissions for Max Increase to Keep City Skyline.*/

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int m = grid.size();
        vector<int> lr;
        vector<int> tb;
        for (int i = 0; i<m; ++i)
        {
            int l = INT_MIN;
            int t = INT_MIN;
            for (int j = 0; j<m; ++j)
            {
                l = max(l, grid[i][j]);
                t = max(t, grid[j][i]);
            }
            lr.push_back(l);
            tb.push_back(t);
        }
        int res = 0;
        for (int i = 0; i< m; ++i)
        {
            for (int j = 0; j< m; ++j)
            {
                auto m = min(lr[i], tb[j]);
                res = res + (m>grid[i][j] ? m - grid[i][j] : 0);
            }
        }
        return res;
    }
};