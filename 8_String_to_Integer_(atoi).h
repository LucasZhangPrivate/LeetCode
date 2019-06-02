﻿/*Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, INT_MAX (231 − 1) or INT_MIN (−231) is returned.
Example 1:

Input: "42"
Output: 42
Example 2:

Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
             Then take as many numerical digits as possible, which gets 42.
Example 3:

Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.
Example 4:

Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical 
             digit or a +/- sign. Therefore no valid conversion could be performed.
Example 5:

Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
             Thefore INT_MIN (−231) is returned.*/

/*Runtime: 8 ms, faster than 86.55% of C++ online submissions for String to Integer (atoi).
Memory Usage: 8.6 MB, less than 53.82% of C++ online submissions for String to Integer (atoi).*/

class Solution {
public:
    int myAtoi(string str) {
        auto start = str.find_first_not_of(' ');
        if (start == string::npos)return 0;
        str = str.substr(start);
        int sign = 1;
        int i = 0;
        if (str[0] == '-')
        {
            sign = -1;
            i = 1;
        }
        else if (str[0] == '+')
        {
            i = 1;
        }
        int res = 0;
        for (; i<str.size(); ++i)
        {
            if (str[i]<'0' || str[i]>'9') break;
            int cur = str[i] - '0';
            if (sign == 1)
            {
                if (res > INT_MAX / 10 || res == INT_MAX / 10 && cur >= INT_MAX % 10)return INT_MAX;
            }
            if (sign == -1)
            {
                if (res*-1 < INT_MIN / 10 || res * -1 == INT_MIN / 10 && cur*-1 <= INT_MIN % 10)return INT_MIN;
            }
            res = res * 10 + cur;
        }
        return res * sign;
    }
};