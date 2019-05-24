/*Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4*/

/*Runtime: 16 ms, faster than 63.25% of C++ online submissions for Kth Largest Element in an Array.
Memory Usage: 9.4 MB, less than 53.12% of C++ online submissions for Kth Largest Element in an Array.*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> q;
        for (const auto& n : nums)
        {
            if (q.size() == k + 1)
            {
                q.pop();
            }
            q.push(n);
        }
        if (q.size()>k)q.pop();
        return q.top();
    }
};