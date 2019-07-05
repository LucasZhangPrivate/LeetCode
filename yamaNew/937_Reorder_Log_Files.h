/*You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: ["a1 9 2 3 1","g1 act car","zo4 4 7","ab1 off key dog","a8 act zoo"]
Output: ["g1 act car","a8 act zoo","ab1 off key dog","a1 9 2 3 1","zo4 4 7"]
 

Note:

0 <= logs.length <= 100
3 <= logs[i].length <= 100
logs[i] is guaranteed to have an identifier, and a word after the identifier.*/

/*Runtime: 16 ms, faster than 82.01% of C++ online submissions for Reorder Log Files.
Memory Usage: 13.7 MB, less than 64.24% of C++ online submissions for Reorder Log Files.*/

class Solution {
public:
    struct Node
    {
        int index;
        string log;
        string id;
        Node(int i, string l, string iD) :index(i), log(l), id(iD) {};
    };

    Node getLog(int index, string s)
    {
        auto i = s.find_first_of(' ');
        auto j = s.find_first_not_of(' ', i);
        auto id = s.substr(0, i);
        auto log = s.substr(j);

        return { index, log, id };
    }


    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<Node> help;
        vector<string> num;
        vector<string> al;
        for (int i = 0; i<logs.size(); ++i)
        {
            auto temp = getLog(i, logs[i]);
            if (temp.log[0] >= '0' && temp.log[0] <= '9')
            {
                num.push_back(logs[i]);
            }
            else
            {
                help.push_back({ temp });
            }
        }
        sort(help.begin(), help.end(), [](const auto& l, const auto& r) {
            if (l.log == r.log) return l.id<r.id;
            return l.log<r.log;
        });
        for (const auto& p : help)
        {
            al.push_back(logs[p.index]);
        }
        al.insert(al.end(), num.begin(), num.end());
        return al;
    }
};