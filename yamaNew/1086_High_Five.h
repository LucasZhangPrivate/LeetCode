/*Given a list of scores of different students, return the average score of each student's top five scores in the order of each student's id.

Each entry items[i] has items[i][0] the student's id, and items[i][1] the student's score.  The average score is calculated using integer division.

 

Example 1:

Input: [[1,91],[1,92],[2,93],[2,97],[1,60],[2,77],[1,65],[1,87],[1,100],[2,100],[2,76]]
Output: [[1,87],[2,88]]
Explanation: 
The average of the student with id = 1 is 87.
The average of the student with id = 2 is 88.6. But with integer division their average converts to 88.
 

Note:

1 <= items.length <= 1000
items[i].length == 2
The IDs of the students is between 1 to 1000
The score of the students is between 1 to 100
For each student, there are at least 5 scores*/

/*Runtime: 16 ms, faster than 62.52% of C++ online submissions for High Five.
Memory Usage: 11.2 MB, less than 87.50% of C++ online submissions for High Five.*/

class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        priority_queue<int, vector<int>, greater<int>> q;
        map<int, priority_queue<int, vector<int>, greater<int>> > mp;
        for (const auto& it : items)
        {
            mp[it[0]].push(it[1]);
            if (mp[it[0]].size()>5)mp[it[0]].pop();
        }
        vector<vector<int>> res;
        for (auto& p : mp)
        {
            int id = p.first;
            int sum = 0;
            auto& q = p.second;
            while (!q.empty())
            {
                sum += q.top();
                q.pop();
            }
            res.push_back({ id, sum / 5 });
        }
        return res;
    }
};