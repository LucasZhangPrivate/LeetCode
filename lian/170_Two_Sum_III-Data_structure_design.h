/*Design and implement a TwoSum class. It should support the following operations: add and find.

add - Add the number to an internal data structure.
find - Find if there exists any pair of numbers which sum is equal to the value.

Example 1:

add(1); add(3); add(5);
find(4) -> true
find(7) -> false
Example 2:

add(3); add(1); add(2);
find(3) -> true
find(6) -> false*/

/*Runtime: 144 ms, faster than 50.92% of C++ online submissions for Two Sum III - Data structure design.
Memory Usage: 23.7 MB, less than 73.14% of C++ online submissions for Two Sum III - Data structure design.*/

class TwoSum {
private:
    unordered_map<int, int> map;
public:
    /** Initialize your data structure here. */
    TwoSum() {
    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        map[number]++;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (const auto& p : map)
        {
            auto first = p.first;
            auto second = value - first;
            if (first == second && p.second>1)return true;
            else if (first != second && map.find(second) != map.end())return true;
        }
        return false;
    }
};

/**
* Your TwoSum object will be instantiated and called as such:
* TwoSum* obj = new TwoSum();
* obj->add(number);
* bool param_2 = obj->find(value);
*/