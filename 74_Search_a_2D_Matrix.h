/*Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
Example 1:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 3
Output: true
Example 2:

Input:
matrix = [
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
target = 13
Output: false*/

/*Runtime: 8 ms, faster than 98.66% of C++ online submissions for Search a 2D Matrix.
Memory Usage: 10 MB, less than 54.43% of C++ online submissions for Search a 2D Matrix.*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = matrix.size();
        if (r == 0)return false;
        int c = matrix[0].size();
        if (c == 0)return false;
        int start = 0;
        int end = r - 1;
        while (start< end)
        {
            int mid = (start + end) / 2;
            if (target > matrix[mid][c - 1])
            {
                start = mid + 1;
            }
            else if (target < matrix[mid][0])
            {
                end = mid - 1;
            }
            else {
                start = mid;
                break;
            }
        }
        int i = 0;
        int j = c - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (target == matrix[start][mid])return true;
            else if (target > matrix[start][mid])
            {
                i = mid + 1;
            }
            else {
                j = mid - 1;
            }
        }
        return false;
    }
};