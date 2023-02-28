// Problem Statement: Given an array of N integers, your task is to find unique quads that add up to give a target value. In short, you need to return an array of all the unique quadruplets [arr[a], arr[b], arr[c], arr[d]] such that their sum is equal to a given target.

// Input Format: arr[] = [1,0,-1,0,-2,2], target = 0
// Result : [ [ -2, -1, 1, 2 ], [ -2, 0, 0, 2 ], [ -1, 0, 0, 1 ] ]

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &arr, int target)
{
    vector<vector<int>> answer;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int three_sum = target - arr[i];
        for (int j = i + 1; j < n; j++)
        {
            int two_sum = three_sum - arr[j];
            int left = j + 1;
            int right = n - 1;
            while (left < right)
            {
                int sum = arr[left] + arr[right];
                if (sum > two_sum)
                    right--;
                else if (sum < two_sum)
                    left++;
                else
                {
                    vector<int> quad(4, 0);
                    quad[0] = arr[i];
                    quad[1] = arr[j];
                    quad[2] = arr[left];
                    quad[3] = arr[right];
                    answer.push_back(quad);
                    while (left < right && quad[2] == arr[left])
                        ++left;
                    while (left < right && quad[3] == arr[right])
                        --right;
                }
            }
            while (j + 1 < n && arr[j + 1] == arr[j])
                ++j;
        }
        while (i + 1 < n && arr[i + 1] == arr[i])
            ++i;
    }
    return answer;
}
int main()
{
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 0;
    fourSum(arr, target);
    return 0;
}