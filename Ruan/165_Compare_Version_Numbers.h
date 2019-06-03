/*Compare two version numbers version1 and version2.
If version1 > version2 return 1; if version1 < version2 return -1;otherwise return 0.

You may assume that the version strings are non-empty and contain only digits and the . character.

The . character does not represent a decimal point and is used to separate number sequences.

For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.

You may assume the default revision number for each level of a version number to be 0. For example, version number 3.4 has a revision number of 3 and 4 for its first and second level revision number. Its third and fourth level revision number are both 0.

 

Example 1:

Input: version1 = "0.1", version2 = "1.1"
Output: -1
Example 2:

Input: version1 = "1.0.1", version2 = "1"
Output: 1
Example 3:

Input: version1 = "7.5.2.4", version2 = "7.5.3"
Output: -1
Example 4:

Input: version1 = "1.01", version2 = "1.001"
Output: 0
Explanation: Ignoring leading zeroes, both “01” and “001" represent the same number “1”
Example 5:

Input: version1 = "1.0", version2 = "1.0.0"
Output: 0
Explanation: The first version number does not have a third level revision number, which means its third level revision number is default to "0"
 

Note:

Version strings are composed of numeric strings separated by dots . and this numeric strings may have leading zeroes.
Version strings do not start or end with dots, and they will not be two consecutive dots.*/

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Compare Version Numbers.
Memory Usage: 8.6 MB, less than 22.17% of C++ online submissions for Compare Version Numbers.*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0;
        int j = 0;
        int res = 0;
        while (i<version1.size() || j<version2.size())
        {
            int x = 0;
            int y = 0;
            if (i<version1.size())
            {
                auto ii = version1.find_first_of('.', i);
                if (ii != string::npos)
                {
                    x = stoi(version1.substr(i, ii - i).c_str());
                    i = ii + 1;
                }
                else
                {
                    x = stoi(version1.substr(i).c_str());
                    i = ii;
                }
            }

            if (j<version2.size())
            {
                auto jj = version2.find_first_of('.', j);
                if (jj != string::npos)
                {
                    y = stoi(version2.substr(j, jj - j).c_str());
                    j = jj + 1;
                }
                else
                {
                    y = stoi(version2.substr(j).c_str());
                    j = jj;
                }
            }

            if (x>y)
            {
                res = 1;
                break;
            }
            else if (x<y)
            {
                res = -1;
                break;
            }
        }
        return res;
    }
};



//利用 atoi的特性，只转换合法的字符为整数.
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int res = 0;
        while (!version1.empty() || !version2.empty())
        {
            int a = atoi(version1.c_str());
            int b = atoi(version2.c_str());
            if (a > b)
            {
                res = 1;
                break;
            }
            if (a<b)
            {
                res = -1;
                break;
            }
            auto i = version1.find_first_of('.');
            if (i != string::npos)version1 = version1.substr(i + 1);
            else version1.clear();

            auto j = version2.find_first_of('.');
            if (j != string::npos)version2 = version2.substr(j + 1);
            else version2.clear();
        }
        return res;
    }
};