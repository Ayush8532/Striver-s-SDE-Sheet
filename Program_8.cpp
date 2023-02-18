// Problem Statement: Given an array of intervals, merge all the overlapping intervals and return an array of non-overlapping intervals.

// Input: intervals=[[1,3],[2,6],[8,10],[15,18]]
// Output : [ [ 1, 6 ], [ 8, 10 ], [ 15, 18 ] ]

#include <bits/stdc++.h>

using namespace std;


/**
 BRUTE FORCE_______________________
vector<pair<int,int>>merge(vector<pair<int,int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    vector < pair < int, int >> ans;
    int n=intervals.size();
    for(int i=0;i<n;i++)
    {
        int start = intervals[i].first;
        int end=intervals[i].second;
        if(!ans.empty())
        {
            if(ans.back().second<=intervals[i].first)
            {
                continue;
            }
        }
        for(int j=i+1;j<n;j++)
        {
            if(intervals[j].first<=end)
            {
                end = max(end, intervals[j].second);
            }
        }
        end = max(end, intervals[i].second);
        ans.push_back({start, end});
    }
    return ans;
}
*/
/**Optimized Approach------------------------------------------*/
 
vector<vector<int>> merge(vector<vector<int>> &intervals)
{

    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;

    for (int i = 0; i < intervals.size(); i++)
    {
        if (merged.empty() || merged.back()[1] < intervals[i][0])
        {
            vector<int> v = {
                intervals[i][0],
                intervals[i][1]};

            merged.push_back(v);
        }
        else
        {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);
        }
    }

    return merged;
}


int main()
{
    vector<vector<int>> arr;
    arr = {{1, 4}, {0, 4}};
    vector<vector<int>> ans = merge(arr);

    cout << "Merged Overlapping Intervals are " << endl;

    for (auto it : ans)
    {
        cout << it[0] << " " << it[1] << "\n";
    }
}