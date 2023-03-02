// Problem Statement: Given an array of integers A and an integer B. Find the total number of subarrays having bitwise XOR of all elements equal to B.

// Input Format : A = [ 4, 2, 2, 6, 4 ], B = 6
// Result : 4

#include <bits/stdc++.h>
using namespace std;

// OPTIMIZED_______________________________
int bitwise(vector<int> a, int b)
{
    unordered_map<int, int> m;
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int curr_xor = curr_xor ^ a[i];
        if (curr_xor == b)
            count++;
        int h = curr_xor ^ b;
        if (m.find(h) != m.end())
            count += m[h];
        m[curr_xor]++;
    }
    cout << count;
    return count;
}
/**Brute Force_____________________________

int bitwise(vector<int> a, int b)
{
    int count = 0;
    for (int i = 0; i < a.size(); i++)
    {
        int curr_xor = 0;
        for (int j = i; j < a.size(); j++)
        {
            curr_xor ^= a[j];
            if (curr_xor == b)
            {
                count++;
            }
        }
    }
    cout << count;
    return count;
}
*/
int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int b = 6;
    bitwise(a, b);
    return 0;
}