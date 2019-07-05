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

/*���������ab�������������״̬00��01��10��ʮλ�͸�λ���տ�ʼ��ʱ��a��b����0��
����ʱ��������1��ʱ��a����Ϊ1��b����Ϊ0������01��״̬���ٴ�����1��ʱ��a����Ϊ0��
b����Ϊ1������10��״̬���ٴ�����1��ʱ��b����Ϊ0��a����Ϊ0������00��״̬���൱�������ˣ�
���Ľ��������a�С�����������ķ������̣�����д���������£�*/