// Problem Statement: Given an array of N + 1 size, where each element is between 1 and N. Assuming there is only one duplicate number, your task is to find the duplicate number.

// Input: arr=[1,3,4,2,2]
// Output: 2

#include <bits/stdc++.h>
using namespace std;

int duplicate(vector<int>arr)
{
    int slow = arr[0];
    int fast = arr[0];
    do
    {
        slow=arr[slow];
        fast = arr[arr[fast]];
    }while (slow != fast);

    fast = arr[0];
    while(slow!=fast)
    {
        slow=arr[slow];
        fast = arr[fast];
    }
    return fast;
}
/*BRUTE FORCE_____________________
void duplicate(vector<int> arr)
{
    int n = arr.size();
    int ans;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        ++m[arr[i]];
    }
    for (int i = 0; i < n; i++)
    {
        if (m[i] == 2)
        {
            ans = i;
        }
    }
    cout << ans;
}
*/
int main()
{
    vector<int> arr = {1, 4, 3, 4, 2};
    duplicate(arr);
    return 0;
}
