/*Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.*/

/*Runtime: 4 ms, faster than 78.78% of C++ online submissions for Validate IP Address.
Memory Usage: 8.8 MB, less than 28.95% of C++ online submissions for Validate IP Address.*/

class Solution {
public:
    vector<string> split(string in, char mark)
    {
        vector<string> res;
        int i = 0;
        while (i<in.size())
        {
            auto j = in.find_first_of(mark, i);
            string temp;
            if (j == string::npos)
            {
                temp = in.substr(i);
                res.push_back(temp);
                break;
            }
            else
            {
                temp = in.substr(i, j - i);
            }
            res.push_back(temp);
            i = j + 1;
        }
        return res;
    }
    string validIPAddress(string IP) {
        string res = "Neither";
        if (IP.back() == '.' || IP.back() == ':')return res; //注意这个判断
        if (IP.find('.') != string::npos)
        {
            vector<string> temp = split(IP, '.');
            if (temp.size() != 4)return res;
            for (const auto& str : temp)
            {
                if (str.empty() || str.size()>1 && str[0] == '0' || str.size()>3)return res;
                if (str.find_first_not_of("0123456789") != string::npos)return res;
                if (atoi(str.c_str())>255)return res;
            }
            res = "IPv4";
        }
        else
        {
            vector<string> temp = split(IP, ':');
            if (temp.size() != 8)return res;
            for (const auto& str : temp)
            {
                if (str.empty() || str.size()>4)return res;
                if (str.find_first_not_of("0123456789abcdefABCDEF") != string::npos)return res; //学会这种用法
            }
            res = "IPv6";
        }
        return res;
    }
};