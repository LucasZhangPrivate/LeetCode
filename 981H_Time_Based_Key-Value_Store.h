/*Create a timebased key-value store class TimeMap, that supports two operations.

1. set(string key, string value, int timestamp)

Stores the key and value, along with the given timestamp.
2. get(string key, int timestamp)

Returns a value such that set(key, value, timestamp_prev) was called previously, with timestamp_prev <= timestamp.
If there are multiple such values, it returns the one with the largest timestamp_prev.
If there are no values, it returns the empty string ("").
 

Example 1:

Input: inputs = ["TimeMap","set","get","get","set","get","get"], inputs = [[],["foo","bar",1],["foo",1],["foo",3],["foo","bar2",4],["foo",4],["foo",5]]
Output: [null,null,"bar","bar",null,"bar2","bar2"]
Explanation:   
TimeMap kv;   
kv.set("foo", "bar", 1); // store the key "foo" and value "bar" along with timestamp = 1   
kv.get("foo", 1);  // output "bar"   
kv.get("foo", 3); // output "bar" since there is no value corresponding to foo at timestamp 3 and timestamp 2, then the only value is at timestamp 1 ie "bar"   
kv.set("foo", "bar2", 4);   
kv.get("foo", 4); // output "bar2"   
kv.get("foo", 5); //output "bar2"   

Example 2:

Input: inputs = ["TimeMap","set","set","get","get","get","get","get"], inputs = [[],["love","high",10],["love","low",20],["love",5],["love",10],["love",15],["love",20],["love",25]]
Output: [null,null,null,"","high","high","low","low"]*/


// One case can not pass cause timeout.

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        m.clear();
    }

    void set(string key, string value, int timestamp) {
        m[key].push_back(make_pair(value, timestamp));
    }

    string get(string key, int timestamp) {
        if (m.find(key) == m.end())return "";
        const auto& lst = m[key]; //using reference is so important here to improve speed.
        int i = 0;
        int j = lst.size() - 1;
        while (i <= j)
        {
            int mid = (i + j) / 2;
            if (lst[mid].second == timestamp)return lst[mid].first;
            else if (lst[mid].second < timestamp) i = mid + 1;
            else j = mid - 1;

        }
        auto r = max(j, i); // not always find the result, some time may get the one bigger than the timestamp.
        if (r - 1 >= 0)return lst[r - 1].first;
        else return "";
    }
private:
    unordered_map<string, vector<pair<string, int>>> m;
};

/**
* Your TimeMap object will be instantiated and called as such:
* TimeMap* obj = new TimeMap();
* obj->set(key,value,timestamp);
* string param_2 = obj->get(key,timestamp);
*/