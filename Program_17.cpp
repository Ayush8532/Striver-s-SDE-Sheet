// Problem Statement: Given a matrix m X n, count paths from left-top to the right bottom of a matrix with the constraints that from each cell you can either only move to the rightward direction or the downward direction.

// Input Format: m = 2, n= 2
// Output : 2

#include <bits/stdc++.h>
using namespace std;
/*Optimized________________*/

int uniquepath(int m, int n)
{
    int R = m + n - 2;
    int r = m - 1;
    int res = 1;
    for (int i = 1; i <= r; i++)
    {
        res = res * (R - r + i) / i;
    }
    return res;
}

/* 2nd Approach______________________________________
int countpath(int i, int j, int m, int n, vector<vector<int>> &v)
{
    if (i == (m - 1) && j == (n - 1))
        return 1;
    if (i >= m || j >= n)
        return 0;
    else
    {
        return v[i][j] = countpath(i + 1, j, m, n, v) + countpath(i, j + 1, m, n, v);
    }
}
int uniquepath(int m, int n)
{
    vector<vector<int>> v(m + 1, vector<int>(n + 1, -1));
    int num = countpath(0, 0, m, n, v);
    if (m == 1 && n == 1)
        return num;
    return v[0][0];
}
*/

/*Brute Force_______________________________
int countpath(int i, int j, int m, int n)
{
    if (i == (m - 1) && j == (n - 1))
        return 1;
    if (i >= m || j >= n)
        return 0;
    else
    {
        return countpath(i + 1, j, m, n) + countpath(i, j + 1, m, n);
    }
}
int uniquepath(int m, int n)
{
    return countpath(0, 0, m, n);
}
*/
int main()
{
    int m = 3, n = 7;
    int total = uniquepath(m, n);
    cout << total;
    return 0;
}
