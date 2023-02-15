//   Given an integer array arr, find the contiguous subarray (containing at least one number) which
//   has the largest sum and returns its sum and prints the subarray.

// Input: arr = [-2,1,-3,4,-1,2,1,-5,4]

// Output: 6

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &v, vector<int> &subarray)
{
    int size = v.size();
    int sum = 0, maxSum = INT_MIN, s = 0;
    for (int i = 0; i < size; i++)
    {
        sum += v[i];
        if (sum > maxSum)
        {
            subarray.clear();
            maxSum = sum;
            subarray.push_back(s);
            subarray.push_back(i);
        }
        if (sum < 0)
        {
            sum = 0;
            s = i + 1;
        }
        // To only print sum
        //  sum = max(sum + v[i], v[i]);
        //  maxSum = max(sum, maxSum);
    }
    return maxSum;
}
int main()
{
    vector<int> v = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> subarray;
    int lon = kadane(v, subarray);
    cout << "max Sum is " << lon << endl;
    for (int i = subarray[0]; i <= subarray[1]; i++)
    {
        cout << v[i] << " ";
    }
}
