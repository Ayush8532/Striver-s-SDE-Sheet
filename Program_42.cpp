#include <bits/stdc++.h>
using namespace std;

void meeting(vector<int> s, vector<int> f, int n)
{
    pair<int, int> a[n + 1];
    for (int i = 0; i < n; i++)
    {
        a[i].first = f[i];
        a[i].second = i;
    }
    sort(a, a + n);
    int limit = a[0].first;
    vector<int> m;
    m.push_back(0);
    for (int i = 1; i < n; i++)
    {
        if (s[a[i].second] > limit)
        {
            m.push_back(i);
            limit = a[i].first;
        }
    }
    cout << m.size();
}
int main()
{
    int n = 6;
    vector<int> s = {1, 3, 0, 5, 8, 5};
    vector<int> f = {2, 4, 6, 7, 9, 9};
    meeting(s, f, n);
}