/*Given a non-empty list of words, return the k most frequent elements.

Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.

Example 1:
Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]
Explanation: "i" and "love" are the two most frequent words.
    Note that "i" comes before "love" due to a lower alphabetical order.
Example 2:
Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]
Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
    with the number of occurrence being 4, 3, 2 and 1 respectively.
Note:
You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Input words contain only lowercase letters.
Follow up:
Try to solve it in O(n log k) time and O(n) extra space.*/

/*Runtime: 16 ms, faster than 98.98% of C++ online submissions for Top K Frequent Words.
Memory Usage: 11.9 MB, less than 81.41% of C++ online submissions for Top K Frequent Words.*/


//不同时期的两个答案，05/08/2019，用的是vector的sort
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for (const auto& w : words)map[w]++;
        vector<pair<string, int>> list;
        for (const auto& p : map)
        {
            list.emplace_back(p.first, p.second);
        }

        sort(list.begin(), list.end(), [&](const auto& l, const auto& r)
            ->bool {if (l.second == r.second)return l.first<r.first;
            else return l.second>r.second; });
        vector<string> result;
        for (int i = 0; i<k; ++i)
        {
            result.emplace_back(list[i].first);
        }
        return result;
    }
};

//一年多以前用的优先队列，效率基本一样
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        struct compare {
            bool operator()(const pair<string, int>& l, const pair<string, int>& r) {
                if (l.second == r.second)return l.first<r.first;
                else
                    return l.second > r.second;
            }
        };

        vector<string> result;

        unordered_map<string, int> mymap;
        for (auto &&st : words)mymap[st]++;

        priority_queue<pair<string, int>, vector<pair<string, int>>, compare> q;
        for (auto &&p : mymap)
        {
            q.emplace(p.first, p.second);
            if (q.size()>k)q.pop();
        }
        while (!q.empty())
        {
            result.insert(result.begin(), q.top().first);
            q.pop();
        }
        return result;
    }
};