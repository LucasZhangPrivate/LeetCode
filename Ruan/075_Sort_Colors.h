/*Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

Example:

Input: [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Follow up:

A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
Could you come up with a one-pass algorithm using only constant space?*/

/*Runtime: 4 ms, faster than 93.59% of C++ online submissions for Sort Colors.
Memory Usage: 8.7 MB, less than 8.02% of C++ online submissions for Sort Colors.*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i <= j)   //如果i<j的话下面必须再加一句注释掉的内容
        {
            if (nums[j] == 0)
            {
                swap(nums[i++], nums[j]);
            }
            else {
                j--;
            }
        }
        // if(nums[i]==0)i++;    
        j = nums.size() - 1;
        while (i<j)
        {
            if (nums[j] == 1)
            {
                swap(nums[i++], nums[j]);
            }
            else {
                j--;
            }
        }
    }
};

/*Runtime: 4 ms, faster than 93.59% of C++ online submissions for Sort Colors.
Memory Usage: 8.8 MB, less than 5.24% of C++ online submissions for Sort Colors.*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int tail_red = 0;
        int head_blue = nums.size() - 1;
        int cur = 0;
        while (cur <= head_blue) {
            if (nums[cur] == 0) {
                swap(nums[tail_red], nums[cur]);
                tail_red++;
                cur++;   //this part is important，the number before cur only 1
            }
            else if (nums[cur] == 2) {
                swap(nums[head_blue], nums[cur]);
                head_blue = head_blue - 1;
            }
            else
                cur++;
        }
    }
};