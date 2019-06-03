/*Given an array consists of non-negative integers, your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
Example 1:
Input: [2,2,3,4]
Output: 3
Explanation:
Valid combinations are: 
2,3,4 (using the first 2)
2,3,4 (using the second 2)
2,2,3
Note:
The length of the given array won't exceed 1000.
The integers in the given array are in the range of [0, 1000].*/

//我用的是递归，倒数第二个case超时
class Solution {
public:
    bool valid(int a, int b, int c)
    {
        if (a == 0 || b == 0 || c == 0)return false;
        auto m = max(max(a, b), c);
        if (a + b + c - m <= m)return false;
        else return true;
    }
    void help(vector<int>& check, vector<int>& nums, int idx, int& res)
    {
        if (check.size() == 3)
        {
            if (valid(check[0], check[1], check[2]))res++;
            return;
        }
        if (idx == nums.size())return;
        for (int i = idx; i<nums.size(); ++i)
        {
            check.push_back(nums[i]);
            help(check, nums, i + 1, res);
            check.pop_back();
        }
    }


    int triangleNumber(vector<int>& nums) {
        int res = 0;
        vector<int> check;
        help(check, nums, 0, res);
        return res;
    }
};

/*Runtime: 436 ms, faster than 12.06% of C++ online submissions for Valid Triangle Number.
Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Valid Triangle Number.*/
//排序后指针遍历，通过测试，但是速度不快
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        int j = nums.size() - 1;
        while (j >= 2)
        {
            int i = j - 1;
            int z = 0;
            while (i>z)
            {
                while (i>z&&nums[i] + nums[z]>nums[j])
                {
                    sum++;
                    i--;
                }
                z++;
                i = j - 1;
            }
            j--;
        }
        return sum;
    }
};
/*Runtime: 16 ms, faster than 91.99% of C++ online submissions for Valid Triangle Number.
Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Valid Triangle Number.*/
//这个想法很不错
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int ans = 0, sum;
        for (int i = nums.size() - 1; i > 1; i--) {
            int l = 0, r = i - 1;
            while (l < r) {
                sum = nums[l] + nums[r];
                if (sum > nums[i]) {
                    ans += r - l;  //这里是比较巧妙的一个地方，直接把范围拿出来省的一个一个的试
                    r--;
                }
                else l++;
            }
        }
        return ans;
    }
};