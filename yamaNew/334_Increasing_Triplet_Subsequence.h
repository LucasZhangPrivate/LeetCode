/*Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.

Formally the function should:

Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Note: Your algorithm should run in O(n) time complexity and O(1) space complexity.

Example 1:

Input: [1,2,3,4,5]
Output: true
Example 2:

Input: [5,4,3,2,1]
Output: false*/

/*Runtime: 144 ms, faster than 9.37% of C++ online submissions for Increasing Triplet Subsequence.
Memory Usage: 9.1 MB, less than 27.61% of C++ online submissions for Increasing Triplet Subsequence.*/

//虽然AC了，但是感觉这个解很菜
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size()<3) return false;
        vector<int> a(nums.size(), 1);
        for (int i = 1; i<nums.size(); ++i)
        {
            while (i<nums.size() && nums[i] == nums[i - 1])
            {
                a[i] = a[i - 1];
                i++;
            }
            if (i >= nums.size())break;
            for (int j = i - 1; j >= 0; --j)
            {
                if (nums[j]<nums[i])
                {
                    a[i] = max(a[i], a[j] + 1);
                    if (a[i] >= 3)return true;
                }
            }
        }
        return false;
    }
};

/*Runtime: 8 ms, faster than 80.72% of C++ online submissions for Increasing Triplet Subsequence.
Memory Usage: 8.9 MB, less than 68.50% of C++ online submissions for Increasing Triplet Subsequence.*/

//一个牛逼的解法
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX;
        int b = a;
        for (const auto& n : nums)
        {
            if (n <= a)a = n;
            else if (n <= b)b = n;
            else return true;
        }
        return false;
    }
};