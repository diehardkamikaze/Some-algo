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

void	move(char *board, char choice)
{
	int i;
	printf("You play for %c\n", choice);
	do {
		printf("Your move: (0 - 8): \n");
		scanf("%d", &i);
	}
	while(board[i] != ' ' && printf("Incorrect! Choose only empty cells!\n"));
	board[i] = choice;
}

void player_move(char *board)
{
	move(board, g_player_choice);
}

void player2_move(char *board)
{
	move(board, 'O');
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

void	play_the_game(char *board)
{
	int moves_count;
	int winner;
	void (*player_one)(char *);
	void (*player_two)(char *);

	moves_count = 0;
	player_one = &player2_move;//&AI_move;
	player_two = &player2_move;//&AI_move;
	if (g_player_choice == 'X')
		player_one = &player_move;
	else
		player_two = &player_move;
	while (moves_count < 9)
	{
		player_one(board);
		show_board(board);
		if (moves_count > 3 && (winner = check_result(board)) != 0)
		{
			printf("\n------\nPlayer %c is WINner!\n------\n", winner);
			return;
		}
		moves_count++;
		player_two(board);
		show_board(board);
		if (moves_count > 3 && (winner = check_result(board)) != 0)
		{
			printf("\n------\nPlayer %c is WINner!\n------\n", winner);
			return;
		}
		moves_count++;
	}
}

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
	play_the_game(board);
	return (0);
}
