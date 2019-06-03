/*Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container and n is at least 2.

 



The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

 

Example:

Input: [1,8,6,2,5,4,8,3,7]
Output: 49*/

/*Runtime: 16 ms, faster than 98.06% of C++ online submissions for Container With Most Water.
Memory Usage: 10 MB, less than 40.66% of C++ online submissions for Container With Most Water.*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = INT_MIN;
        int i = 0;
        int j = height.size() - 1;
        while (i<j)
        {
            res = max(res, (j - i)*min(height[i], height[j]));
            if (height[i]<height[j])i++;
            else j--;
        }
        return res;
    }
};