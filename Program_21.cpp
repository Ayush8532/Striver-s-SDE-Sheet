// Problem Statement: You are given an array of ‘N’ integers. You need to find the length of the longest sequence which contains the consecutive elements

// Input: [100, 200, 1, 3, 2, 4]
// Output: 4

#include <bits/stdc++.h>
using namespace std;
// OPTIMIZED_____________________________
int consecutive(vector<int> nums)
{
    set<int> hash_set;
    for (int num : nums)
    {
        hash_set.insert(num);
    }
    int longest = 0;
    for (int num : nums)
    {
        if (!hash_set.count(num - 1))
        {
            int currNum = num;
            int streak = 1;
            while (hash_set.count(currNum + 1))
            {
                currNum += 1;
                streak += 1;
            }
            longest = max(longest, streak);
        }
    }
    cout << longest;
    return longest;
}
/*BRUTE FORCE_______________________________________
int consecutive(vector<int> nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    sort(nums.begin(), nums.end());
    int count = 1, max_count = INT_MIN;
    int starting = nums[0];
    for (int i = 1; i < n; i++)
    {
        if (nums[i] == starting + 1)
        {
            count += 1;
        }
        else if (nums[i] != starting + 1)
        {
            count = 1;
        }
        starting = nums[i];
        max_count = max(max_count, count);
    }
    cout << max_count;
    return max_count;
}
*/
int main()
{
    vector<int> input = {100, 200, 1, 3, 2, 4};
    consecutive(input);
    return 0;
}
