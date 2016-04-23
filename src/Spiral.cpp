/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

void spiralrecurr1(int**, int, int,int,int*,int);
int *spiral(int rows, int columns, int **input_array)
{
	if (input_array==NULL||rows<1||columns<1)
		return NULL;
	int *a = (int*)malloc(sizeof(int)*rows*columns);
	spiralrecurr1(input_array,rows,columns,0,a,0);
	return a;
}

void spiralrecurr1(int **input_array, int rows, int columns,int start_index, int *a,int index)
{
	int i;
	if (index>=rows*columns)
	{
		return;
	}
	for (i =start_index; i < columns-start_index; i++)
	{
		a[index] = input_array[start_index][i];
		index++;
	}
	if (index >= rows*columns)
	{
		return;
	}
	for (i = start_index + 1; i < rows-start_index; i++)
	{
		a[index] = input_array[i][columns-start_index-1];
		index++;
	}
	if (index >= rows*columns)
	{
		return;
	}
	for (i = columns - 2-start_index; i >= start_index; i--)
	{
		a[index] = input_array[rows - 1-start_index][i];
		index++;
	}
	if (index >= rows*columns)
	{
		return;
	}
	for (i = rows - 2-start_index; i > start_index; i--)
	{
		a[index] = input_array[i][start_index];
		index++;
	}
	if (index >= rows*columns)
	{
		return;
	}

	start_index++;
	spiralrecurr1(input_array, rows, columns, start_index, a, index);
	return;
}