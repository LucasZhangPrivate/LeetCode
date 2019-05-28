/*Given a string containing only digits, restore it by returning all possible valid IP address combinations.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]*/

/*Runtime: 4 ms, faster than 94.20% of C++ online submissions for Restore IP Addresses.
Memory Usage: 8.9 MB, less than 23.99% of C++ online submissions for Restore IP Addresses.*/

class Solution {
public:
    void store(vector<string>& res, int start, string s, string temp, int pot)
    {
        if (pot == 4 || start == s.size())
        {
            if (pot == 4 && start == s.size())
            {
                temp.pop_back();
                res.push_back(temp);
            }
            return;
        }

        string cur;
        for (int i = start; i <= start + 2; ++i)
        {
            cur += s[i];
            auto n = atoi(cur.c_str());
            if (n <= 255)
            {
                store(res, i + 1, s, temp + cur + '.', pot + 1);
            }
            else return;
            if (n == 0) return;
        }
    }


    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string temp;
        store(res, 0, s, temp, 0);
        return res;
    }
};