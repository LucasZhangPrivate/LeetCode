/*Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.*/




/*Runtime: 20 ms, faster than 98.54% of C++ online submissions for Word Search.
Memory Usage: 10.4 MB, less than 86.05% of C++ online submissions for Word Search.*/
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        const char* c = word.c_str();
        //int len=strlen(c);
        int len = word.size();
        int m = board.size();
        bool mark = false;
        if (m == 0)return false;
        int n = board[0].size();
        if (m*n<len)return false;
        for (int i = 0; i<m; i++)
        {
            for (int j = 0; j<n; j++)
            {
                if (board[i][j] == c[0])
                {
                    dfs(i, j, 0, board, c, mark, len);
                    if (mark == true)break;
                }
            }
        }
        return mark;
    }

    void dfs(int row, int col, int index, vector<vector<char>> &board, const char *c, bool &mark, int len)// mark must have & sign;
    {
        if (mark == true)return;
        if (board[row][col] != c[index])return;
        if (board[row][col] == c[index] && index == len - 1)
        {
            mark = true;
            return;
        }
        else
        {
            char temp = board[row][col];
            board[row][col] = ' ';
            if (row - 1 >= 0 && board[row - 1][col] != ' ')dfs(row - 1, col, index + 1, board, c, mark, len);
            if (row + 1<board.size() && board[row + 1][col] != ' ')dfs(row + 1, col, index + 1, board, c, mark, len);
            if (col - 1 >= 0 && board[row][col - 1] != ' ')dfs(row, col - 1, index + 1, board, c, mark, len);
            if (col + 1<board[0].size() && board[row][col + 1] != ' ')dfs(row, col + 1, index + 1, board, c, mark, len);
            board[row][col] = temp;
        }

    }
};


/*Runtime: 300 ms, faster than 30.62% of C++ online submissions for Word Search.
Memory Usage: 159.1 MB, less than 16.56% of C++ online submissions for Word Search.*/

class Solution {
public:
    void check(vector<vector<char>>& board, int i, int j, bool& mark, string word, int index)
    {
        if (i<0 || i >= board.size() || j<0 || j >= board[0].size() || mark == true
            || index >= word.size())return;
        if (board[i][j] == word[index])
        {
            if (index == word.size() - 1)
            {
                mark = true;
                return;
            }
            else
            {
                auto keep = board[i][j];
                board[i][j] = '0';
                check(board, i - 1, j, mark, word, index + 1);
                check(board, i + 1, j, mark, word, index + 1);
                check(board, i, j - 1, mark, word, index + 1);
                check(board, i, j + 1, mark, word, index + 1);

                board[i][j] = keep;
            }
        }
    }


    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty())return false;
        if (word.empty())return true;
        bool mark = false;
        for (int i = 0; i<board.size(); ++i)
        {
            for (int j = 0; j<board[i].size(); ++j)
            {
                check(board, i, j, mark, word, 0);
            }
        }
        return mark;
    }
};

