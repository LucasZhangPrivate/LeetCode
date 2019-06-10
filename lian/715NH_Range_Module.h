/*A Range Module is a module that tracks ranges of numbers. Your task is to design and implement the following interfaces in an efficient manner.

addRange(int left, int right) Adds the half-open interval [left, right), tracking every real number in that interval. Adding an interval that partially overlaps with currently tracked numbers should add any numbers in the interval [left, right) that are not already tracked.
queryRange(int left, int right) Returns true if and only if every real number in the interval [left, right) is currently being tracked.
removeRange(int left, int right) Stops tracking every real number currently being tracked in the interval [left, right).
Example 1:
addRange(10, 20): null
removeRange(14, 16): null
queryRange(10, 14): true (Every number in [10, 14) is being tracked)
queryRange(13, 15): false (Numbers like 14, 14.03, 14.17 in [13, 15) are not being tracked)
queryRange(16, 17): true (The number 16 in [16, 17) is still being tracked, despite the remove operation)
Note:

A half open interval [left, right) denotes all real numbers left <= x < right.
0 < left < right < 10^9 in all calls to addRange, queryRange, removeRange.
The total number of calls to addRange in a single test case is at most 1000.
The total number of calls to queryRange in a single test case is at most 5000.
The total number of calls to removeRange in a single test case is at most 1000*/

/*Runtime: 268 ms, faster than 91.33% of C++ online submissions for Range Module.
Memory Usage: 65.8 MB, less than 60.05% of C++ online submissions for Range Module.*/


//40分钟无bug，遇到这个估计束手就擒了啊
class RangeModule {
private:
    map<int, int> m;
public:
    RangeModule() {

    }

    void addRange(int left, int right) {
        removeRange(left, right);
        m[left] = right;
        auto it = m.find(left);
        if (it != m.begin() && prev(it)->second == left) {
            it--;
            it->second = right;
            m.erase(left);
        }
        if (it != prev(m.end()) && next(it)->first == right) {
            it->second = next(it)->second;
            m.erase(next(it));
        }
    }

    bool queryRange(int left, int right) {
        auto it = m.upper_bound(left);
        if (m.empty() || it == m.begin()) return false;
        it--;
        return it->second >= right;
    }

    void removeRange(int left, int right) {
        if (m.empty())return;
        auto it = m.lower_bound(left);
        if (it != m.begin())it--;
        vector<int> v;
        while (it != m.end() && it->first< right)
        {
            if (it->first< left && it->second > left)
            {
                int temp = it->second;
                it->second = left;
                if (temp>right)
                {
                    m[right] = temp;
                }
            }
            else if (it->first >= left)
            {
                v.push_back(it->first);
                if (it->second> right)
                {
                    m[right] = it->second;
                }
            }
            it++;
        }
        for (auto i : v)m.erase(i);
    }
};

/**
* Your RangeModule object will be instantiated and called as such:
* RangeModule* obj = new RangeModule();
* obj->addRange(left,right);
* bool param_2 = obj->queryRange(left,right);
* obj->removeRange(left,right);
*/