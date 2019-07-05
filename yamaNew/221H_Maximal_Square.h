/*Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.

Example:

Input: 

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0

Output: 4*/

/*Runtime: 20 ms, faster than 86.42% of C++ online submissions for Maximal Square.
Memory Usage: 11.2 MB, less than 27.80% of C++ online submissions for Maximal Square.*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty())return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> size(m, vector<int>(n, 0));
        int res = 0;
        for (int i = 0; i<m; ++i)
        {
            for (int j = 0; j< n; ++j)
            {
                size[i][j] = matrix[i][j] - '0';
                if (size[i][j] == 0)continue;
                if (i != 0 && j != 0)
                    size[i][j] = min(size[i - 1][j - 1], min(size[i - 1][j], size[i][j - 1])) + 1;
                res = max(res, size[i][j] * size[i][j]);
            }
        }
        return res;

    }
};