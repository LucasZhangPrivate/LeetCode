/*Given two strings s and t, determine if they are both one edit distance apart.

Note: 

There are 3 possiblities to satisify one edit distance apart:

Insert a character into s to get t
Delete a character from s to get t
Replace a character of s to get t
Example 1:

Input: s = "ab", t = "acb"
Output: true
Explanation: We can insert 'c' into s to get t.
Example 2:

Input: s = "cab", t = "ad"
Output: false
Explanation: We cannot get t from s by only one step.
Example 3:

Input: s = "1203", t = "1213"
Output: true
Explanation: We can replace '0' with '1' to get t.*/

/*Runtime: 4 ms, faster than 90.86% of C++ online submissions for One Edit Distance.
Memory Usage: 8.8 MB, less than 21.91% of C++ online submissions for One Edit Distance.*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (s == t) return false;
        int m = s.size();
        int n = t.size();
        if (abs(m - n)>1)return false;
        int i = 0;
        while (i<m && i<n)
        {
            if (s[i] == t[i])i++;
            else
            {
                return s.substr(i + 1) == t.substr(i) || s.substr(i) == t.substr(i + 1)
                    || s.substr(i + 1) == t.substr(i + 1);
            }
        }
        return true;
    }
};