#include <bits/stdc++.h>
using namespace std;

void reverseWords(string s)
{
    string result;
    int i = 0;
    int n = s.length();
    while (i < n)
    {
        while (i < n && s[i] == ' ')
            i++;
        if (i >= n)
            break;
        int j = i + 1;
        while (j < n && s[j] != ' ')
            j++;
        string sub = s.substr(i, j - i);
        if (result == "")
            result = sub;
        else
            result = sub + " " + result;
        i = j + 1;
    }
    cout << result;
}
int main()
{
    string s = "  Hello! World  ";
    reverseWords(s);
    return 0;
}