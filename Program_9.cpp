// Problem statement: Given two sorted arrays arr1[] and arr2[] of sizes n and m in non-decreasing order. Merge them in sorted order. Modify arr1 so that it contains the first N elements and modify arr2 so that it contains the last M elements.

// Input:n = 4, arr1[] = [1 4 8 10] m = 3, arr2[] = [2 3 9]
// Output : arr1[] = [1 2 3 4] arr2[] = [8 9 10]

#include <bits/stdc++.h>
using namespace std;

// OPTIMIZED_________

vector<int> merging(vector<int> &v1, vector<int> &v2)
{
    int n = v1.size(), m = v2.size();
    int i = n - 1,j = m - 1;
    int k = n + m - 1, size = n + m;
    while (i >= 0 && j >= 0)
    {
        if (v1[i] < v2[j])
        {
            v1[k--] = v2[j--];
        }
        else
        {
            v1[k--] = v1[i--];
        }
    }
    while (i >= 0)
    {
        v1[k--] = v1[i--];
    }
    while (j >= 0)
    {
        v1[k--] = v2[j--];
    }
    for (int i = 0; i < size;i++)
    {
        cout << v1[i] << " ";
    }
        return v1;
}
/*BRUTE FORCE_____________
vector<int> merging(vector<int> v1, vector<int> v2)
{
    vector<int> ans;
    int n = v1.size();
    int m = v2.size();
    int size = n + m;
    for (int i = 0; i < n; i++)
    {
        ans.push_back(v1[i]);
    }
    for (int i = 0; i < m; i++)
    {
        ans.push_back(v2[i]);
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < size; i++)
    {
        cout << ans[i] << " ";
    }
    return ans;
}
*/
int main()
{
    vector<int> v1 = {1, 4, 8, 10};
    vector<int> v2 = {2, 3, 9};
    merging(v1, v2);
    return 0;
}