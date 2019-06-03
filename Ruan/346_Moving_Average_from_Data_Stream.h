/*Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Example:

MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3*/

/*Runtime: 32 ms, faster than 97.09% of C++ online submissions for Moving Average from Data Stream.
Memory Usage: 15.4 MB, less than 68.89% of C++ online submissions for Moving Average from Data Stream.*/

//去年的做法是用queue，前出后进，但是消耗应该大很多
class MovingAverage {
private:
    vector<int> keep;
    int sum;
    int index;
    int s;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        keep = vector<int>(size, 0);
        sum = 0;
        index = -1;
        s = size;
    }

    double next(int val) {
        index++;
        auto cur = index % s;
        sum -= keep[cur];
        sum += val;
        keep[cur] = val;
        double num = index<s ? static_cast<double>(index%s + 1) : static_cast<double>(s);
        return sum / num;
    }
};

/**
* Your MovingAverage object will be instantiated and called as such:
* MovingAverage* obj = new MovingAverage(size);
* double param_1 = obj->next(val);
*/