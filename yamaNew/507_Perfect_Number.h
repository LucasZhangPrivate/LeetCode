/*We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14*/

/*Runtime: 4 ms, faster than 85.14% of C++ online submissions for Perfect Number.
Memory Usage: 8.1 MB, less than 53.05% of C++ online submissions for Perfect Number.*/

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1)return false;
        int sum = 1;
        for (int i = 2; i*i<num; ++i)
        {
            if (num%i == 0)
            {
                sum += i;
                sum += num / i;
            }
            if (sum>num)return false;
        }
        return sum == num;
    }
};