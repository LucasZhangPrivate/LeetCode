/*Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.*/

/*Runtime: 4 ms, faster than 92.48% of C++ online submissions for Longest Palindrome.
Memory Usage: 8.9 MB, less than 50.81% of C++ online submissions for Longest Palindrome.*/

class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> a(128, 0);
        for (const auto& c : s)
        {
            a[c]++;
        }
        int res = 0;
        int odd = 0;
        for (const auto& n : a)
        {
            if (n % 2 == 1)odd = 1;
            res += n / 2;
        }
        return res * 2 + odd;
    }
};