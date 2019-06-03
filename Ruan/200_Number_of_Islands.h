/*Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3*/

/*Runtime: 108 ms, faster than 5.33% of C++ online submissions for Number of Islands.
Memory Usage: 27.7 MB, less than 5.00% of C++ online submissions for Number of Islands.*/

class Solution {
public:
    void help(vector<vector<char>>& grid, int i, int j)
    {
        if (grid[i][j] == '0')return;
        vector<vector<int>> di({ { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } });
        grid[i][j] = '0';
        for (const auto& p : di)
        {
            int x = i + p[0];
            int y = j + p[1];
            if (x >= 0 && x<grid.size() && y >= 0 && y<grid[i].size())
            {
                help(grid, x, y);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i< grid.size(); ++i)
        {
            for (int j = 0; j< grid[i].size(); ++j)
            {
                if (grid[i][j] == '1')
                {
                    res++;
                    help(grid, i, j);
                }
            }
        }
        return res;
    }
};