/*Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.*/

/*Runtime: 60 ms, faster than 65.20% of C++ online submissions for Count Primes.
Memory Usage: 8.7 MB, less than 60.67% of C++ online submissions for Count Primes.*/

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)return 0;
        vector<bool> isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        for (int i = 2; i*i<n; ++i)
        {
            if (!isPrime[i])continue;
            for (int j = i * i; j<n; j += i)
            {
                isPrime[j] = false;
            }
        }
        int res = 0;
        for (const auto& p : isPrime)
        {
            if (p)res++;
        }
        return res;

    }
};