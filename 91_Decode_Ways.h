/*A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).*/



//³¬•r
class Solution {
public:
    void de(string s, int& res, int start)
    {
        if (start == s.size())
        {
            res++;
            return;
        }
        string temp;
        for (int i = start; i <= start + 1 && i<s.size(); ++i)
        {
            temp += s[i];
            int n = atoi(temp.c_str());
            if (n <= 26 && n >= 1)de(s, res, i + 1);
            else return;
        }
    }

    int numDecodings(string s) {
        if (s.empty())return 0;
        int res = 0;
        de(s, res, 0);
        return res;
    }
};


// „eÈË´ð°¸Ò»
class Solution {
public:
    bool isReasonable(int val)
    {
        return val >= 1 && val <= 26;
    }
    int numDecodings(string s) {
        if (s.empty()) return 0;
        if (s[0] == '0') return 0;
        if (s.size() == 1) return 1;
        int bb = 1, b = 1, c = 0;
        for (int i = 1; i<s.size(); i++)
        {
            if (s[i] == '0')
            {
                if (isReasonable(atoi(s.substr(i - 1, 2).c_str()))) c = bb;
                else return 0;
            }
            else
            {
                if (s[i - 1] == '0') c = b;
                else
                {
                    if (isReasonable(atoi(s.substr(i - 1, 2).c_str()))) c = bb + b;
                    else c = b;
                }
            }

            bb = b;
            b = c;
        }
        return c;
    }
};

//dp
class Solution {
public:
    int numDecodings(string s) {
        if (!s.size() || s.front() == '0') return 0;
        // r2: decode ways of s[i-2] , r1: decode ways of s[i-1] 
        int r1 = 1, r2 = 1;

        for (int i = 1; i < s.size(); i++) {
            // zero voids ways of the last because zero cannot be used separately
            if (s[i] == '0') r1 = 0;

            // possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
            if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
                r1 = r2 + r1;
                r2 = r1 - r2;

            }

            // one-digit letter, no new way added
            else {
                r2 = r1;
            }
        }

        return r1;
    }
};