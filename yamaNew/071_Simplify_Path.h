/*Given an absolute path for a file (Unix-style), simplify it. Or in other words, convert it to the canonical path.

In a UNIX-style file system, a period . refers to the current directory. Furthermore, a double period .. moves the directory up a level. For more information, see: Absolute path vs relative path in Linux/Unix

Note that the returned canonical path must always begin with a slash /, and there must be only a single slash / between two directory names. The last directory name (if it exists) must not end with a trailing /. Also, the canonical path must be the shortest string representing the absolute path.

 

Example 1:

Input: "/home/"
Output: "/home"
Explanation: Note that there is no trailing slash after the last directory name.
Example 2:

Input: "/../"
Output: "/"
Explanation: Going one level up from the root directory is a no-op, as the root level is the highest level you can go.
Example 3:

Input: "/home//foo/"
Output: "/home/foo"
Explanation: In the canonical path, multiple consecutive slashes are replaced by a single one.
Example 4:

Input: "/a/./b/../../c/"
Output: "/c"
Example 5:

Input: "/a/../../b/../c//.//"
Output: "/c"
Example 6:

Input: "/a//b////c/d//././/.."
Output: "/a/b/c"*/

/*Runtime: 4 ms, faster than 98.60% of C++ online submissions for Simplify Path.
Memory Usage: 13.9 MB, less than 6.15% of C++ online submissions for Simplify Path.*/

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> p;
        int i = 0;
        while (i<path.size())
        {
            i = path.find_first_not_of('/', i);
            if (i == string::npos)break;
            auto j = path.find_first_of('/', i);
            string cur;
            if (j != string::npos)
            {
                cur = path.substr(i, j - i);
            }
            else
            {
                cur = path.substr(i);
            }
            if (!cur.empty())
            {
                if (cur == "..")
                {
                    if (!p.empty())p.pop_back();
                }
                else if (cur != ".")p.push_back(cur);
            }
            i = j;
        }
        string res;
        for (const auto& s : p)
        {
            res = res + "/" + s;
        }
        return res.empty() ? "/" : res;
    }
};