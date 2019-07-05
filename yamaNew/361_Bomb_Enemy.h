/*Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb.
The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
Note: You can only put the bomb at an empty cell.

Example:

Input: [["0","E","0","0"],["E","0","W","E"],["0","E","0","0"]]
Output: 3 
Explanation: For the given grid,

0 E 0 0 
E 0 W E 
0 E 0 0

Placing a bomb at (1,1) kills 3 enemies.*/

/*Runtime: 104 ms, faster than 5.41% of C++ online submissions for Bomb Enemy.
Memory Usage: 33.6 MB, less than 5.28% of C++ online submissions for Bomb Enemy.*/

class Solution {
public:
    int kill(vector<vector<char>>& grid, int i, int j)
    {
        int res = 0;
        vector<vector<int>> di({ { -1,0 },{ 0,-1 },{ 1,0 },{ 0,1 } });
        for (const auto& d : di)
        {
            int a = i, b = j;
            while (a + d[0] >= 0 && a + d[0]<grid.size() && b + d[1] >= 0 && b + d[1]<grid[a + d[0]].size()
                && grid[a + d[0]][b + d[1]] != 'W')
            {
                a += d[0];
                b += d[1];
                if (grid[a][b] == 'E')res++;
            }
        }
        return res;
    }
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int res = 0;
        for (int i = 0; i< grid.size(); ++i)
        {
            for (int j = 0; j< grid[i].size(); ++j)
            {
                if (grid[i][j] == '0')
                {
                    res = max(res, kill(grid, i, j));
                }
            }
        }
        return res;
    }
};

/*Runtime: 40 ms, faster than 45.08% of C++ online submissions for Bomb Enemy.
Memory Usage: 14.9 MB, less than 7.17% of C++ online submissions for Bomb Enemy.*/

class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        if (grid.size() == 0)
            return 0;
        vector<vector<int>> killcounter(grid.size(), vector<int>(grid[0].size(), 0));

        // Left to Right for each row   
        for (int i = 0; i<grid.size(); i++)
        {
            int enemy = 0;
            for (int j = 0; j<grid[0].size(); j++)
            {
                if (grid[i][j] == 'W')
                    enemy = 0;
                else if (grid[i][j] == 'E')
                    enemy += 1;
                else if (grid[i][j] == '0')
                    killcounter[i][j] += enemy;
            }
        }
        // Right to Left for each row   
        for (int i = 0; i<grid.size(); i++)
        {
            int enemy = 0;
            for (int j = grid[0].size() - 1; j >= 0; j--)
            {
                if (grid[i][j] == 'W')
                    enemy = 0;
                else if (grid[i][j] == 'E')
                    enemy += 1;
                else if (grid[i][j] == '0')
                    killcounter[i][j] += enemy;
            }
        }
        // Up to Down for each column   
        for (int j = 0; j<grid[0].size(); j++)
        {
            int enemy = 0;
            for (int i = 0; i<grid.size(); i++)
            {
                if (grid[i][j] == 'W')
                    enemy = 0;
                else if (grid[i][j] == 'E')
                    enemy += 1;
                else if (grid[i][j] == '0')
                    killcounter[i][j] += enemy;
            }
        }
        // Down to Up for each column   
        for (int j = 0; j<grid[0].size(); j++)
        {
            int enemy = 0;
            for (int i = grid.size() - 1; i >= 0; i--)
            {
                if (grid[i][j] == 'W')
                    enemy = 0;
                else if (grid[i][j] == 'E')
                    enemy += 1;
                else if (grid[i][j] == '0')
                    killcounter[i][j] += enemy;
            }
        }

        // Final traversal to get the max count  
        int globalenemy = 0;
        for (int i = 0; i<grid.size(); i++)
        {
            for (int j = 0; j<grid[0].size(); j++)
            {
                if (grid[i][j] == '0')
                {
                    int enemy = killcounter[i][j];
                    if (enemy>globalenemy)
                        globalenemy = enemy;
                }
            }
        }
        return globalenemy;
    }
};