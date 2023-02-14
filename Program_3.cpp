// Next Permutation

// Input: nums = [1,2,3]
// Output : [ 1, 3, 2 ]

#include <bits/stdc++.h>
using namespace std;

/**Using in-built Function-----------------------

int main()
{
    int arr[] = {1, 2, 3};
    next_permutation(arr, arr + 3);
    cout << arr[0] << " " << arr[1] << arr[2];
    return 0;
}
*/

int main()
{
    vector<int> arr = {1, 3, 2};
    int n = arr.size(), i, j;
    for (i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            break;
        }
    }
    if (i < 0)
        reverse(arr.begin(), arr.end());
    else
    {
        for (j = n - 1; j > i; j--)
        {
            if (arr[j] > arr[i])
            {
                break;
            }
        }
        swap(arr[i], arr[j]);
        reverse(arr.begin() + i + 1, arr.end());
    }
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}