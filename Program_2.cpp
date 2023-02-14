// Pascal's Triangle: Given an integer numRows, return the first numRows of Pascal's triangle.

// Input: numRows = 5
// Output : [ [1], [ 1, 1 ], [ 1, 2, 1 ], [ 1, 3, 3, 1 ], [ 1, 4, 6, 4, 1 ] ]

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> pascal(int numRows)
{
    vector<vector<int>> answer(numRows);
    for (int i = 0; i < numRows; i++)
    {
        answer[i].resize(i + 1);
        answer[i][0] = answer[i][i] = 1;
        for (int j = 1; j < i; j++)
        {
            answer[i][j] = answer[i - 1][j - 1] + answer[i - 1][j];
        }
    }
    for (int i = 0; i < numRows; i++)
    {
        for (int j = 0; j < answer[i].size(); j++)
        {
            cout << answer[i][j];
        }
    }
    return answer;
}
int main()
{
    int numRows = 5;
    pascal(numRows);
    return 0;
}
