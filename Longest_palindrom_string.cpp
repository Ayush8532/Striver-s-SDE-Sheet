#include<bits/stdc++.h>
using namespace std;

string longest(string s)
{
    int n = s.length();
    string ans = "";
    bool mat[n][n];
    memset(mat, 0, sizeof(mat));
    int maxLength = 1;
    for (int i = 0; i < n; i++)
    {
        mat[i][i] = true;
    }
    int start = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            mat[i][i + 1] = true;
            start = i;
            maxLength = 2;
        }
    }
    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (mat[i + 1][j - 1] && s[i] == s[j])
            {
                mat[i][j] = true;
                if (k > maxLength)
                {
                    start = i;
                    maxLength = k;
                }
            }
        }
    }
    for (int i = start; i < start + maxLength; i++)
    {
        ans += s[i];
    }
    return ans;
}
int main(){
    string s="babad";
    longest(s);
    return 0;
}

/*Brute Force approach---
    string longestPalindrome(string s)
    {
        int length = s.size();
        if (length == 1 || length == 0)
            return s;
        int start = 0, maxLength = 1;
        string sub;
        for (int i = 0; i < length; i++)
        {
            for (int j = i; j < length; j++)
            {
                int flag = 1;
                for (int k = 0; k < j - i + 1; k++)
                {
                    if (s[i + k] != s[j - k])
                    {
                        flag = 0;
                    }
                }
                if (flag && (j - i + 1) > maxLength)
                {
                    start = i;
                    maxLength = j - i + 1;
                    sub = s.substr(start, maxLength);
                }
            }
        }
        return sub;
    }
*/