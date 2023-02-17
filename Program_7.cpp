// Problem Statement: Given a matrix, your task is to rotate the matrix 90 degrees clockwise.

// Input: [[1,2,3],[4,5,6],[7,8,9]]
// Output: [[7,4,1],[8,5,2],[9,6,3]

#include <bits/stdc++.h>
using namespace std;

/**BRUTE FORCE___________________

vector<vector<int>> rotated(vector<vector<int>> matrix)
{
    int n = matrix.size();
    vector<vector<int>> rotate(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            rotate[j][n - i - 1] = matrix[i][j];
        }
    }
    return rotate;
}
*/

// OPTIMIZED______________________________

vector<vector<int>> rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
    return matrix;
}

int main()
{
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    rotate(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}