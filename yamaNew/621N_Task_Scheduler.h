/*Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks. Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.

 

Example:

Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
 

Note:

The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].*/

/*Runtime: 52 ms, faster than 96.87% of C++ online submissions for Task Scheduler.
Memory Usage: 9.7 MB, less than 74.93% of C++ online submissions for Task Scheduler.*/

//https://zxi.mytechroad.com/blog/greedy/leetcode-621-task-scheduler/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n == 0)return tasks.size();
        vector<int> sum(26, 0);
        for (const auto& num : tasks)sum[num - 'A']++;
        auto fre = *max_element(sum.begin(), sum.end());
        int res = (fre - 1)*(n + 1);
        res += count_if(sum.begin(), sum.end(), [fre](const auto& i) {return fre == i; });
        return max((int)tasks.size(), res);
    }
};

