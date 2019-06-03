/*Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.*/

/*Runtime: 20 ms, faster than 71.88% of C++ online submissions for Sort Characters By Frequency.
Memory Usage: 11 MB, less than 61.76% of C++ online submissions for Sort Characters By Frequency.*/

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> mymap;
        for (auto&& c : s)mymap[c]++;
        vector<pair<char, int>> v;
        for (auto&& pair : mymap)v.push_back(pair);
        sort(v.begin(), v.end(), [&](const auto& l, const auto& r)->
            bool {return l.second > r.second; });
        string res;
        for (const auto& p : v)
        {
            auto i = p.second;
            auto c = p.first;
            while (i-->0)res += c;
        }
        return res;
    }
};