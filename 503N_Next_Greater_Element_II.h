/*Given a circular array (the next element of the last element is the first element of the array), print the Next Greater Number for every element. The Next Greater Number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, output -1 for this number.

Example 1:
Input: [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number; 
The second 1's next greater number needs to search circularly, which is also 2.*/

/*Runtime: 96 ms, faster than 57.59% of C++ online submissions for Next Greater Element II.
Memory Usage: 12.7 MB, less than 99.00% of C++ online submissions for Next Greater Element II.*/

//参考别人的，这个有点意思，可以作为这一类题的解法，循环两次
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res(nums.size(), -1);
        stack<int> stk;
        for (int i = 2 * nums.size() - 1; i >= 0; --i)
        {
            while (!stk.empty() && nums[i%nums.size()] >= nums[stk.top()])stk.pop();
            res[i%nums.size()] = stk.empty() ? -1 : nums[stk.top()];
            stk.push(i%nums.size());
        }
        return res;
    }
};