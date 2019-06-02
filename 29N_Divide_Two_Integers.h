/*Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.*/

/*Runtime: 4 ms, faster than 95.01% of C++ online submissions for Divide Two Integers.
Memory Usage: 8.1 MB, less than 84.52% of C++ online submissions for Divide Two Integers.*/

class Solution {
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == divisor)return 1;
        int sign = 1;
        if (dividend == INT_MIN && divisor == -1)return INT_MAX;
        if (dividend<0 && divisor<0)
        {

            if (divisor == INT_MIN)return 0;
            else if (dividend == INT_MIN)
            {
                long int temp = INT_MAX; //maybe should use other method to instead of long int
                return temp / (-divisor);
            }
            else
            {
                dividend = abs(dividend);
                divisor = abs(divisor);
            }

        }
        else if (dividend<0 || divisor<0)
        {
            if (dividend == INT_MIN)return INT_MIN / divisor;
            if (divisor == INT_MIN)return 0;
            dividend = abs(dividend);
            divisor = abs(divisor);
            sign = -1;
        }
        else
        {
            if (divisor == INT_MAX)return 0;
        }
        return sign * (dividend / divisor);

    }
};