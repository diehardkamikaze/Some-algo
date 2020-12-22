#include <unistd.h>
#include <stdio.h>

int EightQueens(int i, int *columns, int *y_equalX, int *y_equal_minusX)
{
	int result;
	int j;

	j = 0;
	result = 0;
	if(i == 8)
		return (1);
	while(j < 8)
	{
		if(columns[j] == 0 && y_equalX[i+j] == 0 && y_equal_minusX[j - i + 8] == 0) 
		{
			columns[j] = 1;
			y_equalX[i+j] = 1;
			y_equal_minusX[j - i + 8] = 1;
		//	printf("%d %d %d\n", i, i+j, 8 - j + i);
			result = result + EightQueens(i + 1, columns, y_equalX, y_equal_minusX);
			columns[j] = 0;
			y_equalX[i+j] = 0;
			y_equal_minusX[j - i + 8] = 0;
		}
		j++;
	}
	return (result);
}

int main(int argc, char **argv)
{
	char c = '0';
	int col[8] = {0};
	int yX[15] = {0};
	int y_X[16] = {0};

	if(argc == 2)
	{
		int g = EightQueens(0, col, yX, y_X);
		printf("%d", g);
	}
	write(1, "\n", 1);
	return (0);
}
