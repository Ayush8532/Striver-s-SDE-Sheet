//Problem Statement: Given an m*n 2D matrix and an integer, write a program to find if the given integer exists in the matrix.Given matrix has the following properties:Integers in each row are sorted from left to right.The first integer of each row is greater than the last integer of the previous row

//Input: matrix = [[1,3,5,7], [10,11,16,20],[23,30,34,60]], 
//target = 3
//Output: true



#include <bits/stdc++.h>
using namespace std;

/**Brute Force appproach_____________________

 bool mat(vector<vector<int>> v, int target)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] == target)
            {
                cout << "True";
                return true;
            }
        }
    }
    cout << "False";
    return false;
}
*/

/*SECOND APPROACH__________________________
        int i=0,j=matrix[0].size()-1;
        while(i<matrix.size()&&j>=0)
        {
            if(matrix[i][j]==target)
                return true;
            else if(matrix[i][j]>target)
                j--;
            else 
                i++;
        }
        return false;
*/

// OPTIMIZED____________________________

int mat(vector<vector<int>> v, int target)
{
    int start = 0;
    int end = (v.size() * v[0].size()) - 1;
    int mid;
    while (start <= end)
    {
        mid = start + (end - start) / 2;
        if (v[mid / v[0].size()][mid % v[0].size()] == target)
        {

            cout << "True";
            return 0;
        }
        else if (v[mid / v[0].size()][mid % v[0].size()] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    cout << "False";
    return 0;
}
int main()
{
    vector<vector<int>> v = {
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 34;
    mat(v, target);
    return 0;
}