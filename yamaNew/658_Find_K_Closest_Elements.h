/*Given a sorted array, two integers k and x, find the k closest elements to x in the array. The result should also be sorted in ascending order. If there is a tie, the smaller elements are always preferred.

Example 1:
Input: [1,2,3,4,5], k=4, x=3
Output: [1,2,3,4]
Example 2:
Input: [1,2,3,4,5], k=4, x=-1
Output: [1,2,3,4]
Note:
The value k is positive and will always be smaller than the length of the sorted array.
Length of the given array is positive and will not exceed 104
Absolute value of elements in the array and x will not exceed 104
*/

/*Runtime: 136 ms, faster than 22.27% of C++ online submissions for Find K Closest Elements.
Memory Usage: 13.5 MB, less than 36.50% of C++ online submissions for Find K Closest Elements.*/

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        sort(arr.begin(), arr.end(), [&](const auto& l, const auto& r) {
            auto a = abs(l - x);
            auto b = abs(r - x);
            if (a == b)return l<r;
            return a<b;
        });
        vector<int> res;

        for (int i = 0; i<k; ++i)res.push_back(arr[i]);
        sort(res.begin(), res.end());
        return res;
    }
};