/*A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.

Here are the rules of Tic-Tac-Toe:

Players take turns placing characters into empty squares (" ").
The first player always places "X" characters, while the second player always places "O" characters.
"X" and "O" characters are always placed into empty squares, never filled ones.
The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
The game also ends if all squares are non-empty.
No more moves can be played if the game is over.
Example 1:
Input: board = ["O  ", "   ", "   "]
Output: false
Explanation: The first player always plays "X".

Example 2:
Input: board = ["XOX", " X ", "   "]
Output: false
Explanation: Players take turns making moves.

Example 3:
Input: board = ["XXX", "   ", "OOO"]
Output: false

Example 4:
Input: board = ["XOX", "O O", "XOX"]
Output: true*/

/*Runtime: 4 ms, faster than 100.00% of C++ online submissions for Valid Tic-Tac-Toe State.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Valid Tic-Tac-Toe State.*/


//这道题应该是考察思考的全面性的，corner case需要注意
class Solution {
public:
    bool rowWin(const vector<string>& board, char key) //保证同一颜色不能重复赢
    {
        int count = 0;
        for (const auto& row : board)
        {
            if (row[0] == key && row[1] == key && row[2] == key)count++;
        }
        return count == 1;
    }
    bool colWin(const vector<string>& board, char key)
    {
        int count = 0;
        for (int i = 0; i<3; ++i)
        {
            if (board[0][i] == key && board[1][i] == key && board[2][i] == key)count++;
        }
        return count == 1;
    }
    int dioWin(const vector<string>& board, char key)
    {
        int count = 0;
        if (board[0][0] == key && board[1][1] == key && board[2][2] == key)count++;
        if (board[2][0] == key && board[1][1] == key && board[0][2] == key)count++;
        return count == 1 || count == 2;
    }
    bool validTicTacToe(vector<string>& board) {
        int i = 0, j = 0;
        for (const auto& s : board)
        {
            for (const auto&c : s)
            {
                if (c == 'X')i++;
                else if (c == 'O')j++;
                else if (c != ' ')return false;
            }
        }
        if (i>j + 1 || i<j)return false; //保证棋子个数合理性

        if ((rowWin(board, 'X') || colWin(board, 'X') || dioWin(board, 'X')) && i == j)return false; //保证赢了以后没人继续落子
        if ((rowWin(board, 'O') || colWin(board, 'O') || dioWin(board, 'O')) && i>j) return false;

        if ((rowWin(board, 'X') || colWin(board, 'X')) && (rowWin(board, 'O') || colWin(board, 'O')))
            return false; //保证双方不能同时赢
        return true;
    }
};