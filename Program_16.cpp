// Problem Statement: Given an array of N integers. Find the elements that appear more than N/3 times in the array. If no such element exists, return an empty vector.

// Input: N = 5, array[] = {1,2,2,3,2}
// Ouput : 2

#include <bits/stdc++.h>
using namespace std;

void majori(vector<int> &v)
{
    int size = v.size();
    vector<int> ans;
    int count1 = 0, count2 = 0;
    int num1 = -1, num2 = -1;
    for (int i = 0; i < size; i++)
    {
        if (count1 == 0)
        {
            num1 == v[i];
            count1 = 1;
        }
        else if (count2 == 0)
        {
            num2 = v[i];
            count2 = 1;
        }
        else if (num1 == v[i])
        {
            count1++;
        }
        else if (num2 == v[i])
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = count2 = 0;
    for (int i = 0; i < size; i++)
    {
        if (v[i] == num1)
            count1++;
        if (v[i] == num2)
            count2++;
    }
    if (count1 > size / 3)
        ans.push_back(num1);
    if (count2 > size / 3)
        ans.push_back(num2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}
int main()
{
    vector<int> v = {1, 2, 2, 3, 2};
    majori(v);
    return 0;
}
