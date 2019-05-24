/*Given an array, rotate the array to the right by k steps, where k is non-negative.

Example 1:

Input: [1,2,3,4,5,6,7] and k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: [-1,-100,3,99] and k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
Note:

Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
Could you do it in-place with O(1) extra space?*/

/*Runtime: 16 ms, faster than 97.61% of C++ online submissions for Rotate Array.
Memory Usage: 9.6 MB, less than 50.06% of C++ online submissions for Rotate Array.*/


//剛做的，圖省事
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int n = nums.size();
        nums.insert(nums.begin(), nums.begin() + n - k, nums.end());
        nums.erase(nums.begin() + n, nums.end());
    }
};



//四年前做的，用的O（1）空間
class Solution {
public:
    void rotate(vector<int>& nums, int k)
    {
        if (k == 0 || nums.size() <= 1 || k == nums.size())return;
        int index = 0, indexM = 0;
        int temp1 = nums[0], temp2 = nums[0];
        int n = nums.size();
        for (int i = 0; i<n; ++i)
        {
            temp1 = temp2;
            index = (index + k) % n;
            temp2 = nums[index];
            nums[index] = temp1;
            if (index == indexM)
            {
                index = ++indexM;
                temp2 = nums[index];
            }
        }
    }
};