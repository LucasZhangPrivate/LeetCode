/*We are given two strings, A and B.

A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.

Example 1:
Input: A = 'abcde', B = 'cdeab'
Output: true

Example 2:
Input: A = 'abcde', B = 'abced'
Output: false*/

class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size())return false;
        if (A == B) return true;
        char c = A[A.size() - 1];
        int i = 0, j = 0;
        while (i<A.size())
        {
            j = B.find_first_of(c, i);
            if (j == string::npos)break;
            string firstB = B.substr(0, j + 1);
            string secondB = B.substr(j + 1);
            if (A.substr(0, secondB.size()) == secondB &&
                A.substr(secondB.size()) == firstB)return true;
            i = j + 1;
        }
        return false;
    }
};