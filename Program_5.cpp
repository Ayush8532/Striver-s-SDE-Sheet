// Given an array consisting of only 0s, 1s and 2s. Write a program to in-place sort the array without using inbuilt sort functions. ( Expected: Single pass-O(N) and constant space)

// Input: nums = [2,0,2,1,1,0]
// Output : [ 0, 0, 1, 1, 2, 2 ]

#include <bits/stdc++.h>
using namespace std;


/**
void sort(vector<int> &nums)
{
    int zero, one, two;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0)
        {
            zero++;
        }
        else if (nums[i] == 1)
        {
            one++;
        }
        else
        {
            two++;
        }
    }
    nums.clear();
    while (zero != 0)
    {
        nums.push_back(0);
        zero--;
    }
    while (one != 0)
    {
        nums.push_back(1);
        one--;
    }
    while (two != 0)
    {
        nums.push_back(2);
        two--;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
}

**/

//Optimized----

void sort(vector<int>v)
{
    int low = 0,mid=0,high=v.size()-1;
    while(mid<=high)
    {
        switch (v[mid])
        {
        case 0:
            swap(v[mid++], v[low++]);
            break;
        case 1:
            mid++;
            break;
        case 2:
            swap(v[mid++], v[high--]);
            break;
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
int main()
{
    vector<int> v = {2, 0, 2, 1, 1, 0};
    sort(v);
    return 0;
}
