/*Return all non - negative integers of length N such that the absolute difference between every two consecutive digits is K.

Note that every number in the answer must not have leading zeros except for the number 0 itself.For example, 01 has one leading zero and is invalid, but 0 is valid.

You may return the answer in any order.



Example 1:

Input: N = 3, K = 7
    Output : [181, 292, 707, 818, 929]
    Explanation : Note that 070 is not a valid number, because it has leading zeroes.
    Example 2 :

    Input : N = 2, K = 1
    Output : [10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98]


    Note :

    1 <= N <= 9
    0 <= K <= 9*/

/*Runtime: 24 ms, faster than 6.28% of C++ online submissions for Numbers With Same Consecutive Differences.
Memory Usage: 10.3 MB, less than 58.82% of C++ online submissions for Numbers With Same Consecutive Differences.*/

class Solution {
public:
    vector<int> getNext(int a, int K)
    {
        vector<int> result;
        if (K == 0)result.push_back(a);
        else
        {
            if ((a + K)<10)result.push_back(a + K);
            if ((a - K) >= 0)result.push_back(a - K);
        }
        return result;
    }

    void help(int N, int K, vector<int>& res, int ans, int cur)
    {
        ans = ans * 10 + cur;
        if (N == 0)
        {
            res.push_back(ans);
            return;
        }
        auto next = getNext(cur, K);
        for (auto n : next)
        {
            help(N - 1, K, res, ans, n);
        }
    }

    vector<int> numsSameConsecDiff(int N, int K)
    {
        vector<int> result;
        if (N == 1)
        {
            for (int i = 0; i<10; ++i) result.push_back(i);
            return result;
        }
        for (int i = 1; i<10; ++i)
        {
            auto next = getNext(i, K);
            for (auto n : next)
            {
                help(N - 2, K, result, i, n);
            }
        }
        return result;
    }
};