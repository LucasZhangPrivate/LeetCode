/*Design a Tic-tac-toe game that is played between two players on a n x n grid.

You may assume the following rules:

A move is guaranteed to be valid and is placed on an empty block.
Once a winning condition is reached, no more moves is allowed.
A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
Example:
Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.

TicTacToe toe = new TicTacToe(3);

toe.move(0, 0, 1); -> Returns 0 (no one wins)
|X| | |
| | | |    // Player 1 makes a move at (0, 0).
| | | |

toe.move(0, 2, 2); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 2 makes a move at (0, 2).
| | | |

toe.move(2, 2, 1); -> Returns 0 (no one wins)
|X| |O|
| | | |    // Player 1 makes a move at (2, 2).
| | |X|

toe.move(1, 1, 2); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 2 makes a move at (1, 1).
| | |X|

toe.move(2, 0, 1); -> Returns 0 (no one wins)
|X| |O|
| |O| |    // Player 1 makes a move at (2, 0).
|X| |X|

toe.move(1, 0, 2); -> Returns 0 (no one wins)
|X| |O|
|O|O| |    // Player 2 makes a move at (1, 0).
|X| |X|

toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
|X| |O|
|O|O| |    // Player 1 makes a move at (2, 1).
|X|X|X|
Follow up:
Could you do better than O(n2) per move() operation?*/

/*Runtime: 36 ms, faster than 93.99% of C++ online submissions for Design Tic-Tac-Toe.
Memory Usage: 20.2 MB, less than 59.65% of C++ online submissions for Design Tic-Tac-Toe.*/

class TicTacToe {
private:
    vector<vector<char>> board;
    int n_;
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        board = vector<vector<char>>(n, vector<char>(n, ' '));
        n_ = n;
    }
    int checkWin(int row, int col, char p)
    {
        for (int i = 0; i < n_; ++i)
        {
            if (board[i][col] != p)break;
            if (i == n_ - 1)return 1;
        }
        for (int j = 0; j< n_; ++j)
        {
            if (board[row][j] != p)break;
            if (j == n_ - 1)return 1;
        }
        if (row + col == n_ - 1)
        {
            for (int i = 0; i< n_; ++i)
            {
                if (board[i][n_ - i - 1] != p) break;
                if (i == n_ - 1)return 1;
            }

        }
        if (row == col)
        {
            for (int i = 0; i< n_; ++i)
            {
                if (board[i][i] != p)break;
                if (i == n_ - 1)return 1;
            }
        }
        return 0;
    }
    /** Player {player} makes a move at ({row}, {col}).
    @param row The row of the board.
    @param col The column of the board.