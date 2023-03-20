#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int j = 0;
        if (nums.size() == 0)
            return 0;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[j])
            {
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};
/*
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        int size=s.size();
        nums.clear();
        for(auto x:s)
        {
            nums.push_back(x);
        }
        return size;
*/