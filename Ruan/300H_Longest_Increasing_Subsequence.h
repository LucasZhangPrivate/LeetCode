/*Given an unsorted array of integers, find the length of longest increasing subsequence.

Example:

Input: [10,9,2,5,3,7,101,18]
Output: 4 
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4. 
Note:

There may be more than one LIS combination, it is only necessary for you to return the length.
Your algorithm should run in O(n2) complexity.
Follow up: Could you improve it to O(n log n) time complexity?*/

/*Runtime: 4 ms, faster than 99.05% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 8.8 MB, less than 11.73% of C++ online submissions for Longest Increasing Subsequence.*/

///这个是以前做的，估计是参考别人的，方法很巧妙，而且时间很短，后面那个是这次做出来的，有点属于暴力破解
class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
        if (nums.size()<2)return nums.size();
        vector<int> v(nums.size());
        v[0] = nums[0];
        int j = 0, mark = 0;
        for (int i = 1; i<nums.size(); ++i)
        {
            if (nums[i]>v[mark])
            {
                v[++mark] = nums[i];
            }
            else
            {
                j = mark;
                while (j >= 0 && v[j] >= nums[i])
                {
                    --j;
                }
                v[++j] = nums[i];
            }
        }
        return mark + 1;

    }
};

/*Runtime: 40 ms, faster than 52.02% of C++ online submissions for Longest Increasing Subsequence.
Memory Usage: 8.9 MB, less than 7.34% of C++ online submissions for Longest Increasing Subsequence.*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> keep(nums.size(), 0);
        for (int i = 0; i< nums.size(); ++i)
        {
            int j = i - 1;
            while (j >= 0)
            {
                if (nums[j] < nums[i])
                {
                    keep[i] = max(keep[i], keep[j] + 1);
                }
                --j;
            }
            if (keep[i] == 0)keep[i] = 1;
        }
        int res = 0;
        for (const auto& n : keep)res = max(res, n);
        return res;
    }
};