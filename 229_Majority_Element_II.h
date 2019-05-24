/*Given an integer array of size n, find all elements that appear more than ? n/3 ? times.

Note: The algorithm should run in linear time and in O(1) space.

Example 1:

Input: [3,2,3]
Output: [3]
Example 2:

Input: [1,1,1,3,3,2,2,2]
Output: [1,2]*/

/*Runtime: 12 ms, faster than 98.38% of C++ online submissions for Majority Element II.
Memory Usage: 10.8 MB, less than 8.87% of C++ online submissions for Majority Element II.*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int c1 = 0;
        int c2 = 0;
        int a, b;
        for (const auto& n : nums)
        {
            if (a == n)
            {
                c1++;
            }
            else if (b == n)
            {
                c2++;
            }
            else if (c1 == 0)
            {
                c1++;
                a = n;
            }
            else if (c2 == 0)
            {
                c2++;
                b = n;
            }
            else
            {
                c1--;
                c2--;
            }
        }
        c1 = 0;
        c2 = 0;
        for (const auto& n : nums)
        {
            if (n == a)c1++;
            else if (n == b)c2++;
        }
        vector<int> res;
        if (c1>nums.size() / 3)res.push_back(a);
        if (c2>nums.size() / 3)res.push_back(b);
        return res;
    }
};