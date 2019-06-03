/*Given a wordlist, we want to implement a spellchecker that converts a query word into a correct word.

For a given query word, the spell checker handles two categories of spelling mistakes:

Capitalization: If the query matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the case in the wordlist.
Example: wordlist = ["yellow"], query = "YellOw": correct = "yellow"
Example: wordlist = ["Yellow"], query = "yellow": correct = "Yellow"
Example: wordlist = ["yellow"], query = "yellow": correct = "yellow"
Vowel Errors: If after replacing the vowels ('a', 'e', 'i', 'o', 'u') of the query word with any vowel individually, it matches a word in the wordlist (case-insensitive), then the query word is returned with the same case as the match in the wordlist.
Example: wordlist = ["YellOw"], query = "yollow": correct = "YellOw"
Example: wordlist = ["YellOw"], query = "yeellow": correct = "" (no match)
Example: wordlist = ["YellOw"], query = "yllw": correct = "" (no match)
In addition, the spell checker operates under the following precedence rules:

When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
When the query matches a word up to capitlization, you should return the first such match in the wordlist.
When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
If the query has no matches in the wordlist, you should return the empty string.
Given some queries, return a list of words answer, where answer[i] is the correct word for query = queries[i].

 

Example 1:

Input: wordlist = ["KiTe","kite","hare","Hare"], queries = ["kite","Kite","KiTe","Hare","HARE","Hear","hear","keti","keet","keto"]
Output: ["kite","KiTe","KiTe","Hare","hare","","","KiTe","","KiTe"]*/

/*Runtime: 112 ms, faster than 41.20% of C++ online submissions for Vowel Spellchecker.
Memory Usage: 31.3 MB, less than 42.42% of C++ online submissions for Vowel Spellchecker.*/
class Solution {
public:
    unordered_map<string, string> deCap;
    unordered_map<string, string> deVow;

    string deC(string in)
    {
        for (auto& i : in)
        {
            i = tolower(i);
        }
        return in;
    }

    string deV(string in)
    {
        in = deC(in);
        for (auto& i : in)
        {
            if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
            {
                i = '*';
            }
        }
        return in;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        vector<string> result;
        set<string> words(wordlist.begin(), wordlist.end());
        for (const auto& word : wordlist)
        {
            string l = deC(word);
            string v = deV(word);
            deCap.insert({ l,word });
            deVow.insert({ v,word });
        }
        for (const auto& q : queries)
        {
            if (words.count(q))
            {
                result.push_back(q);
                continue;
            }
            auto qDec = deC(q);
            if (deCap.find(qDec) != deCap.end())
            {
                result.push_back(deCap[qDec]);
                continue;
            }
            auto qDev = deV(q);
            if (deVow.find(qDev) != deVow.end())
            {
                result.push_back(deVow[qDev]);
                continue;
            }
            result.push_back("");
        }
        return result;
    }
};