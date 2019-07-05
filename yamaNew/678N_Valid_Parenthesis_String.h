/*Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:

Any left parenthesis '(' must have a corresponding right parenthesis ')'.
Any right parenthesis ')' must have a corresponding left parenthesis '('.
Left parenthesis '(' must go before the corresponding right parenthesis ')'.
'*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
An empty string is also valid.
Example 1:
Input: "()"
Output: True
Example 2:
Input: "(*)"
Output: True
Example 3:
Input: "(*))"
Output: True
Note:
The string size will be in the range [1, 100].*/

/*Runtime: 20 ms, faster than 16.33% of C++ online submissions for Valid Parenthesis String.
Memory Usage: 10.3 MB, less than 5.01% of C++ online submissions for Valid Parenthesis String.*/

class Solution {
public:
    bool isValid(vector<vector<int>>& m, int i, int j, const string& s)
    {
        if (i>j)return true;
        if (m[i][j] != -1) return m[i][j];
        if (i == j)return m[i][j] = (s[i] == '*');
        if ((s[i] == '(' || s[i] == '*') && (s[j] == ')' || s[j] == '*') && isValid(m, i + 1, j - 1, s))
            return m[i][j] = 1;
        for (int p = i; p<j; ++p)
        {
            if (isValid(m, i, p, s) && isValid(m, p + 1, j, s))return m[i][j] = 1;
        }
        return m[i][j] = 0;
    }


    bool checkValidString(string s) {
        int l = s.size();
        vector<vector<int>> m(l, vector<int>(l, -1));
        return isValid(m, 0, l - 1, s);
    }
};


class Solution {
public:
    bool checkValidString(const string& s) {
        int l = s.length();
        if (l == 0) return true;
        vector<vector<int>> dp(l, vector<int>(l, 0));
        for (int i = 0; i < l; ++i)
            if (s[i] == '*') dp[i][i] = 1;
        for (int len = 2; len <= l; ++len)
            for (int i = 0; i <= l - len; ++i) {
                int j = i + len - 1;
                // (...), *...), (...*, *...*
                if ((s[i] == '(' || s[i] == '*')
                    && (s[j] == ')' || s[j] == '*'))
                    if (len == 2 || dp[i + 1][j - 1]) {
                        dp[i][j] = 1;
                        continue;
                    }

                for (int k = i; k < j; ++k)
                    if (dp[i][k] && dp[k + 1][j]) {
                        dp[i][j] = 1;
                        break;
                    }
            }
        return dp[0][l - 1];
    }
};

class Solution {
public:
    bool checkValidString(string s) {
        int min_op = 0;
        int max_op = 0;

        for (char c : s) {
            if (c == '(') ++min_op; else --min_op;
            if (c != ')') ++max_op; else --max_op;
            if (max_op < 0) return false;
            min_op = max(0, min_op);
        }

        return min_op == 0;
    }
};