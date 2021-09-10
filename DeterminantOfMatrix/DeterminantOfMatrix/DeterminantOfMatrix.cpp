#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<double>> matrix = {
    {1,2,3},
    {2,3,4},
    {4,5,6}
};
double multiplier = 1;

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

                if (firstColumnZeros == matrix.size()-1) {
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

int main()
{
    double determin = determinant(matrix, multiplier);
    cout << determin << endl;
}