#pragma once
#include <iostream>
#include <array>
#include <cmath>

#define M_PI 3.14159265358979323846

using namespace std;

class OperationsOnVectors
{
public:

	array<float, 2> addition(array<float, 2> u, array<float, 2> v) {
		float valX = u[0] + v[0];
		float valY = u[1] + v[1];
		return { valX, valY };
	}

	array<float, 2> subtraction(array<float, 2> u, array<float, 2> v) {
		float valX = u[0] - v[0];
		float valY = u[1] - v[1];
		return { valX, valY };
	}

	float lengthCalculationInR2(array<float, 2> u) {
		float length = sqrt(pow(u[0], 2) + pow(u[1], 2));
		return length;
	}

	float lengthCalculationInR3(array<float, 3> u) {
		float length = sqrt(pow(u[0], 2) + pow(u[1], 2) + pow(u[2], 2));
		return length;
	}

	array<float, 2> scalarMultiplication(array<float, 2> u, float scalar) {
		float valX = u[0] * scalar;
		float valY = u[1] * scalar;
		return { valX, valY };
	}


	float dotProductAlgebraically(array<float, 2> u, array<float, 2> v) {
		float val = 0;
		for (int i = 0; i < 2; i++) {
			val += u[i] * v[i];
		}
		return val;
	}

	float dotProductGeometrically(array<float, 2> u, array<float, 2> v, float angleBetweenUandV) {
		float cosine;
		if (angleBetweenUandV > M_PI) {
			cosine = cos(2 * M_PI - angleBetweenUandV);
		}
		else {
			cosine = cos(angleBetweenUandV);
		}

		float length1 = lengthCalculationInR2(u);
		float length2 = lengthCalculationInR2(v);

		return length1 * length2 * cosine;
	}


	array<float, 3> vectorsMultiplicationAlgebraically(array<float, 3> u, array<float, 3> v) {
		float valX = u[1] * v[2] - u[2] * v[1];
		float valY = u[2] * v[0] - u[0] * v[2];
		float valZ = u[0] * v[1] - u[1] * v[0];

		return { valX, valY, valZ };
	}

	float vectorsMultiplicationGeometrically(array<float, 3> u, array<float, 3> v, float angleBetweenUandV) {
		float sine;
		if (angleBetweenUandV > M_PI) {
			sine = sin(2 * M_PI - angleBetweenUandV);
		}
		else {
			sine = sin(angleBetweenUandV);
		}

		float length1 = lengthCalculationInR3(u);
		float length2 = lengthCalculationInR3(v);

		return length1 * length2 * sine;
	}

};

