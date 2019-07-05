/*Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();*/

/*Runtime: 240 ms, faster than 9.38% of C++ online submissions for Shuffle an Array.
Memory Usage: 34.3 MB, less than 5.09% of C++ online submissions for Shuffle an Array.*/

class Solution {
public:
    vector<int> m;
    Solution(vector<int>& nums) {
        m = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return m;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res;
        auto n = m;
        while (!n.empty())
        {
            auto i = random() % n.size();
            res.push_back(n[i]);
            n.erase(n.begin() + i);
        }
        return res;
    }
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(nums);
* vector<int> param_1 = obj->reset();
* vector<int> param_2 = obj->shuffle();
*/

/*Runtime: 192 ms, faster than 98.53% of C++ online submissions for Shuffle an Array.
Memory Usage: 30.2 MB, less than 26.21% of C++ online submissions for Shuffle an Array.*/
class Solution {
public:
    vector<int> m;
    Solution(vector<int>& nums) {
        m = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return m;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res;
        auto n = m;
        for (int i = n.size() - 1; i >= 0; --i)
        {
            swap(n[i], n[random() % (i + 1)]);
        }
        return n;
    }
};
