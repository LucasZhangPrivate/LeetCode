/*In an N by N square grid, each cell is either empty (0) or blocked (1).

A clear path from top-left to bottom-right has length k if and only if it is composed of cells C_1, C_2, ..., C_k such that:

Adjacent cells C_i and C_{i+1} are connected 8-directionally (ie., they are different and share an edge or corner)
C_1 is at location (0, 0) (ie. has value grid[0][0])
C_k is at location (N-1, N-1) (ie. has value grid[N-1][N-1])
If C_i is located at (r, c), then grid[r][c] is empty (ie. grid[r][c] == 0).
Return the length of the shortest such clear path from top-left to bottom-right.  If such a path does not exist, return -1.

 

Example 1:

Input: [[0,1],[1,0]]
Output: 2
Example 2:

Input: [[0,0,0],[1,1,0],[1,1,0]]
Output: 4
 

Note:

1 <= grid.length == grid[0].length <= 100
grid[r][c] is 0 or 1*/

/*Runtime: 136 ms, faster than 18.16% of C++ online submissions for Shortest Path in Binary Matrix.
Memory Usage: 32 MB, less than 100.00% of C++ online submissions for Shortest Path in Binary Matrix.*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if (grid.empty())return -1;
        int m = grid.size();
        int n = grid[0].size();
        if (grid[0][0] == 1 || grid[m - 1][n - 1])return -1;
        vector<vector<bool>> visited = vector<vector<bool>>(m, vector<bool>(n, false));
        vector<vector<int>> di({ { -1,0 },{ -1,-1 },{ -1,1 },{ 0,-1 },{ 0,1 },{ 1,-1 },{ 1,0 },{ 1,1 } });
        queue<vector<int>> q;
        q.push({ 0,0 });
        visited[0][0] = true;
        int count = 1;
        while (!q.empty())
        {
            int size = q.size();
            while (size-->0)
            {
                auto index = q.front();
                q.pop();
                for (const auto& d : di)
                {
                    int x = index[0] + d[0];
                    int y = index[1] + d[1];
                    if (x<0 || x >= grid.size() || y<0 || y >= grid[0].size() || visited[x][y])continue;
                    visited[x][y] = true;
                    if (x == m - 1 && y == n - 1)return count + 1;
                    if (grid[x][y] == 0)q.push({ x,y });
                }
            }
            count++;
        }
        return -1;
    }
};