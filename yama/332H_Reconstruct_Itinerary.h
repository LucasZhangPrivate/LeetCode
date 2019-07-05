/*Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:

If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:

Input: [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Output: ["JFK", "MUC", "LHR", "SFO", "SJC"]
Example 2:

Input: [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"].
             But it is larger in lexical order.*/

/*Runtime: 20 ms, faster than 97.64% of C++ online submissions for Reconstruct Itinerary.
Memory Usage: 15.8 MB, less than 95.38% of C++ online submissions for Reconstruct Itinerary.*/

class Solution {
private:
    unordered_map<string, deque<string>> mp;
    void visit(string cur, vector<string>& res)
    {
        auto& list = mp[cur];
        while (!list.empty())
        {
            auto next = list.front();
            list.pop_front();
            visit(next, res);
        }
        res.push_back(cur);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (const auto& t : tickets)
        {
            mp[t[0]].push_back(t[1]);
        }
        for (auto& p : mp)
        {
            auto& s = p.second;
            sort(s.begin(), s.end());
        }
        const string& start = "JFK";
        vector<string> res;
        visit(start, res);
        reverse(res.begin(), res.end());
        return res;
    }
};