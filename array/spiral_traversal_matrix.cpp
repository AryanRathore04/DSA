#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();

        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;
        vector<int> ans;

        while (top <= bottom && left <= right)
        {
            // Left to Right
            for (int i = left; i <= right; i++)
            {
                ans.push_back(mat[top][i]);
            }
            top++;

            // Top to bottom
            for (int i = top; i <= bottom; i++)
            {
                ans.push_back(mat[i][right]);
            }
            right--;

            if (top <= bottom)
            {
                // Right to left
                for (int i = right; i >= left; i--)
                {
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }

            if (left <= right)
            {
                // Bottom to top
                for (int i = bottom; i >= top; i--)
                {
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        }
    }
};