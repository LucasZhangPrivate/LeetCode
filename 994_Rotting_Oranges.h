/*In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> direction{ { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
        queue<vector<int>> q;
        bool hasFresh = false;
        for (int i = 0; i< grid.size(); ++i) {
            for (int j = 0; j< grid[0].size(); ++j) {
                if (grid[i][j] == 2) {
                    q.push({ i,j });
                }
                //if(grid[i][j]==1)hasFresh = true;
            }
        }
        int result = 0;
        while (!q.empty()) {
            int n = q.size();
            bool newRo = false;
            while (n-->0) {
                auto idx = q.front();
                q.pop();
                for (auto&& d : direction) {
                    int x = idx[0] + d[0];
                    int y = idx[1] + d[1];
                    if (x >= 0 && x<grid.size() && y >= 0 && y<grid[0].size() && grid[x][y] == 1) {
                        newRo = true;
                        grid[x][y] = 2;
                        q.push({ x,y });
                    }
                }
            }
            if (newRo)result++;
        }

        for (int i = 0; i< grid.size(); ++i) {
            for (int j = 0; j< grid[0].size(); ++j) {
                if (grid[i][j] == 1)return -1;
            }
        }
        return result;
    }
};