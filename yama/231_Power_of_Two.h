/*Given an integer, write a function to determine if it is a power of two.

Example 1:

Input: 1
Output: true 
Explanation: 20 = 1
Example 2:

Input: 16
Output: true
Explanation: 24 = 16
Example 3:

Input: 218
Output: false*/

/*Runtime: 4 ms, faster than 75.07% of C++ online submissions for Power of Two.
Memory Usage: 8 MB, less than 67.33% of C++ online submissions for Power of Two.*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        while (n>0)
        {
            if (n & 1)break;
            n >>= 1;
        }
        return n == 1;
    }
};

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Power of Two.
Memory Usage: 7.9 MB, less than 82.39% of C++ online submissions for Power of Two.*/
class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        return (n>0) && !(n&(n - 1));
    }
};