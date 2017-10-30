// q2a.cpp : Defines the entry point for the console application.
//
// Program written by Gavin Reid-Jones for Assesed Course Work 1 last edited 30/10/17

//include statements to allow the program to access in/out fuctionality, maths functions and the vector class.
#include "stdafx.h"
#include <iostream>
#include <cmath>

//Allows the program to call functions from the standard library without referencing it.
using namespace std;

// Declaring the functions that are used from the other .cpp files.
void quadrature(double n, double **quadrature);

int main()
{
	//values that the Legendre function uses to calculate the result
	double dNval = 4;
	//pointer variable that acts as the array
	double **dQuadrature;
	
	//defines the first layer of the 2d array
	dQuadrature = new double*[2];
	//adds the correct number of columns to the 2d array
	for (int i = 0; i < 2; i++)
	{
		dQuadrature[i] = new double[dNval];
	}

	//calls the quadrature function, while passing the n value given by the user and the array declared previously
	quadrature(dNval, dQuadrature);

	//prints a display of the result of the quadrature function
	cout << "The Guass Quadrature for n = " << dNval << " is : \n";
	cout << "x";
	for (int i = 1; i < dNval + 1; i++)
	{
		cout << " " << dQuadrature[0][i-1] << " ";
	}
	cout << "\n" << "w";
	for (int i = 1; i < dNval + 1; i++)
	{
		cout << " " << dQuadrature[1][i - 1] << " ";
	}
	cout << "\n \n";
	
	return 0;
}

