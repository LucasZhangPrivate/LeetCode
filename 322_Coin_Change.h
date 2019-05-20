/*You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:

Input: coins = [1, 2, 5], amount = 11
Output: 3 
Explanation: 11 = 5 + 5 + 1
Example 2:

Input: coins = [2], amount = 3
Output: -1
Note:
You may assume that you have an infinite number of each kind of coin.*/

/*Runtime: 60 ms, faster than 44.83% of C++ online submissions for Coin Change.
Memory Usage: 12.5 MB, less than 75.82% of C++ online submissions for Coin Change.*/


///之前一直没想明白的dp解决此类问题，突然就清楚了，很奇怪
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        vector<int> nums(amount + 1, 0);
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j< coins.size(); ++j)
            {
                if (coins[j] == i)
                {
                    nums[i] = 1;
                }
                else if (coins[j]< i)
                {
                    if (nums[i - coins[j]] != 0)
                    {
                        nums[i] = nums[i] == 0 ? nums[i - coins[j]] + 1 :
                            min(nums[i], nums[i - coins[j]] + 1);
                    }
                }
            }
        }
        return nums[amount] == 0 ? -1 : nums[amount];
    }
};