/*Given two integers A and B, return any string S such that:

S has length A + B and contains exactly A 'a' letters, and exactly B 'b' letters;
The substring 'aaa' does not occur in S;
The substring 'bbb' does not occur in S.
 

Example 1:

Input: A = 1, B = 2
Output: "abb"
Explanation: "abb", "bab" and "bba" are all correct answers.
Example 2:

Input: A = 4, B = 1
Output: "aabaa"*/

class Solution {
public:
    string strWithout3a3b(int A, int B) {
        string result;
        int adjustA = 0;
        int adjustB = 0;
        while (A>0 || B>0)
        {
            if (A > B)
            {
                if (adjustA < 2)
                {
                    A--;
                    adjustA++;
                    adjustB = 0;
                    result += 'a';
                }
                else
                {
                    B--;
                    adjustB++;
                    result += 'b';
                    adjustA = 0;
                }
            }
            else
            {
                if (adjustB <2)
                {
                    B--;
                    adjustB++;
                    adjustA = 0;
                    result += 'b';
                }
                else
                {
                    A--;
                    adjustA++;
                    result += 'a';
                    adjustB = 0;
                }
            }

        }
        return result;
    }