/*Given an array of integers A, find the sum of min(B), where B ranges over every (contiguous) subarray of A.

Since the answer may be large, return the answer modulo 10^9 + 7.

 

Example 1:

Input: [3,1,2,4]
Output: 17
Explanation: Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4]. 
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.  Sum is 17.
 

Note:

1 <= A.length <= 30000
1 <= A[i] <= 30000
 */

/*Runtime: 88 ms, faster than 92.34% of C++ online submissions for Sum of Subarray Minimums.
Memory Usage: 17.1 MB, less than 29.78% of C++ online submissions for Sum of Subarray Minimums.*/

class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int n = A.size();
        vector<int> L(n, 0), R(n, 0);
        stack<int>  st;
        A.push_back(INT_MIN);
        for (int i = 0; i <= n; ) {
            if (st.empty() || A[st.top()] < A[i]) st.push(i++);
            else {
                int pos = st.top(); st.pop();
                R[pos] = i - pos - 1;
                L[pos] = st.empty() ? pos : pos - st.top() - 1;
            }
        }

        int ans = 0, cur = 0, mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            cur = 1 + L[i] + R[i] + L[i] * R[i];
            ans = (ans + cur * A[i]) % mod;
        }
        return ans;
    }
};


//用的dp，结果超内存
class Solution {
public:
    int sumSubarrayMins(vector<int>& A) {
        int m = A.size();
        int mode = 1e9 + 7;
        vector<vector<int>> dp(m, vector<int>(m, 0));
        for (int i = 0; i<A.size(); ++i)dp[i][i] = A[i];
        for (int l = 2; l <= m; ++l)
        {
            for (int i = 0; i + l - 1<m; ++i)
            {
                dp[i][i + l - 1] = min(A[i], dp[i + 1][i + l - 1]);
            }
        }
        long res = 0;
        for (const auto& a : dp)
        {
            for (const auto& b : a)res += b;
            res %= mode;
        }
        return res;
    }
};