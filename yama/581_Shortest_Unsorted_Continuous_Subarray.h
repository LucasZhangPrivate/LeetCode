/*Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.

Example 1:
Input: [2, 6, 4, 8, 10, 9, 15]
Output: 5
Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
Note:
Then length of the input array is in range [1, 10,000].
The input array may contain duplicates, so ascending order here means <=.*/

/*Runtime: 48 ms, faster than 44.33% of C++ online submissions for Shortest Unsorted Continuous Subarray.
Memory Usage: 11.3 MB, less than 49.16% of C++ online submissions for Shortest Unsorted Continuous Subarray.*/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto com = nums;
        sort(com.begin(), com.end());
        int i = 0;
        int j = nums.size() - 1;
        while (i<nums.size() && com[i] == nums[i])i++;
        if (i == nums.size())return 0;
        while (j >= 0 && com[j] == nums[j])j--;
        return j - i + 1;
    }
};