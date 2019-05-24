/*Write a function that takes an unsigned integer and return the number of '1' bits it has (also known as the Hamming weight).

 

Example 1:

Input: 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.
Example 2:

Input: 00000000000000000000000010000000
Output: 1
Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.
Example 3:

Input: 11111111111111111111111111111101
Output: 31
Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.*/

/*Runtime: 4 ms, faster than 95.35% of C++ online submissions for Number of 1 Bits.
Memory Usage: 8.4 MB, less than 5.03% of C++ online submissions for Number of 1 Bits.*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0)
        {
            auto m = n << 31;
            m = m >> 31;
            if (m == 1)res++;
            n = n >> 1;
        }
        return res;
    }
};

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Number of 1 Bits.
Memory Usage: 8.3 MB, less than 9.61% of C++ online submissions for Number of 1 Bits.*/
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while (n != 0)
        {
            if (n & 1)res++;
            n >>= 1;
        }
        return res;
    }
};