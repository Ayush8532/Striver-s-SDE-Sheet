// Problem Statement: You are given a read-only array of N integers with values also in the range [1, N] both inclusive. Each integer appears exactly once except A which appears twice and B which is missing. The task is to find the repeating and missing numbers A and B where A repeats twice and B is missing.

// Input Format:  array[] = {3,1,2,5,3}
// Result:{3,4)

#include <bits/stdc++.h>
using namespace std;

pair<int, int> missing(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans(n + 1, 0);
    pair<int, int> answer;
    for (int i = 0; i < n; i++)
    {
        ++ans[arr[i]];
    }
    for (int i = 1; i < ans.size(); i++)
    {
        if (ans[i] > 1)
        {
            answer.first = i;
        }
        if (ans[i] == 0)
        {
            answer.second = i;
        }
    }
    cout << answer.first << " " << answer.second;
    return answer;
}
int main()
{
    vector<int> arr = {1, 2, 3, 5, 3};
    missing(arr);
    return 0;
}