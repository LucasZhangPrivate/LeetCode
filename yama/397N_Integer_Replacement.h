/*Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Integer Replacement.
Memory Usage: 10.4 MB, less than 19.44% of C++ online submissions for Integer Replacement.*/

class Solution {
public:
    unordered_map<long, long> mp;
    int help(long n)
    {
        if (n == 1)return 0;
        if (mp.count(n))return mp[n];
        if (n % 2 == 0)return 1 + help(n >> 1);
        else mp[n] = 1 + min(help(n - 1), help(n + 1));
        return mp[n];
    }
    int integerReplacement(int n) {
        return help(n);
    }
};