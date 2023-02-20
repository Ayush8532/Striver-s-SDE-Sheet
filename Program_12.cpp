// Given an array of N integers, count the inversion of the array (using merge-sort). What is an inversion of an array? Definition: for all i & j < size of array, if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

// Input Format: N = 5, array[] = {1,2,3,4,5}
// Result : 0

#include <bits/stdc++.h>
using namespace std;

// OPTIMIZED
int merge(vector<int> v, vector<int> temp, int left, int mid, int right)
{
    int count = 0;
    int i = left;
    int j = mid;
    int k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (v[i] <= v[j])
        {
            temp[k++] = v[i++];
        }
        else
        {
            temp[k++] = v[j++];
            count = count + (mid - i);
        }
    }
    while (i <= mid - 1)
    {
        temp[k++] = v[i++];
    }
    while (j <= right)
    {
        temp[k++] = v[j++];
    }
    for (i = left; i <= right; i++)
        v[i] = temp[i];
    return count;
}
int merging(vector<int> v, vector<int> temp, int start, int last)
{
    int mid;
    int count = 0;
    if (start < last)
    {
        mid = (start + last) / 2;
        count += merging(v, temp, start, mid);
        count += merging(v, temp, mid + 1, last);
        count += merge(v, temp, start, mid + 1, last);
    }
    return count;
}

/**
 BRUTE FORCE________________________________________
void inversion(vector<int> v, int n)
{
    vector<pair<int, int>> answer;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (v[i] > v[j])
            {
                answer.push_back(make_pair(v[i], v[j]));
            }
        }
    }
    int size = answer.size();
    cout << size;
}
*/
int main()
{
    int n = 5;
    vector<int> v = {5, 4, 3, 2, 1};
    vector<int> temp;
    int ans = merging(v, temp, 0, n - 1);
    cout << ans;
    return 0;
}