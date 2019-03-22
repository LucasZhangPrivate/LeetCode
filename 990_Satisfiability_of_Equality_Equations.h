/*Given an array equations of strings that represent relationships between variables, each string equations[i] has length 4 and takes one of two different forms: "a==b" or "a!=b".  Here, a and b are lowercase letters (not necessarily different) that represent one-letter variable names.

Return true if and only if it is possible to assign integers to variable names so as to satisfy all the given equations.

 

Example 1:

Input: ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.  There is no way to assign the variables to satisfy both equations.
Example 2:

Input: ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
Example 3:

Input: ["a==b","b==c","a==c"]
Output: true
Example 4:

Input: ["a==b","b!=c","c==a"]
Output: false
Example 5:

Input: ["c==c","b==d","x!=z"]
Output: true*/


class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        vector<int> arr(26);
        for (int i = 0; i<26; ++i) arr[i] = i;
        for (auto&& s : equations) {
            if (s[1] == '=') {
                arr[find(arr, s[0] - 'a')] = find(arr, s[3] - 'a');
            }
        }
        for (auto&& s : equations) {
            if (s[1] == '!' && find(arr, s[0] - 'a') == find(arr, s[3] - 'a')) {
                return false;
            }
        }
        return true;
    }

    int find(vector<int>& arr, int x) {
        if (x != arr[x])arr[x] = find(arr, arr[x]);
        return arr[x];
    }
};