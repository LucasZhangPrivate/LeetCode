/*According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.

Example:

Input: 
[
  [0,1,0],
  [0,0,1],
  [1,1,1],
  [0,0,0]
]
Output: 
[
  [0,0,0],
  [1,0,1],
  [0,1,1],
  [0,1,0]
]
Follow up:

Could you solve it in-place? Remember that the board needs to be updated at the same time: You cannot update some cells first and then use their updated values to update other cells.
In this question, we represent the board using a 2D array. In principle, the board is infinite, which would cause problems when the active area encroaches the border of the array. How would you address these problems?*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Game of Life.
Memory Usage: 8.9 MB, less than 39.82% of C++ online submissions for Game of Life.*/

class Solution {
private:
    vector<vector<int>> ne;
public:
    void check(vector<vector<int>>& board, int i, int j)
    {
        int sum = 0;
        for (const auto& n : ne)
        {
            auto x = i + n[0];
            auto y = j + n[1];
            if (x<0 || x >= board.size() || y<0 || y >= board[0].size())continue;
            if (board[x][y] == 2)
            {
                sum += 0;
            }
            else if (board[x][y] == 3)
            {
                sum += 1;
            }
            else sum += board[x][y];
        }
        if (board[i][j] == 1 && (sum<2 || sum>3))board[i][j] = 3;
        if (board[i][j] == 0 && sum == 3) board[i][j] = 2;
    }


    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        ne = vector<vector<int>>({ { -1,-1 },{ -1,0 },{ -1,1 },{ 0,-1 },{ 0,1 },{ 1,-1 },{ 1,0 },{ 1,1 } });
        for (int i = 0; i< m; ++i)
        {
            for (int j = 0; j< n; ++j)check(board, i, j);
        }
        for (int i = 0; i< m; ++i)
        {
            for (int j = 0; j< n; ++j)
            {
                if (board[i][j] == 2)board[i][j] = 1;
                if (board[i][j] == 3)board[i][j] = 0;
            }
        }

    }
};