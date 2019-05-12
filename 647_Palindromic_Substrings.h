/*Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:

Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:

Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".*/

/*Runtime: 496 ms, faster than 10.25% of C++ online submissions for Palindromic Substrings.
Memory Usage: 515.6 MB, less than 5.02% of C++ online submissions for Palindromic Substrings.*/

//brute force 速度太慢
class Solution {
public:
    bool isP(const string& in)
    {
        if (in.size() == 1)return true;
        int i = 0;
        int j = in.size() - 1;
        while (i<j)
        {
            if (in[i++] != in[j--])return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int res = 0;
        for (auto l = 1; l <= s.size(); ++l)
        {
            for (auto i = 0; i + l <= s.size(); ++i)
            {
                auto str = s.substr(i, l);
                if (isP(str))res++;
            }
        }
        return res;
    }
};


//一个不错的方法
class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            count += countPalindromes(s, i, i);
            count += countPalindromes(s, i, i + 1);
        }
        return count;
    }

    int countPalindromes(string& s, int i, int j) {
        int count = 0;
        while (i >= 0 && j < s.size() && s[i--] == s[j++])
            count++;
        return count;
    }
};