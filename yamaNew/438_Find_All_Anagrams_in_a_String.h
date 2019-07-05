/*Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".*/

/*Runtime: 32 ms, faster than 80.53% of C++ online submissions for Find All Anagrams in a String.
Memory Usage: 10.5 MB, less than 40.06% of C++ online submissions for Find All Anagrams in a String.*/

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> a(26, 0);
        vector<int> b = a;
        vector<int> res;
        if (p.size()>s.size())return res;
        for (int i = 0; i<p.size(); ++i)
        {
            a[s[i] - 'a']++;
            b[p[i] - 'a']++;
        }
        if (a == b)res.push_back(0);
        for (int i = p.size(); i<s.size(); ++i)
        {
            a[s[i] - 'a']++;
            a[s[i - p.size()] - 'a']--;
            if (a == b)res.push_back(i - p.size() + 1);
        }
        return res;
    }
};