/*Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.*/

/*Runtime: 36 ms, faster than 96.23% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.
Memory Usage: 11.8 MB, less than 99.82% of C++ online submissions for Kth Smallest Element in a Sorted Matrix.*/

//花花的相当巧妙的答案，l=m+1，保证接近的时候数值一个一个的加，恰好达到临界的时候保证出现在matrix里面
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1] + 1;
        while (l < r) {
            long m = l + (r - l) / 2;
            int total = 0;
            for (const auto& row : matrix)
                total += distance(begin(row), upper_bound(row.begin(), end(row), m));
            if (total >= k)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};