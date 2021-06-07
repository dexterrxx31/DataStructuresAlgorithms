#include <iostream>
#include <vector>
using namespace std;

int is_multiplicable(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
    return matrix1[0].size() == matrix2.size();
}

vector<vector<int>> multiply_two_Matrices(vector<vector<int>> matrix1, vector<vector<int>> matrix2)
{
    vector<vector<int>> resultant_matrix(matrix1.size(), vector<int>(matrix2[0].size()));
    int element;
    for (int i = 0; i < matrix1[0].size(); i++)
    {

        for (int j = 0; j < matrix2.size(); j++)
        {
            resultant_matrix[i][j] = 0;
            for (int k = 0; k < matrix1[0].size(); k++)
            {
                resultant_matrix[i][j] +=matrix1[i][k] * matrix2[k][j];
            }
        }
    }
     return resultant_matrix ;
}
int main()
{
    int row1, row2, col1, col2, sequence;
    sequence = 0;
    row1 = 3;
    col1 = 3;
    row2 = 3;
    col2 = 3;
    vector<vector<int>> matrix1(row1, vector<int>(col1));
    vector<vector<int>> matrix2(row2, vector<int>(col2));
    for (int i = 0; i < matrix1.size(); i++)
    {
        for (int j = 0; j < matrix1[0].size(); j++)
        {
            matrix1[i][j] = sequence++;
        }
    }

    for (int i = 0; i < matrix1.size(); i++)
    {
        for (int j = 0; j < matrix1[0].size(); j++)
        {
            cout << matrix1[i][j] << "|";
        }
        cout << endl;
    }

    for (int i = 0; i < matrix2.size(); i++)
    {
        for (int j = 0; j < matrix2[0].size(); j++)
        {
            matrix2[i][j] = sequence++;
        }
    }

    for (int i = 0; i < matrix2.size(); i++)
    {
        for (int j = 0; j < matrix2[0].size(); j++)
        {
            cout << matrix2[i][j] << "|";
        }
        cout << endl;
    }

    if (is_multiplicable(matrix1, matrix2))
    {
        cout << "Yes! Matrix is Multiplicable" << endl;
    }
    else
    {
        cout << "No! Matrix is not Multiplicable" << endl;
    }
    //multiply_two_Matrices(matrix1, matrix2);
    vector< vector <int>> result = multiply_two_Matrices(matrix1 , matrix2) ;
    for(int i = 0 ; i < result.size() ; i++)
    {
        for(int j = 0 ; j < result[0].size() ; j++)
        {
            cout<<result[i][j]<<"|";
        }
        cout<<endl;
    }
    return 0;
}