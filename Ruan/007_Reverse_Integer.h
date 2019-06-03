/*Given a 32-bit signed integer, reverse digits of an integer.

Example 1:

Input: 123
Output: 321
Example 2:

Input: -123
Output: -321
Example 3:

Input: 120
Output: 21
Note:
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Integer.
Memory Usage: 8.4 MB, less than 57.24% of C++ online submissions for Reverse Integer.*/

class Solution {
public:
    int reverse(int x) {
        if (x == 0)return x;
        int sign = x>0 ? 1 : -1;
        int res = 0;
        while (x != 0)
        {
            int digit = x % 10;
            if (sign == 1 && (res>INT_MAX / 10 || res == INT_MAX / 10 && digit > INT_MAX % 10))return 0;
            if (sign == -1 && (res < INT_MIN / 10 || res == INT_MIN / 10 && digit < INT_MIN % 10))return 0;
            res = res * 10 + digit;
            x /= 10;
        }
        return res;
    }
};