/*Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

Example:

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
Note:  

1 is typically treated as an ugly number.
n does not exceed 1690.*/

class Solution {
public:
    int nthUglyNumber(int n) {
        int n2 = 0;
        int n3 = 0;
        int n5 = 0;
        vector<int> res;
        res.push_back(1);
        while (res.size() < n)
        {
            int v2 = res[n2] * 2;
            int v3 = res[n3] * 3;
            int v5 = res[n5] * 5;
            int min = std::min(v2, std::min(v3, v5));
            if (min == v2)n2++;
            if (min == v3)n3++;
            if (min == v5)n5++;
            res.push_back(min);
        }
        return res.back();
    }
};