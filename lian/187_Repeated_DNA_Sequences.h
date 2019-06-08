/*All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.

Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.

Example:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"

Output: ["AAAAACCCCC", "CCCCCAAAAA"]*/

/*Runtime: 44 ms, faster than 81.67% of C++ online submissions for Repeated DNA Sequences.
Memory Usage: 24.7 MB, less than 5.03% of C++ online submissions for Repeated DNA Sequences.*/

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {

        unordered_map<string, int> map;
        vector<string> res;
        for (int i = 0; i + 10 <= s.size(); ++i)
        {
            string x = s.substr(i, 10);
            map[x]++;
            if (map[x] == 2)
            {
                res.push_back(x);
            }
        }
        return res;
    }
};