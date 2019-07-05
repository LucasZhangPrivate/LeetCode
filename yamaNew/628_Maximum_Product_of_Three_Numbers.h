/*Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6
 

Example 2:

Input: [1,2,3,4]
Output: 24
 

Note:

The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.*/

/*Runtime: 68 ms, faster than 47.96% of C++ online submissions for Maximum Product of Three Numbers.
Memory Usage: 10.8 MB, less than 82.80% of C++ online submissions for Maximum Product of Three Numbers.*/

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int i = 0;
        int j = nums.size() - 1;
        return max(nums[i] * nums[i + 1] * nums[i + 2], nums[j] * nums[j - 1] * nums[i]);
    }
};