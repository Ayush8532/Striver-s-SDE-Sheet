// Problem Statement: Given an array containing both positive and negative integers, we have to find the length of the longest subarray with the sum of all elements equal to zero.

// Input Format: N = 6, array[] = {9, -3, 3, -1, 6, -5}
// Result : 5

#include <bits/stdc++.h>
using namespace std;

//OPTIMIZED__________________________________
int sub(vector<int>&v)
{
    int size=v.size();
    int sum=0, maxi=0;
    unordered_map<int,int>m;
    for(int i=0;i<size;i++)
    {
        sum += v[i];
        if(sum==0)
        {
            maxi = i + 1;
        }
        else{
            if(m.find(sum)!=m.end())
            {
                maxi = max(maxi, i - m[sum]);
            }
            else{
                m[sum] = i;
            }
        }
    }
    return maxi;
}
/*Brute Force---------------------------
int sub(vector<int> &v)
{
    int size = v.size();
    int maxi = 0;
    for (int i = 0; i < size; i++)
    {
        int sum = 0;
        for (int j = i; j < size; j++)
        {
            sum += v[j];
            if (sum == 0)
            {
                int length = j - i + 1;
                maxi = max(maxi, length);
            }
        }
    }
    cout << maxi;
    return maxi;
}
*/
int main()
{
    vector<int> v = {9, -3, 3, -1, 6, -5};
    sub(v);
    return 0;
}