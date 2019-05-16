/*Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.

Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.

Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.

Note:
The order of returned grid coordinates does not matter.
Both m and n are less than 150.
Example:

Given the following 5x5 matrix:

  Pacific ~   ~   ~   ~   ~ 
       ~  1   2   2   3  (5) *
       ~  3   2   3  (4) (4) *
       ~  2   4  (5)  3   1  *
       ~ (6) (7)  1   4   5  *
       ~ (5)  1   1   2   4  *
          *   *   *   *   * Atlantic

Return:

[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).*/

/*Runtime: 48 ms, faster than 96.91% of C++ online submissions for Pacific Atlantic Water Flow.
Memory Usage: 14.3 MB, less than 62.35% of C++ online submissions for Pacific Atlantic Water Flow.*/

class Solution {
public:
    void canReach(vector<vector<int>>& matrix, vector<vector<bool>>& reachP, int i, int j)
    {
        reachP[i][j] = true;
        if (i - 1 >= 0 && matrix[i - 1][j] >= matrix[i][j] && !reachP[i - 1][j])canReach(matrix, reachP, i - 1, j);
        if (i + 1<matrix.size() && matrix[i + 1][j] >= matrix[i][j] && !reachP[i + 1][j])canReach(matrix, reachP, i + 1, j);
        if (j - 1 >= 0 && matrix[i][j - 1] >= matrix[i][j] && !reachP[i][j - 1])canReach(matrix, reachP, i, j - 1);
        if (j + 1<matrix[0].size() && matrix[i][j + 1] >= matrix[i][j] && !reachP[i][j + 1])canReach(matrix, reachP, i, j + 1);
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> res;
        int row = matrix.size();
        if (row == 0)return res;
        int col = matrix[0].size();
        vector<vector<bool>> reachP(row, vector<bool>(col, false));
        vector<vector<bool>> reachA(row, vector<bool>(col, false));

        for (int i = 0; i< row; ++i)
        {
            for (int j = 0; j< col; ++j)
            {
                if (i == 0 || j == 0)canReach(matrix, reachP, i, j);
                if (i == row - 1 || j == col - 1)canReach(matrix, reachA, i, j);
            }
        }
        for (int i = 0; i< row; ++i)
        {
            for (int j = 0; j< col; ++j)
            {
                if (reachP[i][j] && reachA[i][j])res.push_back({ i,j });
            }
        }
        return res;
    }
};