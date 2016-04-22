/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>

int path_recur(int *, int, int, int, int, int, int, int[][30]);

int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	int ans, memory[30][30] = { 0 };
	if (rows <= x1 || rows <= x2 || columns <= y1 || columns <= y2 || rows <= 0 || columns <= 0)
	{
		return 0;
	}
	ans = path_recur(maze, rows, columns, x1, y1, x2, y2, memory);
	return ans;
}
int path_recur(int *maze, int rows, int columns, int x1, int y1, int x2, int y2, int memory[][30])
{
	int x;
	if (rows <= x1 || (x1<0) || columns <= y1 || (y1<0))
	{
		return 0;
	}
	if (memory[x1][y1] != 0)
	{
		return 0;
	}
	if (*((maze + x1*columns) + y1) == 0)
	{
		return 0;
	}
	if (x2 == x1&&y2 == y1)
	{
		return 1;
	}
	memory[x1][y1] = 2;
	x1++;
	x = path_recur(maze, rows, columns, x1, y1, x2, y2, memory);
	if (x == 1)
	{
		return 1;
	}
	x1--;
	y1++;
	x = path_recur(maze, rows, columns, x1, y1, x2, y2, memory);
	if (x == 1)
	{
		return 1;
	}
	y1--;
	x1 = x1 - 1;
	x = path_recur(maze, rows, columns, x1, y1, x2, y2, memory);
	if (x == 1)
	{
		return 1;
	}
	x1++;
	y1 = y1 - 1;
	x = path_recur(maze, rows, columns, x1, y1, x2, y2, memory);
	if (x == 1)
	{
		return 1;
	}
	return 0;
}

