/*You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
Note:

S and J will consist of letters and have length at most 50.
The characters in J are distinct.*/

/*Runtime: 4 ms, faster than 86.99% of C++ online submissions for Jewels and Stones.
Memory Usage: 8.7 MB, less than 44.09% of C++ online submissions for Jewels and Stones.*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_set<char> st(J.begin(), J.end());
        int res = 0;
        for (const auto& c : S)
        {
            if (st.count(c))res++;
        }
        return res;
    }
};