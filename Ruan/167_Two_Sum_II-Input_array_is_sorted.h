/*Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.*/

/*Runtime: 4 ms, faster than 99.55% of C++ online submissions for Two Sum II - Input array is sorted.
Memory Usage: 9.4 MB, less than 78.63% of C++ online submissions for Two Sum II - Input array is sorted.*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target)
                return { low + 1, high + 1 };
            else if (sum < target)
                ++low;
            else
                --high;
        }
        return { -1, -1 };
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> map;
        vector<int> res;
        for (int i = 0; i< numbers.size(); ++i)
        {
            if (map.find(target - numbers[i]) != map.end())
            {
                res.push_back(map[target - numbers[i]]);
                res.push_back(i + 1);
                break;
            }
            else map[numbers[i]] = i + 1;
        }
        return res;
    }
};