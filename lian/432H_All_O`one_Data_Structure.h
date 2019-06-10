/*Implement a data structure supporting the following operations:

Inc(Key) - Inserts a new key with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
Challenge: Perform all these in O(1) time complexity.*/

/*Runtime: 48 ms, faster than 93.59% of C++ online submissions for All O`one Data Structure.
Memory Usage: 25.2 MB, less than 85.00% of C++ online submissions for All O`one Data Structure.*/

class AllOne {
private:
    map<int, vector<string>> minMax;
    unordered_map<string, int> m;
public:
    /** Initialize your data structure here. */
    AllOne() {

    }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        m[key]++;
        int i = m[key];
        in(key, i - 1);
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        m[key]--;
        int i = m[key];
        if (i <= 0)m.erase(key);
        de(key, i + 1);
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (minMax.empty())return "";
        auto v = minMax.rbegin();
        return v->second[0];
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (minMax.empty())return "";
        return minMax.begin()->second[0];
    }
    void in(string key, int i)
    {
        if (i == 0)
        {
            minMax[1].push_back(key);
            return;
        }
        auto& v = minMax[i];
        auto it = find(v.begin(), v.end(), key);
        v.erase(it);
        if (v.size() == 0)minMax.erase(i);
        minMax[i + 1].push_back(key);
    }
    void de(string key, int i)
    {
        if (i == 0)return;
        auto& v = minMax[i];
        auto it = find(v.begin(), v.end(), key);
        v.erase(it);
        if (v.size() == 0)minMax.erase(i);
        if (i>1)
        {
            minMax[i - 1].push_back(key);
        }
    }
};

/**
* Your AllOne object will be instantiated and called as such:
* AllOne* obj = new AllOne();
* obj->inc(key);
* obj->dec(key);
* string param_3 = obj->getMaxKey();
* string param_4 = obj->getMinKey();
*/