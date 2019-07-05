/*Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

Example:

Input: 3
Output:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]*/

/*Runtime: 4 ms, faster than 85.35% of C++ online submissions for Spiral Matrix II.
Memory Usage: 9 MB, less than 21.81% of C++ online submissions for Spiral Matrix II.*/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int cur = 1;
        int x1 = 0;
        int y1 = 0;
        int x2 = n - 1;
        int y2 = n - 1;
        int i = 0;
        int j = 0;
        while (true)
        {
            while (j <= y2)res[i][j++] = cur++;
            x1++;
            j--;
            i++;
            if (cur == n * n + 1)break;
            while (i <= x2)res[i++][j] = cur++;
            i--;
            j--;
            y2--;
            if (cur == n * n + 1)break;
            while (j >= y1)res[i][j--] = cur++;
            j++;
            i--;
            x2--;
            if (cur == n * n + 1)break;
            while (i >= x1)res[i--][j] = cur++;
            i++;
            j++;
            y1++;
            if (cur == n * n + 1)break;
        }
        return res;

    }
};