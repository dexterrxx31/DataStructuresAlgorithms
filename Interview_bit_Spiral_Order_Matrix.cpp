// Spiral Order Matrix I
// https://www.interviewbit.com/problems/spiral-order-matrix-i/
#include <iostream>
#include <vector>
using namespace std;

vector<int> Spiral_Matrix(vector<vector<int>> &matrix)
{
    vector<int> spiralled_Matrix;
    int top_left, top_right, bottom_left, bottom_right;
    top_left = 0;
    top_right = matrix[0].size() - 1;
    bottom_left = 0;
    bottom_right = matrix.size() - 1;
    while (top_left <= matrix.size() / 2)
    {
        if (top_left == top_right && bottom_left == bottom_right && top_left ==bottom_left && top_right == bottom_right && top_right == bottom_left && top_left == bottom_right)
        {
            spiralled_Matrix.push_back(matrix[top_left][top_left]);
            break;
        }
        for (int i = top_left; i <= top_right; i++)
        {
            spiralled_Matrix.push_back(matrix[top_left][i]);
        }
        top_left++;
        for (int i = top_left; i <= bottom_right; i++)
        {
            spiralled_Matrix.push_back(matrix[i][top_right]);
        }
        top_right--;
        for (int i = top_right; i >= bottom_left; i--)
        {
            spiralled_Matrix.push_back(matrix[bottom_right][i]);
        }

        bottom_right--;
        for (int i = bottom_right; i >= top_left; i--)
        {
            spiralled_Matrix.push_back(matrix[i][bottom_left]);
        }
        bottom_left++;
    }
    return spiralled_Matrix ;
}

void vector_traversal(vector<int> ret)
{
    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << "|";
    }
}
int main()
{
    /*
[
    [ 1, 2, 3 ],
    [ 4, 5, 6 ],
    [ 7, 8, 9 ]
]
*/
    vector<vector<int>> matrix;
    matrix = {
        {1, 2},
        {5, 6},
        };
    vector<int> spiralled_Matrix = Spiral_Matrix(matrix);
    vector_traversal(spiralled_Matrix);

    return 0;
}