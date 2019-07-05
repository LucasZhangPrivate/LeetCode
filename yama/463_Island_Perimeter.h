/*You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water.

Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells).

The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

 

Example:

Input:
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]

Output: 16

Explanation: The perimeter is the 16 yellow stripes in the image below:

*/

/*Runtime: 96 ms, faster than 31.79% of C++ online submissions for Island Perimeter.
Memory Usage: 25.3 MB, less than 30.53% of C++ online submissions for Island Perimeter.*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<pair<int, int>>q;
        bool find = false;
        for (int i = 0; i< grid.size(); ++i)
        {
            for (int j = 0; j<grid[i].size(); ++j)
            {
                if (grid[i][j] == 1)
                {
                    grid[i][j] = 2;
                    q.push({ i,j });
                    find = true;
                }
                if (find)break;
            }
            if (find)break;
        }
        int cells = 0;
        int con = 0;
        vector<vector<int>> di({ { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } });
        while (!q.empty())
        {
            int size = q.size();
            while (size-->0)
            {
                auto cur = q.front();
                cells++;
                q.pop();
                for (const auto& d : di)
                {
                    int i = cur.first + d[0];
                    int j = cur.second + d[1];
                    if (i >= 0 && i<grid.size() && j >= 0 && j<grid[i].size())
                    {
                        if (grid[i][j] == 1 || grid[i][j] == 2)
                            con++;
                        if (grid[i][j] == 1)
                        {
                            grid[i][j] = 2;
                            q.push({ i,j });
                        }

                    }
                }

            }
        }
        return cells * 4 - con;
    }
};

/*Runtime: 324 ms, faster than 5.08% of C++ online submissions for Island Perimeter.
Memory Usage: 101 MB, less than 5.06% of C++ online submissions for Island Perimeter.*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> direction = { { 0,-1 },{ 0,1 },{ -1,0 },{ 1,0 } };
        int sum = 0;
        for (int i = 0; i<grid.size(); ++i)
        {
            for (int j = 0; j<grid[0].size(); ++j)
            {
                if (grid[i][j] == 1)
                    sum += check(i, j, grid, direction);
            }
        }
        return sum;
    }
    int check(int i, int j, vector<vector<int>>&grid, vector<vector<int>>di)
    {
        int sum = 4;
        for (auto d : di)
        {
            int x = i + d[0];
            int y = j + d[1];
            if (x >= 0 && x<grid.size() && y >= 0 && y<grid[0].size() && grid[x][y] == 1)sum--;
        }
        return sum;
    }
};