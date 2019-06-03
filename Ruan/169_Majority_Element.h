/*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2*/

/*Runtime: 20 ms, faster than 94.80% of C++ online submissions for Majority Element.
Memory Usage: 11 MB, less than 81.06% of C++ online submissions for Majority Element.*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = 0;
        int count = 0;
        for (const auto& n : nums)
        {
            if (count == 0)
            {
                maj = n;
                count++;
            }
            else if (n == maj)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return maj;
    }
};