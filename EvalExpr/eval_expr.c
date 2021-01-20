#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(long num)
{
	char remainder;

	if (num < 0)
	{
		ft_putchar('-');
		num = -num;
	}
	remainder = (num % 10) + '0';
	if (num / 10 > 0)
		ft_putnbr(num / 10);
	ft_putchar(remainder);
}

int eval_expr(char *str)
{
	int operand1;
	int operand2;

	operand1 = ft_atoi(str);
}
