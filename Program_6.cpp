// Problem: You are given an array of prices where prices[i] is the price of a given stock on an ith day.You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.Return the maximum profit you can achieve from this transaction.If you cannot achieve any profit, return 0.

// Input: prices = [7,1,5,3,6,4]
// Output : 5

#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int max_profit = 0;
    int mini = INT_MAX;
    for (int i = 0; i < prices.size(); i++)
    {
        mini = min(mini, prices[i]);
        max_profit = max(max_profit, prices[i] - mini);
    }
    cout << max_profit;
    return max_profit;
}
/**Brute Force---

    int max_profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            max_profit = max(max_profit, prices[j] - prices[i]);
        }
    }
**/