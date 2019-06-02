/*Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().*/

/*Runtime: 4 ms, faster than 97.77% of C++ online submissions for Implement strStr().
Memory Usage: 9.2 MB, less than 63.02% of C++ online submissions for Implement strStr().*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty())return 0;
        for (int i = 0; i< haystack.size(); ++i)
        {
            for (int j = 0; j<needle.size(); ++j)
            {
                if (i + j >= haystack.size())return -1;
                if (needle[j] != haystack[i + j])break;
                if (j == needle.size() - 1)return i;
            }
        }
        return -1;
    }
};