/*Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.*/

/*Runtime: 68 ms, faster than 81.02% of C++ online submissions for Search a 2D Matrix II.
Memory Usage: 13.1 MB, less than 6.79% of C++ online submissions for Search a 2D Matrix II.*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty())return false;
        int i = 0, j = matrix[0].size() - 1;
        while (i<matrix.size() && j >= 0)
        {
            if (matrix[i][j] == target)return true;
            if (matrix[i][j]<target)++i;
            else --j;
        }
        return false;
    }
};