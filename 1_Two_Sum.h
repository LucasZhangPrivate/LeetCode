/*Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].*/

/*Runtime: 8 ms, faster than 98.29% of C++ online submissions for Two Sum.
Memory Usage: 10.2 MB, less than 35.87% of C++ online submissions for Two Sum.
Next challenges:*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        for (int i = 0; i< nums.size(); ++i)
        {
            if (map.find(target - nums[i]) != map.end())
            {
                res.push_back(map[target - nums[i]]);
                res.push_back(i);
                break;
            }
            else map[nums[i]] = i;
        }
        return res;
    }
};