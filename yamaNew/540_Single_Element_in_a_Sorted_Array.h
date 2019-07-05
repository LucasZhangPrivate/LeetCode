/*Given a sorted array consisting of only integers where every element appears exactly twice except for one element which appears exactly once. Find this single element that appears only once.

 

Example 1:

Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: [3,3,7,7,10,11,11]
Output: 10
 

Note: Your solution should run in O(log n) time and O(1) space.*/

/*Runtime: 12 ms, faster than 43.32% of C++ online submissions for Single Element in a Sorted Array.
Memory Usage: 9.5 MB, less than 9.33% of C++ online submissions for Single Element in a Sorted Array.*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int res = nums[0];
        for (int i = 1; i<nums.size(); ++i)
        {
            res ^= nums[i];
        }
        return res;
    }
};

/*Runtime: 8 ms, faster than 98.04% of C++ online submissions for Single Element in a Sorted Array.
Memory Usage: 9.5 MB, less than 8.09% of C++ online submissions for Single Element in a Sorted Array.*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i<j)
        {
            int mid = (i + j) / 2;
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])return nums[mid];
            else if (nums[mid] == nums[mid - 1])
            {
                if ((mid - i) % 2 == 1)i = mid + 1;
                else j = mid;
            }
            else
            {
                if ((j - mid) % 2 == 1)j = mid - 1;
                else i = mid;
            }
        }
        return nums[i];
    }
};