/*You are given two arrays (without duplicates) nums1 and nums2 where nums1¡¯s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.*/

/*Runtime: 12 ms, faster than 81.00% of C++ online submissions for Next Greater Element I.
Memory Usage: 9.4 MB, less than 42.06% of C++ online submissions for Next Greater Element I.*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> mp;
        for (int i = nums2.size() - 1; i >= 0; i--)
        {
            while (!stk.empty() && stk.top()<nums2[i])
            {
                stk.pop();
            }
            if (!stk.empty())
            {
                mp[nums2[i]] = stk.top();
            }
            stk.push(nums2[i]);
        }
        for (int i = 0; i<nums1.size(); ++i)
        {
            if (mp.count(nums1[i]))nums1[i] = mp[nums1[i]];
            else nums1[i] = -1;
        }
        return nums1;
    }
};