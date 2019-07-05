/*Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.) You may assume all four edges of the grid are surrounded by water.

Find the maximum area of an island in the given 2D array. (If there is no island, the maximum area is 0.)

Example 1:

[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
Given the above grid, return 6. Note the answer is not 11, because the island must be connected 4-directionally.
Example 2:

[[0,0,0,0,0,0,0,0]]
Given the above grid, return 0.
Note: The length of each dimension in the given grid does not exceed 50.*/

/*Runtime: 16 ms, faster than 85.67% of C++ online submissions for Max Area of Island.
Memory Usage: 10.4 MB, less than 84.36% of C++ online submissions for Max Area of Island.*/

class Solution {
public:
    void help(vector<vector<int>>& grid, int i, int j, int& res)
    {
        res++;
        grid[i][j] = 0;
        if (i - 1 >= 0 && grid[i - 1][j] == 1)help(grid, i - 1, j, res);
        if (i + 1<grid.size() && grid[i + 1][j] == 1)help(grid, i + 1, j, res);
        if (j - 1 >= 0 && grid[i][j - 1] == 1)help(grid, i, j - 1, res);
        if (j + 1<grid[i].size() && grid[i][j + 1] == 1)help(grid, i, j + 1, res);
    }


    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i<grid.size(); ++i)
        {
            for (int j = 0; j<grid[i].size(); ++j)
            {

                if (grid[i][j] == 1 && (i == 0 || grid[i - 1][j] != 1) && (j == 0 || grid[i][j - 1] != 1))
                {
                    int res = 0;
                    help(grid, i, j, res);
                    ans = max(ans, res);
                }
            }
        }
        return ans;
    }
};