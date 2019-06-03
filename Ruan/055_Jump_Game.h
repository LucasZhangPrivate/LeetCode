/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

Example 1:

Input: [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum
             jump length is 0, which makes it impossible to reach the last index.*/

/*Runtime: 12 ms, faster than 92.36% of C++ online submissions for Jump Game.
Memory Usage: 10.1 MB, less than 58.71% of C++ online submissions for Jump Game.*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1)return true;
        int i = 0, j = 0;
        while (j<nums.size())
        {
            auto temp = j;
            for (int z = i; z <= j; ++z)
            {
                temp = max(temp, nums[z] + z);
                if (temp >= nums.size() - 1)return true;
            }
            if (temp == j)break;
            i = j;
            j = temp;
        }
        return false;
    }
};

//Ö®Ç°µÄ
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if (nums.size()<2)return true;
        int l = 1;
        int r = nums[0];
        while (l <= r)
        {
            if (r >= nums.size() - 1)return true;
            int maxr = 0;
            for (int i = l; i <= r; i++)
            {
                if (nums[i] + i>maxr)maxr = nums[i] + i;
            }
            l = r + 1;
            r = maxr;
        }
        return false;
    }
};

/*bool canJump(int A[], int n) {
int last=n-1,i,j;
for(i=n-2;i>=0;i--){
if(i+A[i]>=last)last=i;
}
return last<=0;
}*/