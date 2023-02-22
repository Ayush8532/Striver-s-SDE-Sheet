// Problem Statement: Given an array of N integers, write a program to return an element that occurs more than N/2 times in the given array. You may consider that such an element always exists in the array.

// Input Format:  N = 7, nums[] = {2,2,1,1,1,2,2}
// Result: 2

#include <bits/stdc++.h>
using namespace std;

// Optimal approach-------------------------
int majori(vector<int> v)
{
    int n = v.size();
    int count = 0;
    int number;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            number = v[i];
        }
        if (number == v[i])
            count++;
        else
            count--;
    }
    cout << number;
    return number;
}

/*Better Approach-----------------------
int majori(vector<int> v)
{
    int n = v.size();
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[v[i]]++;
    }
    for (auto i : m)
    {
        if (i.second > n / 2)
        {
            cout << i.first;
            return i.first;
        }
    }
    return -1;
}
*/
int main()
{
    vector<int> v = {2, 2, 1, 1, 1, 2, 1};
    majori(v);
    return 0;
}
