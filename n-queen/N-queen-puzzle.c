#include <stdio.h>

int g_N = 8;

void ft_memset(char *arr, char c, int val)
{
	while(val--)
		*arr++ = c;
}

int ft_atoi(char *num)
{
	int			i;
	long		sign;
	long		result;

	i = 0;
	sign = 1;
	result = 0;
	while((num[i] >= 9 && num[i] <= 13) || num[i] == ' ')
		i++;
	if(num[i] == '-' || num[i] == '+')
		if(num[i++] == '-')
			sign = -1;
	while(num[i] >= '0' && num[i] <= '9')
	{
		result = result * 10 + (num[i] - '0');
		i++;
	}
	return (sign * result);
}


int N_Queens(int i, char *columns, char *y_equalX, char *y_equal_minusX)
{
	int result;
	int j;

	j = 0;
	result = 0;
	if(i == g_N)
		return (1);
	while(j < g_N)
	{
		if(columns[j] == 0 && y_equalX[i + j] == 0 && y_equal_minusX[j - i + g_N - 1] == 0) 
		{
			columns[j] = 1;
			y_equalX[i + j] = 1;
			y_equal_minusX[j - i + g_N - 1] = 1;
			result = result + N_Queens(i + 1, columns, y_equalX, y_equal_minusX);
			columns[j] = 0;
			y_equalX[i + j] = 0;
			y_equal_minusX[j - i + g_N - 1] = 0;
		}
		j++;
	}
	return (result);
}

int main(int argc, char **argv)
{
	if(argc == 2)
		g_N = ft_atoi(argv[1]);
	char col[g_N];
	ft_memset(col, '\0', g_N);
	char yX[g_N * 2 - 1];
 	ft_memset(yX, '\0', g_N * 2 - 1);
	char y_X[g_N * 2 - 1];
	ft_memset(y_X, '\0', g_N * 2 - 1);
	printf("%d\n", N_Queens(0, col, yX, y_X));
	return (0);
}
