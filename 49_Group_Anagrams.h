/*Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.*/

/*Runtime: 36 ms, faster than 97.39% of C++ online submissions for Group Anagrams.
Memory Usage: 19 MB, less than 72.57% of C++ online submissions for Group Anagrams.*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mymap;
        for (const auto& str : strs)
        {
            auto temp = str;
            sort(temp.begin(), temp.end());
            mymap[temp].push_back(str);
        }
        vector<vector<string>> res;
        for (const auto& pair : mymap)
        {
            res.push_back(pair.second);
        }
        return res;
    }
};