/*Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"
Note:
letters has a length in range [2, 10000].
letters consists of lowercase letters, and contains at least 2 unique letters.
target is a lowercase letter.*/

/*Runtime: 16 ms, faster than 84.59% of C++ online submissions for Find Smallest Letter Greater Than Target.
Memory Usage: 9.2 MB, less than 54.31% of C++ online submissions for Find Smallest Letter Greater Than Target.*/

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = letters[0];
        for (int i = 0; i < letters.size(); ++i)
        {
            if (letters[i]> target)
            {
                res = letters[i];
                break;
            }
        }
        return res;
    }
};