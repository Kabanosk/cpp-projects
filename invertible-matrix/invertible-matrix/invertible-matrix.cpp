#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<double>> matrix = {
    {2,2,4,2,2},
    {0,2,2,4,2},
    {4,2,4,2,2},
    {2,4,2,6,2},
    {2,4,2,2,4}
};


double determinant(vector<vector<double>> matrix, double multiplier) {

    vector<double> tmpRow;
    vector<vector<double>> tmpMatrix;

    if (matrix[0].size() == 2) {
        return (matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]) * multiplier;
    }
    else {
        if (matrix[0][0] == 0) {
            unsigned int firstColumnZeros = 0;
            for (unsigned int i = 1; i < matrix.size(); i++) {
                if (matrix[i][0] != 0) {
                    matrix[0].swap(matrix[i]);
                    multiplier *= -1;
                    firstColumnZeros = 0;
                    break;
                }
                else
                    firstColumnZeros++;

                if (firstColumnZeros == matrix.size() - 1) {
                    return 0;
                }
            }
        }
        long double firstRowDivider = matrix[0][0];
        for (unsigned int j = 0; j < matrix[0].size(); j++) {
            matrix[0][j] /= firstRowDivider;
        }
        multiplier *= firstRowDivider;


        for (unsigned int i = 1; i < matrix.size(); i++) {
            long double rowDivider = matrix[i][0];
            for (unsigned int j = 1; j < matrix[0].size(); j++) {
                tmpRow.push_back(matrix[i][j] - matrix[0][j] * rowDivider);
            }
            tmpMatrix.push_back(tmpRow);
            tmpRow.clear();
        }
    }

    return determinant(tmpMatrix, multiplier);
}

bool isSingular(vector<vector<double>> matrix) {
    double det = determinant(matrix, 1);
    if (det == 0)
        return true;
    else
        return false;
}
vector<vector<double>> cofactorOfMatrix( vector<vector<double>> matrix ) {

    vector<vector<double>> cofactorMatrix, tmpMatrix;
    vector<double> rowOfDeterminants;

    for (unsigned int i = 0; i < matrix.size(); i++) {
        for (unsigned int j = 0; j < matrix.size(); j++) {
            tmpMatrix = matrix;
            tmpMatrix.erase(tmpMatrix.begin() + i);
            for (unsigned int k = 0; k < tmpMatrix.size(); k++) {
                tmpMatrix[k].erase(tmpMatrix[k].begin() + j);
            }
                rowOfDeterminants.push_back(determinant(tmpMatrix, pow(-1,i+j)));
            
        }
        cofactorMatrix.push_back(rowOfDeterminants);
        rowOfDeterminants.clear();
    }

    return cofactorMatrix;
}

vector<vector<double>> transpose(vector<vector<double>> matrix) {

    vector<vector<double>> transposedMatrix = matrix;

    for (unsigned int i = 0; i < matrix.size(); i++) 
        for (unsigned int j = 0; j < matrix.size(); j++) 
            transposedMatrix[i][j] = matrix[j][i];

        
    

    return transposedMatrix;
}

vector<vector<double>> divisionByDeterminant(vector<vector<double>> matrix, double det) {

    for (unsigned int i = 0; i < matrix.size(); i++) 
        for (unsigned int j = 0; j < matrix.size(); j++) 
            matrix[i][j] /= det;

    return matrix;
}

vector<vector<double>> inverseOfMatrix(vector<vector<double>> matrix) {

    if (isSingular(matrix))
        return { {} };

    double det = determinant(matrix, 1);

    matrix = cofactorOfMatrix(matrix);
    matrix = transpose(matrix);
    matrix = divisionByDeterminant(matrix, det);
    return matrix;
}

int main()
{
    vector<vector<double>> determinan = inverseOfMatrix( matrix );
    for (unsigned int i = 0; i < determinan.size(); i++) {
        for (unsigned int j = 0; j < determinan.size(); j++) {
            cout << determinan[i][j] << ", ";
        }
        cout << endl;
    }
}
