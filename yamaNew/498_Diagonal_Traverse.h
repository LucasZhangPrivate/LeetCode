/*Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image.

 

Example:

Input:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

Output:  [1,2,4,7,5,3,6,8,9]

Explanation:

 

Note:

The total number of elements of the given matrix will not exceed 10,000.*/

/*Runtime: 88 ms, faster than 39.75% of C++ online submissions for Diagonal Traverse.
Memory Usage: 17.9 MB, less than 10.65% of C++ online submissions for Diagonal Traverse.*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty())return {};
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 1, j = 0;
        vector<int> res;
        while (j<n)
        {
            int a = 0;
            int b = j;
            vector<int> temp;
            while (a<m && b >= 0)
            {
                temp.push_back(matrix[a][b]);
                a++;
                b--;
            }
            if (j % 2 == 0)reverse(temp.begin(), temp.end());
            res.insert(res.end(), temp.begin(), temp.end());
            j++;
        }
        while (i<m)
        {
            int a = i;
            int b = n - 1;
            vector<int>temp;
            while (b >= 0 && a<m)
            {
                temp.push_back(matrix[a][b]);
                a++;
                b--;
            }
            if ((i + n) % 2 == 1)reverse(temp.begin(), temp.end());
            res.insert(res.end(), temp.begin(), temp.end());
            i++;
        }
        return res;
    }
};