/*Given an array of integers where 1 ¡Ü a[i] ¡Ü n (n = size of array), some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]*/

/*Runtime: 128 ms, faster than 31.30% of C++ online submissions for Find All Numbers Disappeared in an Array.
Memory Usage: 14.9 MB, less than 99.49% of C++ online submissions for Find All Numbers Disappeared in an Array.*/

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i< nums.size(); ++i)
        {
            while (nums[i] != i + 1)
            {
                if (nums[i] == nums[nums[i] - 1])break;
                auto keep = nums[nums[i] - 1];
                nums[nums[i] - 1] = nums[i];
                nums[i] = keep;
            }
        }
        vector<int> res;
        for (int i = 0; i<nums.size(); ++i)
        {
            if (nums[i] != i + 1)res.push_back(i + 1);
        }
        return res;
    }
};