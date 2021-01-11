#include <stdio.h>

void	show_board(char *board)
{
	int i;

	i = 0;
	while (i < 3)
	{
		printf("%c | %c | %c\n", board[0 + 3 * i], board[1 + 3 * i], board[2 + 3 * i]);
		printf("____________\n");
		i++;
	}
}

int		main(void)
{
	char player_choice;

	player_choice = 0;
	do
	{
		printf("Select X or O\n");
		scanf(" %c", &player_choice); //whitespace specificator cool
	}
	while (player_choice != 'X' && player_choice != 'O');

	char board[9] = { 'X', 'O', 'X', ' ', ' ', 'X', ' ', 'O', 'X' };
	show_board(board);
	return (0);
}
