#include <unistd.h>
#include <stdio.h>

int EightQueens(int i, char *columns, char *y_equalX, char *y_equal_minusX)
{
	int result;
	int j;

	j = 0;
	result = 0;
	if(i == 8)
		return (1);
	while(j < 8)
	{
		if(columns[j] == 0 && y_equalX[i + j] == 0 && y_equal_minusX[j - i + 7] == 0) 
		{
			columns[j] = 1;
			y_equalX[i + j] = 1;
			y_equal_minusX[j - i + 7] = 1;
			result = result + EightQueens(i + 1, columns, y_equalX, y_equal_minusX);
			columns[j] = 0;
			y_equalX[i + j] = 0;
			y_equal_minusX[j - i + 7] = 0;
		}
		j++;
	}
	return (result);
}

int main(/*int argc, char **argv*/)
{
	char col[8] = {0};
	char yX[15] = {0};
	char y_X[15] = {0};

	//if(argc == 2)
		printf("%d\n", EightQueens(0, col, yX, y_X));
	return (0);
}
