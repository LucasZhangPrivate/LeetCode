/*Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

Example:

Input:  [1,2,1,3,2,5]
Output: [3,5]
Note:

The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?*/

/*Runtime: 16 ms, faster than 76.94% of C++ online submissions for Single Number III.
Memory Usage: 9.8 MB, less than 45.90% of C++ online submissions for Single Number III.*/

/*���������Ȱ�ԭ����ȫ�������������ô���ǻ�õ�һ�����֣������������������ͬ���������Ľ��������ȡ����������һλΪ ��1�� ��λ��
Ϊ�˷�������������� a &= -a ��ȡ�����Ҷ�Ϊ ��1�� ��λ��������˵���������β����İɡ�������Ŀ�е�������˵��������ǽ���ȫ�� '���' 
����������֪����ͬ�������� '���' �Ļ�Ϊ0����ô����1������2���������ˣ���ʣ3��5 '���' ��������ô���Ƕ����Ƶ� 11 �� 101 '���' ��
�õ�110��Ȼ�����ǽ��� a &= -a ���������ȱ为���ɣ��ڶ������и������ò������ʽ����������Ƿ��� +1����ô 110 �ķ����� 11...1001��
��ô��1���� 11...1010��Ȼ��� 110 ���룬�õ��� 10�����Ǵ����е� diff �������õ������ diff���Ϳ��Խ�ԭ�����Ϊ���������ˡ�Ϊɶ�أ�
�����밢�����������ͬ������ '���' ��ÿλ������0������ͬ������ '���' ��һ�����ж�Ӧλ��ͬ��һ��0һ��1������ '���' ��1��
����3��5�Ķ����� 11 �� 101������ӵ����߿����ʼ������ͬ�ľ��ǵڶ�λ����ô�����õڶ�λ����������ÿ���������룬���ݽ���Ĳ�ͬ��
һ�����԰�3��5���ֿ����������������������ǳɶԳ��֣��������ֿ���Ҳ�ǳɶԵģ����ն��� '���' ��0������3��5����Ӱ�졣
�ֱ�����С���е����ֶ�����������Ϳ��Եõ����ս����*/

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        diff &= -diff;
        vector<int> res(2, 0);
        for (auto &a : nums) {
            if (a & diff) res[0] ^= a;
            else res[1] ^= a;
        }
        return res;
    }
};