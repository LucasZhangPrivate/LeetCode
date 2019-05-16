/*Given an array of characters, compress it in-place.

The length after compression must always be smaller than or equal to the original array.

Every element of the array should be a character (not int) of length 1.

After you are done modifying the input array in-place, return the new length of the array.*/

/*Runtime: 8 ms, faster than 99.06% of C++ online submissions for String Compression.
Memory Usage: 9.4 MB, less than 98.40% of C++ online submissions for String Compression.*/

class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, pre = 0;
        int cnt = 0;
        while (i<chars.size())
        {
            while (i<chars.size() && chars[i] == chars[pre])
            {
                i++;
                cnt++;
            }
            if (cnt == 1)
            {
                cnt = 0;
            }
            else
            {
                vector<int> num;
                while (cnt>0)
                {
                    num.push_back(cnt % 10);
                    cnt /= 10;
                }
                for (int inx = num.size() - 1; inx >= 0; --inx)
                {
                    chars[++pre] = '0' + num[inx];
                }
            }

            if (i<chars.size())chars[++pre] = chars[i];
        }
        return pre + 1;
    }
};