#include "tic-tac-toe.h"

int get_chances(char *board, char order, int move)
{
	int i;
	int result;
	int temp;

	i = 0;
	result = 0;
	temp = check_result(board);
	if (temp == g_ai_choice)
		return (10000);
	if (temp == g_player_choice)
		return (-1);
	if (move == 8)
		return (1);

	while (i < 9)
	{
		if (board[i] != ' ')
		{
			i++;
			continue;
		}
		board[i] = order;
		temp = get_chances(board, g_XO ^ order, move + 1);
		board[i] = ' ';
		if (temp > 0)
			result += temp;
		else if (temp < 0 && order != g_ai_choice)
			return (-1);
		i++;
	}
	if (result == 0 && order == g_ai_choice)
		return (-1);
	return (result);
}

void	ai_move(char *board)
{

	int		i;
	int		max;
	int		max_index[9];
	int		max_count;
	int		temp;

	i = 0;
	max_count = 0;
	max = -1;
	printf("AI move is: \n");
	while (i < 9)
	{
		if(board[i] != ' ')
		{
			i++;
			continue;
		}
		board[i] = g_ai_choice;
		temp = get_chances(board, g_player_choice, g_moves_count);
		board[i] = ' ';
		printf("%d\n",temp);
		if((temp > 0) && ((max == -1) ||\
			((temp / 10000 * (max % 10000 + max / 10000)) > (max / 10000 * (temp % 10000 + temp / 10000)))))
		{
			max_count = 1;
			max_index[0] = i;
			max = temp;
		}
		else if((temp > 0) && ((temp / 10000 * (max % 10000 + max / 10000)) == (max / 10000 * (temp % 10000 + temp / 10000))))
		{
			max_index[max_count] = i;
			max_count++;
		}
		i++;
	}
	srand(time(0));
	printf("\n%d\n", max);
	board[max_index[rand() % max_count]] = g_ai_choice;
}

void	random_ai_move(char *board)
{
	int i;

	srand(time(NULL));
	i = rand() % 9;
	printf("Random AI move is: \n");
	while (board[i] != ' ')
		if (++i > 8)
			i = 0;
	board[i] = g_ai_choice;
}
