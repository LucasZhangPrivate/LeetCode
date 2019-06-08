/*Implement pow(x, n), which calculates x raised to the power n (xn).

Example 1:

Input: 2.00000, 10
Output: 1024.00000
Example 2:

Input: 2.10000, 3
Output: 9.26100
Example 3:

Input: 2.00000, -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
Note:

-100.0 < x < 100.0
n is a 32-bit signed integer, within the range [−231, 231 − 1]*/

/*Runtime: 4 ms, faster than 88.29% of C++ online submissions for Pow(x, n).
Memory Usage: 8.4 MB, less than 73.83% of C++ online submissions for Pow(x, n).*/

class Solution {
public:
    double myPow(double x, int n) {
        long N = n;
        if (n<0)return powx(1.0 / x, -N);
        else return powx(x, N);
    }
private:
    double powx(double x, long n)
    {
        if (n == 0)return 1;
        double result = 1;
        while (n>0)
        {
            if (n % 2 == 1)
            {
                result *= x;
                n--;
            }
            else {
                x *= x;
                n /= 2;
            }
        }
        return result;
    }
};