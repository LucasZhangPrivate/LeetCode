/*You are given coins of different denominations and a total amount of money. Write a function to compute the number of combinations that make up that amount. You may assume that you have infinite number of each kind of coin.*/


//µÝ¹é³¬Ê±
class Solution {
public:
    void cal(int& res, vector<int>& coins, int amount, int idx)
    {
        if (amount == 0)
        {
            res++;
            return;
        }
        if (amount < 0)return;
        for (int i = idx; i < coins.size(); ++i)
        {
            cal(res, coins, amount - coins[i], i);
        }


    }


    int change(int amount, vector<int>& coins) {
        if (amount == 0) return 1;
        int res = 0;
        cal(res, coins, amount, 0);
        return res;
    }
};


/*Runtime: 8 ms, faster than 98.14% of C++ online submissions for Coin Change 2.
Memory Usage: 8.8 MB, less than 84.31% of C++ online submissions for Coin Change 2.*/

//DP´ó·¨
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for (int i = 0; i<coins.size(); ++i) {
            for (int j = 1; j <= amount; ++j) {
                if (coins[i] <= j) {
                    dp[j] += dp[j - coins[i]];
                }
            }
        }
        return dp[amount];
    }
};