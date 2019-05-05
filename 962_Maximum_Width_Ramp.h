/*Given an array A of integers, a ramp is a tuple (i, j) for which i < j and A[i] <= A[j].  The width of such a ramp is j - i.

Find the maximum width of a ramp in A.  If one doesn't exist, return 0.

 

Example 1:

Input: [6,0,8,2,1,5]
Output: 4
Explanation: 
The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.
Example 2:

Input: [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: 
The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.
 

Note:

2 <= A.length <= 50000
0 <= A[i] <= 50000*/

/*Time out*/
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int res = 0;
        if (A.empty())return 0;
        int j = A.size() - 1;
        while (j >= 0)
        {
            int i = 0;
            while (A[i]>A[j] && i<j)
            {
                ++i;
            }
            res = max(res, j - i);
            auto cur = j;
            while (j>0 && A[j - 1]<A[cur])--j;
            --j;
        }
        return res;
    }
};

/*other good answer*/
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        int n = A.size();
        vector<int> small(n);
        vector<int> big(n);
        int ans = 0;
        small[0] = A[0];
        for (int i = 1; i<n; ++i)
        {
            small[i] = min(small[i - 1], A[i]);
        }
        big[n - 1] = A[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            big[i] = max(big[i + 1], A[i]);
        }
        int i = 0, j = 1;
        while (i < n && j < n) {
            if (small[i] <= big[j]) {
                ans = max(ans, j - i);
                j++;
            }
            else i++;
        }
        return ans;
    }
};