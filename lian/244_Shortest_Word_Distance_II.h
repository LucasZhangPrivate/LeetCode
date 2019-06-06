/*Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 

Example:
Assume that words = ["practice", "makes", "perfect", "coding", "makes"].

Input: word1 = ¡°coding¡±, word2 = ¡°practice¡±
Output: 3
Input: word1 = "makes", word2 = "coding"
Output: 1
Note:
You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.*/

/*Runtime: 56 ms, faster than 36.95% of C++ online submissions for Shortest Word Distance II.
Memory Usage: 20.4 MB, less than 25.67% of C++ online submissions for Shortest Word Distance II.*/

class WordDistance {
private:
    unordered_map<string, vector<int>> map;
public:
    WordDistance(vector<string>& words) {
        for (int i = 0; i< words.size(); ++i)
        {
            map[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        auto list1 = map[word1];
        auto list2 = map[word2];
        int dis = INT_MAX;
        int i = 0;
        int j = 0;
        while (i< list1.size() || j<list2.size())
        {
            if (i< list1.size() && j<list2.size())
            {
                dis = min(abs(list1[i] - list2[j]), dis);
                if (list1[i] < list2[j])i++;
                else j++;
            }
            else if (i < list1.size())
            {
                dis = min(abs(list1[i] - list2.back()), dis);
                if (list1[i]>list2.back())break;
                else i++;
            }
            else {
                dis = min(abs(list2[j] - list1.back()), dis);
                if (list2[j]>list1.back())break;
                else j++;
            }
        }
        return dis;
    }
};

/**
* Your WordDistance object will be instantiated and called as such:
* WordDistance* obj = new WordDistance(words);
* int param_1 = obj->shortest(word1,word2);
*/