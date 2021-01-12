#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char	g_XO = 'X' ^ 'O';
char	g_player_choice;
char 	ai_choice = 'X' ^ 'O';
int		moves_count = 0;

int check_result(char *);
int get_chances(char *board, char order, int move);

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

void	player_move(char *board)
{
	move(board, g_player_choice);
}

void	player2_move(char *board)
{
	move(board, ai_choice);
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
	board[i] = ai_choice;
}

void	ai_move(char *board)
{
	int i;
	int max = -1000;
	int max_index = 0;
	int temp;

	i = 0;
	printf("AI move is: \n");
	while (i < 8)
	{
		if(board[i] != ' ')
		{
			i++;
			continue;
		}
		board[i] = ai_choice;
		temp = get_chances(board, g_player_choice, moves_count);
		board[i] = ' ';
		printf("%d\n",temp);
		if(temp == 10000)
		{
			max_index = i;
			break;
		}
		if (temp > max)
		{
			max = temp;
			max_index = i;
		}
		i++;
	}
	board[max_index] = ai_choice;
}

int get_chances(char *board, char order, int move)
{
	int i;
	int result;
	int temp;

	i = 0;
	result = 0;
	temp = check_result(board);
//	printf("temp %d\n", temp);
//	show_board(board);
	//char c;
	//scanf(" %c", &c);
	if (temp == ai_choice)
		return (10000);
	if (temp == g_player_choice)
		return (-1);
	if (move == 9)
		return (0);

	while (i < 9)
	{
		if (board[i] != ' ')
		{
			i++;
			continue;
		}
		board[i] = order;
		temp = get_chances(board, g_XO ^ order, move + 1);
		if (temp == 0)
			result += 1;
		if (temp >= 10000)
			result += temp;
		if (temp < 0 && order != ai_choice)
		{
			board[i] = ' ';
			return (-1);
		}
		board[i] = ' ';
		i++;
	}

	return (result);
}

int check_result(char *board)
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
	int winner;
	void (*player_one)(char *);
	void (*player_two)(char *);

	moves_count = 0;
	player_one = &ai_move; // &random_ai_move; //&AI_move;
	player_two = &ai_move; // &random_ai_move; //&AI_move;
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
	ai_choice ^= g_player_choice;
	memset(board, ' ', 9);

	// printf("%d", get_chances(board, player_choice, move));
	play_the_game(board);
	return (0);
}
