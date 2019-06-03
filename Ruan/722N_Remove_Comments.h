/**/



//不是自己做的，许多地方值得推敲
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        bool flag = false;
        vector<string> res;
        for (auto s : source) {
            string code = flag ? code : ""; // append code or new code based on the flag status 将block中内容整体去除，但是要链接前后剩下的string成为一个
            for (int i = 0; i<s.size(); ++i) {
                if (!flag && i < s.size() - 1 && s[i] == '/' && s[i + 1] == '*') { flag = true; ++i; } // if /* set the flag
                else if (!flag && i < s.size() - 1 && s[i] == '/' && s[i + 1] == '/') break; // if // all gone 
                else if (flag && i < s.size() - 1 && s[i] == '*' && s[i + 1] == '/') { flag = false; ++i; } // if flag is up and */
                else { if (!flag) code += s[i]; } // if no flag then add the char 
            }
            if (!flag && code != "") res.push_back(code); // if not inside /* */ and got some char then push it 
        }
        return res;
    }
};