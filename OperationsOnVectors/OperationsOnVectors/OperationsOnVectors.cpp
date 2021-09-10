// OperationsOnVectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include "OperationsOnVectors.h"
#define M_PI 3.14159265358979323846

OperationsOnVectors vectors = OperationsOnVectors();

using namespace std;

int main()
{
    array<float, 3>u = { 3,3,3 };
    array<float, 3>v = { 3,3,3 };

   float length = vectors.vectorsMultiplicationGeometrically(u, v, M_PI/6);
    cout << length << "   Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
