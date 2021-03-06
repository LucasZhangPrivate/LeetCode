/*You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

Example: 

Given the 2D grid:

INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:

  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4*/

/*Runtime: 84 ms, faster than 99.70% of C++ online submissions for Walls and Gates.
Memory Usage: 14.8 MB, less than 61.00% of C++ online submissions for Walls and Gates.*/

class Solution {
public:
    void fill(vector<vector<int>>& rooms, int i, int j, int dis)
    {
        if (rooms[i][j]<dis)return;
        else
        {
            rooms[i][j] = dis;
        }
        if (i - 1 >= 0 && rooms[i - 1][j]>0)fill(rooms, i - 1, j, dis + 1);
        if (i + 1<rooms.size() && rooms[i + 1][j]>0)fill(rooms, i + 1, j, dis + 1);
        if (j - 1 >= 0 && rooms[i][j - 1]>0)fill(rooms, i, j - 1, dis + 1);
        if (j + 1<rooms[0].size() && rooms[i][j + 1])fill(rooms, i, j + 1, dis + 1);
    }


    void wallsAndGates(vector<vector<int>>& rooms) {
        for (int i = 0; i< rooms.size(); ++i)
        {
            for (int j = 0; j< rooms[i].size(); ++j)
            {
                if (rooms[i][j] == 0)
                    fill(rooms, i, j, 0);
            }
        }
    }
};