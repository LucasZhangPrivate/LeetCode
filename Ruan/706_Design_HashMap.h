/*Design a HashMap without using any built-in hash table libraries.

To be specific, your design should include these functions:

put(key, value) : Insert a (key, value) pair into the HashMap. If the value already exists in the HashMap, update the value.
get(key): Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.

Example:

MyHashMap hashMap = new MyHashMap();
hashMap.put(1, 1);          
hashMap.put(2, 2);         
hashMap.get(1);            // returns 1
hashMap.get(3);            // returns -1 (not found)
hashMap.put(2, 1);          // update the existing value
hashMap.get(2);            // returns 1 
hashMap.remove(2);          // remove the mapping for 2
hashMap.get(2);            // returns -1 (not found) 
*/

/*Runtime: 140 ms, faster than 70.74% of C++ online submissions for Design HashMap.
Memory Usage: 56.6 MB, less than 35.87% of C++ online submissions for Design HashMap.
Next challenges:*/

using List = vector<pair<int, int>>;
using Map = vector<List>;
class MyHashMap {
public:
    /** Initialize your data structure here. */
    void init()
    {
        List list = List();
        map = Map();
        int s = size;
        while (s-- > 0)map.push_back(list);
    }
    void resize()
    {
        auto m = map;
        size *= 2;
        init();
        sum = 0;
        for (const auto& list : m)
        {
            for (const auto& cell : list)
            {
                put(cell.first, cell.second);
            }
        }
    }
    MyHashMap() {
        sum = 0;
        size = 1000;
        init();
    }

    /** value will always be non-negative. */
    void put(int key, int value) {
        if (sum>static_cast<int>(0.75*size))resize();
        int pos = key % size;
        auto& li = map[pos];
        for (auto& cell : li)
        {
            if (cell.first == key)
            {
                cell.second = value;
                return;
            }
        }
        li.push_back({ key, value });
        sum++;
    }

    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int pos = key % size;
        auto& li = map[pos];
        for (auto& cell : li)
        {
            if (cell.first == key)
            {
                return cell.second;
            }
        }
        return -1;
    }

    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int pos = key % size;
        auto& li = map[pos];
        for (int i = 0; i<li.size(); ++i)
        {
            if (li[i].first == key)
            {
                li.erase(li.begin() + i);
                sum--;
                return;
            }
        }
    }
private:
    int sum;
    Map map;
    size_t size;
};

/**
* Your MyHashMap object will be instantiated and called as such:
* MyHashMap* obj = new MyHashMap();
* obj->put(key,value);
* int param_2 = obj->get(key);
* obj->remove(key);
*/