/*Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Example 2:

Input: [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.*/

/*Runtime: 4 ms, faster than 80.09% of C++ online submissions for Plus One.
Memory Usage: 8.4 MB, less than 79.88% of C++ online submissions for Plus One.*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        int carry = 1;
        while (i >= 0 && carry>0)
        {
            int sum = carry + digits[i];
            digits[i] = sum % 10;
            carry = sum / 10;
            i--;
        }
        if (carry>0 && i < 0)
        {
            digits.insert(digits.begin(), 1);
        }

        return digits;
    }
};