/*In a list of songs, the i-th song has a duration of time[i] seconds. 

Return the number of pairs of songs for which their total duration in seconds is divisible by 60.  Formally, we want the number of indices i < j with (time[i] + time[j]) % 60 == 0.

 

Example 1:

Input: [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
Example 2:

Input: [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
 

Note:

1 <= time.length <= 60000
1 <= time[i] <= 500*/

/*Runtime: 44 ms, faster than 47.90% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.
Memory Usage: 11.9 MB, less than 13.35% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, pair<int, int>> m;
        for (const auto& t : time)
        {
            auto n = t % 60;
            if (n == 0 || n == 30)
            {
                m[n].first++;
            }
            else if (m.count(60 - n))
            {
                m[60 - n].second++;
            }
            else
            {
                m[n].first++;
            }
        }
        int res = 0;
        for (const auto& p : m)
        {
            if (p.first == 0 || p.first == 30)
            {
                res = res + p.second.first*(p.second.first - 1) / 2;
            }
            else
            {
                res = res + p.second.first*p.second.second;
            }
        }
        return res;
    }
};

/*Runtime: 36 ms, faster than 92.73% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.
Memory Usage: 11.8 MB, less than 21.54% of C++ online submissions for Pairs of Songs With Total Durations Divisible by 60.*/
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> hash(60, 0);
        int count = 0;
        for (int i = 0; i < time.size(); i++) {
            hash[time[i] % 60]++;
        };
        count += (hash[0])*(hash[0] - 1) / 2;
        count += (hash[30])*(hash[30] - 1) / 2;
        for (int i = 1; i < 30; i++) {
            count += (hash[i])*(hash[60 - i]);
        }
        return count;
    }
};