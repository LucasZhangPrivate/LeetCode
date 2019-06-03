/*Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:

Input: 
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation: 
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.
 

Example 2:

Input: 
nums = [1, 2, 3]
Output: -1
Explanation: 
There is no index that satisfies the conditions in the problem statement.*/

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int size = nums.size();
        //if(size<3)return -1;
        vector<int> left(size + 1, 0);
        left[0] = 0;
        vector<int> right(size + 1, 0);
        right[size] = 0;
        for (int i = 0; i<size; ++i)
        {
            left[i + 1] = nums[i] + left[i];
        }
        for (int i = size - 1; i >= 0; --i)
        {
            right[i] = nums[i] + right[i + 1];
        }
        for (int i = 0; i<size; ++i)
        {
            if (left[i] == right[i + 1])return i;
        }
        return -1;
    }
};

//Good solution
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for (const auto& n : nums)sum += n;
        int left = 0;
        for (int i = 0; i<nums.size(); ++i)
        {
            if (left == sum - left - nums[i])return i;
            left += nums[i];
        }
        return -1;
    }
};
