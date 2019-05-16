/*Given an 2D board, count how many battleships are in it. The battleships are represented with 'X's, empty slots are represented with '.'s. You may assume the following rules:
You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - there are no adjacent battleships.*/

/*Runtime: 8 ms, faster than 97.20% of C++ online submissions for Battleships in a Board.
Memory Usage: 9.5 MB, less than 88.19% of C++ online submissions for Battleships in a Board.*/

/*不是所有的矩阵都需要递归，这个是个很好的取巧的例子，只需要把最左边最上面的点标记为一个船就行，其他的都是船身
可以直接越过*/
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int res = 0;
        for (int i = 0; i< board.size(); ++i)
        {
            for (int j = 0; j< board[i].size(); ++j)
            {
                if (board[i][j] == 'X')
                {
                    if (i - 1 >= 0 && board[i - 1][j] == 'X')continue;
                    if (j - 1 >= 0 && board[i][j - 1] == 'X')continue;
                    res++;
                }
            }
        }
        return res;
    }
};