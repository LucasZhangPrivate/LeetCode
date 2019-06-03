/*Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.*/

/*Runtime: 12 ms, faster than 96.28% of C++ online submissions for Find the Duplicate Number.
Memory Usage: 10 MB, less than 30.60% of C++ online submissions for Find the Duplicate Number.*/

class Solution {
public:
    int findDuplicate(vector<int>& nums)

    {
        int n = nums.size() - 1;
        int low = 1;
        int high = n;
        int mid;
        while (low<high) {
            mid = (low + high) / 2;
            int count = 0;
            for (int num : nums) {
                if (num <= mid) count++;
            }
            if (count>mid) high = mid;
            else low = mid + 1;
        }
        return low;
    }
};





int n=nums.size()-1;
int low=1;
int high=n;
int mid;
while(low<high){
mid=(low+high)/2;
int count=0;
for(int num:nums){
if(num<=mid) count++;
}
if(count>mid) high=mid;
else low=mid+1;
}
return low;



int slow = 0;
int fast = 0;
int finder = 0;

while (true)
{
slow = nums[slow];
fast = nums[nums[fast]];

if (slow == fast)
break;
}
while (true)
{
slow = nums[slow];
finder = nums[finder];
if (slow == finder)
return slow;
}