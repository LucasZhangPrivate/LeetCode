/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?*/

/*Runtime: 48 ms, faster than 91.40% of C++ online submissions for Set Matrix Zeroes.
Memory Usage: 11.5 MB, less than 71.83% of C++ online submissions for Set Matrix Zeroes.*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        bool top = false;
        bool left = false;

        for (int i = 0; i< r; ++i)
        {
            for (int j = 0; j<c; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    if (i == 0)top = true;
                    if (j == 0)left = true;
                    if (i != 0 && j != 0)
                    {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
                }
            }
        }
        for (int i = 1; i< r; ++i)
        {
            for (int j = 1; j<c; ++j)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        if (top)
        {
            for (int j = 0; j< c; ++j)matrix[0][j] = 0;
        }
        if (left)
        {
            for (int i = 0; i< r; ++i)matrix[i][0] = 0;
        }
    }
};