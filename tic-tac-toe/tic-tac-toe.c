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

void	check_result(char *board)
{

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
	return (0);
}
