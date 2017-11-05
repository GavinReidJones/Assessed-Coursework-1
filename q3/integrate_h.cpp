// integrate_h.cpp : Defines the entry point for the console application.
//
// Program written by Gavin Reid-Jones for Assesed Course Work 1 last edited 3/11/17

//include statements to allow the program to access in/out fuctionality and maths functions .
#include "stdafx.h"
#include <iostream>
#include <cmath>

//Allows the program to call functions from the standard library without referencing it.
using namespace std;


void AllocateVertices(double **coordinates)
{
	coordinates[0][0] = 0.1;
	coordinates[1][0] = 0.0; 
	coordinates[0][1] = 0.7;
	coordinates[1][1] = 0.2;
	coordinates[0][2] = 1.0;
	coordinates[1][2] = 0.5;
	coordinates[0][3] = 0.75;
	coordinates[1][3] = 0.85;
	coordinates[0][4] = 0.5;
	coordinates[1][4] = 0.1;
	coordinates[0][5] = 0.0;
	coordinates[1][5] = 0.25;
	
	return;
}

void AllocateEdges(double **coordinates, double **edges)
{
	for (int i =0; i <2;i++)
	{
		for (int j = 0; j <6; j++)
		{
			if (j < 5)
			{
				edges[i][j] = coordinates[i][j + 1] - coordinates[i][j];
			}
			else
			{
				edges[i][j] = coordinates[i][0] - coordinates[i][j];
			}
		}
	}
}

void AllocateNormals(double **normal)
{
	normal[0][0] = 0.2;
	normal[1][0] = -0.6;
	normal[0][1] = 0.3;
	normal[1][1] = -0.3;
	normal[0][2] = 0.35;
	normal[1][2] = 0.25;
	normal[0][3] = 0.25;
	normal[1][3] = 0.15;
	normal[0][4] = -1.0;
	normal[1][4] = 0.5;
	normal[0][5] = -0.25;
	normal[1][5] = -0.1;
}

void Integrate_h(double n, double **quadrature, double result)
{	
	double dDegreeq, dMapping,dNumberofEdges =6 ;

	double **dVertices;
	//defines the first layer of the 2d array
	dVertices = new double*[2];
	//adds the correct number of columns to the 2d array
	for (int i = 0; i < 2; i++)
	{
		dVertices[i] = new double[6];
	}

	double **dEdges;
	//defines the first layer of the 2d array
	dEdges = new double*[2];
	//adds the correct number of columns to the 2d array
	for (int i = 0; i < 2; i++)
	{
		dEdges[i] = new double[6];
	}

	double **dNormals;
	//defines the first layer of the 2d array
	dNormals = new double*[2];
	//adds the correct number of columns to the 2d array
	for (int i = 0; i < 2; i++)
	{
		dNormals[i] = new double[6];
	}


	AllocateVertices(dVertices);
	AllocateEdges(dVertices, dEdges);
	AllocateNormals(dNormals);

	// deletes the columns of the matrix used for the vertices once it has performed the calculation to find the edges of the polygon.
	for (int i = 0; i < 2; i++)
	{
		delete[] dVertices[i];
	}

	// deletes the rows of the matrix
	delete[] dVertices;


	//maps 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			
				dMapping = (0.5*quadrature[0][i] + 0.5)*dEdges[i][j];
				dEdges[i][j] = dMapping;
			
		}

	}

	double dDotproduct, hx, summation;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			dDotproduct = dEdges[0][j] * dNormals[0][j] + dEdges[1][j] * dNormals[1][j];
			hx = pow(dEdges[0][j], 5)*pow(dEdges[1][j], 3);
			summation = dDotproduct*hx*quadrature[1][i]
			
		}
	}
	return;
	

}
