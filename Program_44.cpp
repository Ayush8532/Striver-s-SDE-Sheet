#include <bits/stdc++.h>
using namespace std;

struct Job
{
    int id;
    int dead;
    int profit;
};
class Solution
{
public:
    bool static conversion(Job a, Job b)
    {
        return (a.profit > b.profit);
    }
    vector<int> jobSche(vector<Job> v, int n)
    {
        vector<int> answer;
        sort(v.begin(), v.end(), conversion);
        int maxi = v[0].dead;
        for (int i = 1; i < n; i++)
        {
            maxi = max(maxi, v[i].dead);
        }
        vector<int> v2;
        for (int i = 0; i < maxi; i++)
        {
            v2.push_back(-1);
        }
        int countMax = 0;
        int profitMax = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = v[i].dead; j > 0; j--)
            {
                if (v2[j] == -1)
                {
                    v2[j] = i;
                    countMax++;
                    profitMax += v[j].profit;
                    break;
                }
            }
        }
        v2.push_back(countMax);
        v2.push_back(profitMax);
        cout << countMax << endl;
        cout << profitMax;
        return v2;
    }
    int main()
    {
        int n = 4;
        vector<Job> v = {{1, 4, 20}, {2, 1, 10}, {3, 2, 40}, {4, 2, 30}};
        jobSche(v, n);
        return 0;
    }
};