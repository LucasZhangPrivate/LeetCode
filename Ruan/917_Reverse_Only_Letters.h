/*Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.

 

Example 1:

Input: "ab-cd"
Output: "dc-ba"
Example 2:

Input: "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
Example 3:

Input: "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"*/

class Solution {
public:
    bool isLetter(const char& c)
    {
        return c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z';
    }

    string reverseOnlyLetters(string S) {
        string result;
        int j = S.size() - 1;
        for (int i = 0; i<S.size(); ++i)
        {
            if (isLetter(S[i]))
            {
                while (j >= 0 && !isLetter(S[j]))j--;
                result += S[j--];
            }
            else result += S[i];
        }
        return result;
    }
};