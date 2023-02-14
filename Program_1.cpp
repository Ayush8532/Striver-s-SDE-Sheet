//: Given a matrix if an element in the matrix is 0 then you will have to set its entire column and row to 0 and then return the matrix.

// Input: matrix=[[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]

#include <bits/stdc++.h>
using namespace std;

/**
void setZero(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                int index = i - 1;
                while (index >= 0)
                {
                    if (matrix[index][j] != 0)
                    {
                        matrix[index][j] = -1;
                    }
                    index--;
                }
                index = i + 1;
                while (index < row)
                {
                    if (matrix[index][j] != 0)
                    {
                        matrix[index][j] = -1;
                    }
                    index++;
                }
                index = j - 1;
                while (index >= 0)
                {
                    if (matrix[i][index] != 0)
                    {
                        matrix[i][index] = -1;
                    }
                    index--;
                }
                index = j + 1;
                while (index < col)
                {
                    if (matrix[i][index] != 0)
                    {
                        matrix[i][index] = -1;
                    }
                    index++;
                }
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0 || matrix[i][j] == -1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}
**/

// Optimized way------------------

void setZero(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();

    vector<int> dummy1(row, -1);
    vector<int> dummy2(col, -1);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == 0)
            {
                dummy1[i] = 0;
                dummy2[j] = 0;
            }
        }
    }
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (dummy1[i] == 0 || dummy2[j] == 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    vector<vector<int>> matrix;

    matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}};
    setZero(matrix);
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[0].size(); j++)
        {
            cout << matrix[i][j] << endl;
        }
    }
}
