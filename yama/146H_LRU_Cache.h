/*Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 /* capacity */ );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4*/

/*Runtime: 96 ms, faster than 98.04% of C++ online submissions for LRU Cache.
Memory Usage: 38 MB, less than 73.73% of C++ online submissions for LRU Cache.*/

class LRUCache {
private:
    unordered_map<int, list<pair<int, int>>::iterator> m;
    list<pair<int, int>> cache;
    int capa;
public:
    LRUCache(int capacity) {
        capa = capacity;
    }

    int get(int key) {
        const auto it = m.find(key);
        if (it == m.end())return -1;
        cache.splice(cache.begin(), cache, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        const auto it = m.find(key);
        if (it != m.end())
        {
            it->second->second = value;
            cache.splice(cache.begin(), cache, it->second);
            return;
        }
        if (cache.size() == capa)
        {
            const auto& node = cache.back();
            m.erase(node.first);
            cache.pop_back();
        }
        cache.emplace_front(key, value);
        m[key] = cache.begin();
    }
};

/**
* Your LRUCache object will be instantiated and called as such:
* LRUCache* obj = new LRUCache(capacity);
* int param_1 = obj->get(key);
* obj->put(key,value);
*/