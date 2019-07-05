/*Let's play the minesweeper game (Wikipedia, online game)!

You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.

Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules:

If a mine ('M') is revealed, then the game is over - change it to 'X'.
If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
Return the board when no more squares will be revealed.
 

Example 1:

Input: 

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

Example 2:

Input: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

Output: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Explanation:

 

Note:

The range of the input matrix's height and width is [1,50].
The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at least one clickable square.
The input board won't be a stage when game is over (some mines have been revealed).
For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all the unrevealed mines when the game is over, consider any cases that you will win the game or flag any squares.*/

/*Runtime: 104 ms, faster than 10.75% of C++ online submissions for Minesweeper.
Memory Usage: 33.4 MB, less than 16.34% of C++ online submissions for Minesweeper.*/

class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        vector<vector<int>> grid = { { -1,-1 },{ -1,0 },{ -1,1 },{ 0,1 },{ 1,1 },{ 1,0 },{ 1,-1 },{ 0,-1 } };
        check(board, click[0], click[1], grid);
        return board;
    }
    void check(vector<vector<char>>& board, int x, int y, vector<vector<int>> grid)
    {
        if (board[x][y] == 'M')
        {
            board[x][y] = 'X';
            return;
        }
        if (board[x][y] == 'E')
        {

            int n = 0;
            int i = board.size();
            int j = board[0].size();
            for (auto &&g : grid)
            {
                int x1 = x + g[0];
                int y1 = y + g[1];
                if (x1 >= 0 && x1<i&&y1 >= 0 && y1<j&&board[x1][y1] == 'M')n++;
            }
            if (n == 0)
            {
                board[x][y] = 'B';
                for (auto &&g : grid)
                {
                    int x1 = x + g[0];
                    int y1 = y + g[1];
                    if (x1 >= 0 && x1<i&&y1 >= 0 && y1<j)
                    {
                        check(board, x1, y1, grid);
                    }
                }
            }
            else
            {
                board[x][y] = '0' + n;
            }
        }
    }
};