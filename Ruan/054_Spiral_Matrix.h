/*Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

Example 1:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
Output: [1,2,3,6,9,8,7,4,5]
Example 2:

Input:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
Memory Usage: 8.6 MB, less than 60.60% of C++ online submissions for Spiral Matrix.*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty())return res;
        if (matrix.size() == 1)return matrix[0];
        int ti = 0, tj = 0;
        int bi = matrix.size() - 1;
        int bj = matrix[0].size() - 1;

        while (true)
        {
            int i = ti;
            int j = tj;
            while (j <= bj)res.push_back(matrix[i][j++]);
            j--;
            i++;
            if (i>bi)break;
            while (i <= bi)res.push_back(matrix[i++][j]);
            i--;
            j--;
            if (j<tj)break;
            while (j >= tj)res.push_back(matrix[i][j--]);
            j++;
            i--;
            if (i<ti)break;
            while (i>ti)res.push_back(matrix[i--][j]);  //注意这里是>因为需要排除第一排已经算过的一个
            ti++;
            tj++;
            bi--;
            bj--;
            if (ti>bi || tj>bj)break;
        }
        return res;
    }
};