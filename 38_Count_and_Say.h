/*The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

Note: Each term of the sequence of integers will be represented as a string.

 

Example 1:

Input: 1
Output: "1"
Example 2:

Input: 4
Output: "1211"*/

/*Runtime: 16 ms, faster than 18.17% of C++ online submissions for Count and Say.
Memory Usage: 59 MB, less than 12.34% of C++ online submissions for Count and Say.*/

class Solution {
public:
    string countAndSay(int n) {
        string cur = "1";
        if (n == 1)return cur;
        while (n-->1)
        {
            string temp;
            auto pre = cur[0];
            int count = 1;
            int i = 1;
            while (i<cur.size())
            {
                if (cur[i] == pre)
                {
                    count++;
                    i++;
                }
                else
                {
                    string c = to_string(count);
                    temp = temp + c + pre;
                    pre = cur[i++];
                    count = 1;
                }
            }
            string c = to_string(count);
            cur = temp + c + pre;
        }

        return cur;
    }
};

/*Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count and Say.
Memory Usage: 8.7 MB, less than 78.24% of C++ online submissions for Count and Say.*/


//之前做的，这个效率高
class Solution {
public:
    string countAndSay(int n)
    {
        int count = 1;
        string result = "1";
        while (count<n)
        {
            int i = 0;
            string r;
            while (i<result.size())
            {

                int temp;
                size_t z = result.find_first_not_of(result[i], i);
                if (string::npos == z)temp = result.size() - i;
                else temp = z - i;
                //r+=(temp+'0');
                r += to_string(temp);
                r += result[i];
                i = z; //this is ignored by the first time, I use i++.
            }
            result = r;
            count++;
        }
        return result;
    }


};