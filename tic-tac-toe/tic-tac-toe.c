#include <stdio.h>
#include <string.h>

char	g_player_choice;

void	show_board(char *board)
{
	int i;

	i = 0;
	while (i < 3)
	{
		printf("%c | %c | %c\n", board[0 + 3 * i], board[1 + 3 * i], board[2 + 3 * i]);
		printf("----------\n");
		i++;
	}
}

void	player_move(char *board)
{
	int i;
	printf("You play for %c\n", g_player_choice);
	do {
		printf("Your move: (0 - 8): \n");
		scanf("%d", &i);
	}
	while(board[i] != ' ' && printf("Incorrect! Choose only empty cells!\n"));
	board[i] = g_player_choice;
}
/*
void	AI_move(char *board)
{
	int i;
	int ai_variants[8][2];

	i = 0;

	while (i < 8)
	{
		if (i != ' ')
		{
			ai_variants[i][0] = 0;
			ai_variants[i][1] = 0;
			continue;
		}
		i++;
	}
}
*/
int		check_result(char *board)
{
	int i;
	int tmp;

	i = 0;
	tmp = board[0] + board[4] + board[8];
	if (tmp == 237 || tmp == 264)
		return tmp / 3;
	tmp = board[2] + board[4] + board[6];
	if (tmp == 237 || tmp == 264)
		return tmp / 3;
	while (i < 3)
	{
		tmp = board[0 + i * 3] + board[1 + i * 3] + board[2 + i * 3];
		if (tmp == 237 || tmp == 264)
			return tmp / 3;
		tmp = board[0 + i] + board[3 + i] + board[6 + i];
		if (tmp == 237 || tmp == 264)
			return tmp / 3;
		i++;
	}
	return (0);
}

//play_the_game!

int		main(void)
{
	char board[9];

	g_player_choice = 0;
	do {
		printf("Select X or O\n");
		scanf(" %c", &g_player_choice); //whitespace specificator cool
	}
	while (g_player_choice != 'X' && g_player_choice != 'O');
	memset(board, ' ', 9);
	while(1)
	{
		player_move(board);
		show_board(board);
		printf("\n%d\n", check_result(board));
	}
	return (0);
}
