#include <bits/stdc++.h>
using namespace std;

/**Brute Force appproach_____________________

 bool mat(vector<vector<int>> v, int target)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == target)
            {
                cout << "True";
                return true;
            }
        }
    }
    cout << "False";
    return false;
}
*/

// OPTIMIZED____________________________

int mat(vector<vector<int>> v, int target)
{
    int start = 0;
    int end = (v.size() * v[0].size()) - 1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (v[mid / v[0].size()][mid % v[0].size()] == target)
        {

            cout << "True";
            return 0;
        }
        else if (v[mid / v[0].size()][mid % v[0].size()] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << "False";
    return 0;
}
int main()
{
    vector<vector<int>> v = {
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 34;
    mat(v, target);
    return 0;
}