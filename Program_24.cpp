// Given a String, find the length of longest substring without any repeating character.

// Input: s = ”abcabcbb”
// Output: 3

#include <bits/stdc++.h>
using namespace std;

// OPTIMIZED_____________________________________

int repeat(string s)
{
    unordered_set<int> st;
    int l = 0;
    int length = INT_MIN;
    for (int r = 0; r < s.length(); r++)
    {
        if (st.find(s[r]) != st.end())
        {
            while (l < r && st.find(s[r]) != st.end())
            {
                st.erase(s[l]);
                l++;
            }
        }
        st.insert(s[r]);
        length = max(length, r - l + 1);
    }
    cout << length;
    return length;
}
/*BRUTE FORCE___________________________________
int repeat(string s)
{
    unordered_set<int> st;
    int maxi = INT_MIN;
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
        {
            if (st.find(s[j]) != st.end())
            {
                maxi = max(maxi, j - i);
                break;
            }
            else
            {
                st.insert(s[j]);
            }
        }
    }
    cout << maxi;
    return maxi;
}
*/
int main()
{
    string s = "abcabcbb";
    repeat(s);
    return 0;
}