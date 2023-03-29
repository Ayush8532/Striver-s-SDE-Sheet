#include<bits/stdc++.h>
using namespace std;

void arrival(vector<int> arr, vector<int> dep, int n)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());
    int ans = 1, count = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            count++;
            i++;
        }
        else if (arr[i] > dep[j])
        {
            count--;
            j++;
        }
        ans = max(ans, count);
    }
    cout << ans;
}
int main()
{
    int n = 6;
    vector<int> arr = {900, 940, 950, 1100, 1500, 1800};
    vector<int> dep = {910, 1200, 1120, 1130, 1900, 2000};
    arrival(arr, dep, n);
    return 0;
}