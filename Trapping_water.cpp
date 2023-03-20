#include <bits/stdc++.h>
using namespace std;

int trapWater(vector<int> v)
{
    int n = v.size();
    vector<int> left;
    vector<int> right;
    left[0] = v[0];

    for (int i = 1; i < n; i++)
    {
        left[i] = max(left[i - 1], v[i]);
    }
    right[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        right[i] = max(right[i + 1], v[i]);
    }
    int water = 0;
    for (int i = 0; i < n; i++)
    {
        water += min(left[i], right[i]) - v[i];
    }
    return water;
}
int main()
{
    vector<int> v = {4, 2, 0, 3, 2, 5};
    int sum = trapWater(v);
    cout <<"The sum " <<sum;
    return 0;
}