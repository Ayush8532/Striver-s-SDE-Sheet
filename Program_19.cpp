// Problem Statement: Given an array of integers nums[] and an integer target, return indices of the two numbers such that their sum is equal to the target.

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]

#include <bits/stdc++.h>
using namespace std;

/*OPTIMIZED_____________________*/
vector<int> twoSum(vector<int> nums, int target)
{
    vector<int> ans;
    unordered_map<int, int> m;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m.find(target - nums[i]) != m.end())
        {
            ans.push_back(m[target - nums[i]]);
            ans.push_back(i);
            break;
        }
        m[nums[i]] = i;
    }
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
    return ans;
}

/**BRUTE FORCE______________________________

vector<int> twoSum(vector<int> nums, int target)
{
    vector<int> answer;
    for (int i = 0; i < nums.size() - 1; i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                answer.push_back(i);
                answer.push_back(j);
            }
        }
    }
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    return answer;
}
*/
int main()
{
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    twoSum(nums, target);
    return 0;
}