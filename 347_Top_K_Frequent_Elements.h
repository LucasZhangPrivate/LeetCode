/*Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.*/

/*Runtime: 28 ms, faster than 30.70% of C++ online submissions for Top K Frequent Elements.
Memory Usage: 11.7 MB, less than 19.28% of C++ online submissions for Top K Frequent Elements.*/


//两种优先队列的初始化方式
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (const auto& n : nums)map[n]++;

        /*struct cmp{
        bool operator()(const pair<int,int>& l, const pair<int,int>& r)
        {
        return l.second < r.second;
        }
        };*/


        //priority_queue<pair<int,int> , vector<pair<int,int>>, cmp> queue;

        auto cmp = [](const pair<int, int>& l, const pair<int, int>& r)
        {
            return  l.second < r.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> queue(cmp);


        for (const auto& p : map)queue.push(p);
        vector<int> res;
        while (k-->0)
        {
            auto a = queue.top();
            res.push_back(a.first);
            queue.pop();
        }
        return res;
    }
};