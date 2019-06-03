/*Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, also in sorted non-decreasing order.

 

Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.*/



// bad solution, may just use two pointer, compare abs value before set to the end of result vector.Because the largest value 
// can only got from two end.
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int idx1, idx2;
        int i = 0;
        int j = A.size() - 1;
        if (A[i] >= 0) {
            idx2 = i;
            idx1 = -1;
        }
        else if (A[j]<0) {
            idx1 = j;
            idx2 = A.size();
        }
        else {
            while (i<j)
            {
                int mid = (i + j) / 2;
                if (A[mid] * A[mid + 1] <= 0) {
                    idx1 = mid;
                    idx2 = mid + 1;
                    break;
                }
                else if (A[mid] >= 0) {
                    j = mid;
                }
                else if (A[mid]<0) {
                    i = mid;
                }
            }
        }
        vector<int> result;
        while (idx1 >= 0 && idx2<A.size())
        {
            if ((A[idx1] * A[idx1]) <= (A[idx2] * A[idx2]))
            {
                result.push_back(A[idx1] * A[idx1]);
                idx1--;
            }
            else
            {
                result.push_back(A[idx2] * A[idx2]);
                idx2++;
            }
        }
        while (idx1 >= 0)
        {
            result.push_back(A[idx1] * A[idx1]);
            idx1--;
        }
        while (idx2<A.size())
        {
            result.push_back(A[idx2] * A[idx2]);
            idx2++;
        }
        return result;
    }
};