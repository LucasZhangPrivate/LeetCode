/*Given an array A of positive lengths, return the largest perimeter of a triangle with non - zero area, formed from 3 of these lengths.

If it is impossible to form any triangle of non - zero area, return 0.



Example 1:

Input: [2, 1, 2]
    Output : 5
    Example 2 :

    Input : [1, 2, 1]
    Output : 0
    Example 3 :

    Input : [3, 2, 3, 4]
    Output : 10
    Example 4 :

    Input : [3, 6, 2, 3]
    Output : 8*/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end(), [](const int a, const int b)->bool {return a>b; });
        int i = A[0];
        int j = A[1];
        int k = A[2];
        int index = 3;
        while (k + j <= i && index<A.size())
        {
            i = j;
            j = k;
            k = A[index++];
        }
        return k + j <= i ? 0 : i + j + k;
    }
};

using namespace std;
class light {
public: 
    vector<bool> lights(N + 1, true);
    for (int i = 1; i <= M; ++i)
    {
        int add = i;
        while (i < N + 1)
        {
            lights[i] = !lights[i];
            i += add;
        }
        i = add;
    }
    string result;
    for (int i = 1; i <= N; ++i)
    {
        if (!lights[i])
        {
            result += to_string(i);
            result += ',';
        }
    }
    result.pop_back();
    return result;
};