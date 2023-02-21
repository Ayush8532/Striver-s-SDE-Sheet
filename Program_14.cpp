// Problem Statement: Given a double x and integer n, calculate x raised to power n. Basically Implement pow(x, n).

// Input: x = 2.10000, n = 3
// Output : 9.26100

#include <bits/stdc++.h>
using namespace std;

/**OPTIMIZED_______________________________*/

double mypow(double x, int n)
{
    long long temp = n;
    double ans = 1.0;

    if (temp < 0)
        temp *= -1;
    while (temp)
    {
        if (temp % 2 == 0)
        {
            x = x * x;
            temp = temp / 2;
        }
        else
        {
            ans = ans * x;
            temp = temp - 1;
        }
    }
    if (n < 0)
        ans = (double)1.0 / (double)(ans);
    return ans;
}
/*BRUTE FORCE_________________________________
double mypow(double x, int n)
{
    int pow = n;
    if (n < 0)
        pow = pow * -1;
    double temp = x;
    for (int i = 0; i < pow; i++)
    {
        if (n < 0)
        {
            x = 1 / temp * x;
        }
        else
        {
            x *= temp;
        }
    }
    return x;
}
*/
int main()
{
    cout << mypow(2, -2);
}