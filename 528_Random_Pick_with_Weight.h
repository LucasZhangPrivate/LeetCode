/*Given an array w of positive integers, where w[i] describes the weight of index i, write a function pickIndex which randomly picks an index in proportion to its weight.*/

/*Memory Usage: 32.9 MB, less than 91.80% of C++ online submissions for Random Pick with Weight.*/


//曾经面试过这道题，当时没做出来。
class Solution {
public:
    Solution(vector<int>& w) {
        presum_ = vector<int>(w.size(), 0);
        presum_[0] = w[0];
        for (int i = 1; i < w.size(); ++i) {
            presum_[i] = presum_[i - 1] + w[i];
        }
    }

    int pickIndex() {
        int value = random() % presum_.back();
        //auto iter = upper_bound(presum_.begin(), presum_.end(), value);
        //return iter - presum_.begin();
        for (int i = 0; i < presum_.size(); ++i)
        {
            if (i == 0)
            {
                if (value<presum_[i])
                    return i;
            }
            else if (value >= presum_[i - 1] && value <presum_[i])return i;
        }
        return -1;
    }

private:
    vector<int> presum_;
};


//这个是别人的答案，学会upper_bound 的使用，返回一个比value大的最小的值
class Solution {
public:
    Solution(vector<int>& w) {
        presum_.resize(w.size(), 0);
        presum_[0] = w[0];
        for (int i = 1; i < w.size(); ++i) {
            presum_[i] = presum_[i - 1] + w[i];
        }
    }

    int pickIndex() {
        int value = random() % presum_.back();
        auto iter = upper_bound(presum_.begin(), presum_.end(), value);
        return iter - presum_.begin();
    }

private:
    vector<int> presum_;
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(w);
* int param_1 = obj->pickIndex();
*/