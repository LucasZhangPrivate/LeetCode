/*Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99*/

/*Runtime: 12 ms, faster than 83.45% of C++ online submissions for Single Number II.
Memory Usage: 9.8 MB, less than 24.07% of C++ online submissions for Single Number II.*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        int b = 0;
        for (const auto& n : nums)
        {
            a = a ^ n&~b;
            b = b ^ n&~a;
        }
        return a;
    }
};

/*我们这里的ab就是上面的三种状态00，01，10的十位和各位，刚开始的时候，a和b都是0，
当此时遇到数字1的时候，a更新为1，b更新为0，就是01的状态；再次遇到1的时候，a更新为0，
b更新为1，就是10的状态；再次遇到1的时候，b更新为0，a更新为0，就是00的状态，相当于重置了；
最后的结果保存在a中。明白了上面的分析过程，就能写出代码如下；*/