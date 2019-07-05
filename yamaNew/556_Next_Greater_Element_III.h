/*Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.

Example 1:

Input: 12
Output: 21
 

Example 2:

Input: 21
Output: -1*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Greater Element III.
Memory Usage: 8.3 MB, less than 66.03% of C++ online submissions for Next Greater Element III.*/

class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        if (s.size() <= 1)return -1;
        int i = s.size() - 2;
        for (; i >= 0; --i)
        {
            if (s[i]<s[i + 1])break;
        }
        if (i == -1)return -1;
        int j = s.size() - 1;
        for (; j >= 0; --j)
        {
            if (s[j]>s[i])break;
        }
        swap(s[i], s[j]);
        reverse(s.begin() + i + 1, s.end());
        auto a = stoll(s.c_str());
        if (a>INT_MAX)return -1;
        return a;
    }
};