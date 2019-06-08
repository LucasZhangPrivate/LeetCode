/*Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.*/

/*Runtime: 12 ms, faster than 63.77% of C++ online submissions for Isomorphic Strings.
Memory Usage: 9.4 MB, less than 13.13% of C++ online submissions for Isomorphic Strings.*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.empty() && t.empty())return true;
        int count = 0;
        unordered_map<char, int> a, b;
        for (int i = 0; i<s.size(); ++i)
        {
            if (!a.count(s[i]) && !b.count(t[i]))
            {
                a[s[i]] = count;
                b[t[i]] = count;
                count++;
                continue;
            }
            if (a.count(s[i]) && b.count(t[i]) && a[s[i]] == b[t[i]])continue;
            else return false;
        }
        return true;
    }
};