/*Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".*/

//dp需要最后重点看看的
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int dp[s.size()][s.size()];
        int n = s.size();
        for (int i = 0; i<n; i++) {
            for (int j = 0; j<n; j++) {
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i<n; i++) {
            dp[i][i] = 1;
        }
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j + i - 1<n; j++) {
                if (s[j] == s[j + i - 1]) {
                    dp[j][i + j - 1] = 2 + dp[j + 1][i + j - 1 - 1];
                }
                else {
                    dp[j][i + j - 1] = max(dp[j + 1][i + j - 1], dp[j][i + j - 1 - 1]);
                }
            }
        }
        return dp[0][n - 1];
    }
};