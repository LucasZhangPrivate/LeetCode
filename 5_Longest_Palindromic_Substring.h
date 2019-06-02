/*Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example 1:

Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: "cbbd"
Output: "bb"*/

/*Runtime: 36 ms, faster than 59.77% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 104 MB, less than 19.16% of C++ online submissions for Longest Palindromic Substring.*/


//https://leetcode.windliang.cc/leetCode-5-Longest-Palindromic-Substring.html

class Solution {
public:
    int help(string s, int l, int r)
    {
        while (l >= 0 && r<s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        return r - l - 1;
    }
    string longestPalindrome(string s) {
        if (s.empty() || s.size() == 1)return s;
        int maxlen = 0;
        int start = 0, end = 0;
        for (int i = 0; i<s.size(); ++i)
        {
            int len1 = help(s, i, i);
            int len2 = help(s, i, i + 1);
            int len = max(len1, len2);
            if (len> maxlen)
            {
                maxlen = len;
                start = i - (len - 1) / 2;
                end = i + len / 2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};

/*Runtime: 112 ms, faster than 39.22% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 9.8 MB, less than 59.19% of C++ online submissions for Longest Palindromic Substring.*/

class Solution {    //more attention
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        if (n == 0)return "";
        if (n == 1)return s;
        int maxlen = 1;
        int begin = 0;
        bool check[n][n] = { false };
        for (int i = 0; i<n; i++)
            check[i][i] = true;
        for (int i = 0; i<n - 1; i++)
            if (s[i] == s[i + 1])
            {
                check[i][i + 1] = true;
                begin = i;
                maxlen = 2;
            }


        for (int i = 2; i<n; i++)
        {
            for (int j = 0; j<n - i; j++)
            {
                if ((s[j] == s[j + i]) && check[j + 1][j + i - 1])
                {
                    check[j][j + i] = true;
                    begin = j;
                    maxlen = i + 1;
                }
            }
        }

        return s.substr(begin, maxlen);
    }
};