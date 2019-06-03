/*Given an integer n, return the number of trailing zeroes in n!.

Example 1:

Input: 3
Output: 0
Explanation: 3! = 6, no trailing zero.
Example 2:

Input: 5
Output: 1
Explanation: 5! = 120, one trailing zero.
Note: Your solution should be in logarithmic time complexity.*/

/*Runtime: 4 ms, faster than 92.28% of C++ online submissions for Factorial Trailing Zeroes.
Memory Usage: 8.3 MB, less than 61.28% of C++ online submissions for Factorial Trailing Zeroes.*/

//就是记住了方法就行了，没啥好说的
class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n >= 5)
        {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};