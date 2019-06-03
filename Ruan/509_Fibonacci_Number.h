/*The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.*/
/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Fibonacci Number.
Memory Usage: 8.5 MB, less than 43.61% of C++ online submissions for Fibonacci Number.*/
//ÔüÔüÌâ
class Solution {
public:
    int fib(int N) {
        if (N == 0)return 0;
        if (N == 1)return 1;
        int a = 0, b = 1;
        int c;
        while (N-->1)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};