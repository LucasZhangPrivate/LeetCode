/*A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true if and only if queries[i] matches the pattern.

 

Example 1:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
Example 2:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: 
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
Example 3:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: 
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
 

Note:

1 <= queries.length <= 100
1 <= queries[i].length <= 100
1 <= pattern.length <= 100
All strings consists only of lower and upper case English letters.*/

/*Runtime: 4 ms, faster than 94.43% of C++ online submissions for Camelcase Matching.
Memory Usage: 8.7 MB, less than 10.25% of C++ online submissions for Camelcase Matching.*/

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res;
        int p = 0;
        for (const auto& s : queries)
        {
            p = 0;
            bool pass = true;
            for (int i = 0; i<s.size(); ++i)
            {
                if (s[i] >= 'a'&&s[i] <= 'z')
                {
                    if (p<pattern.size() && pattern[p] == s[i])p++;
                }
                else
                {
                    if (p >= pattern.size() || pattern[p] != s[i])
                    {
                        pass = false;
                        break;
                    }
                    p++;
                }
            }
            if (p != pattern.size())pass = false;  //注意这里，要求pattern必须都用上不能有剩余
            res.push_back(pass);

        }
        return res;

    }
};