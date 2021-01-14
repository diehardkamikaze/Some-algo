#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

char	g_XO = 'X' ^ 'O';
char	g_player_choice;
char 	g_ai_choice;

int		g_moves_count;

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
	move(board, g_ai_choice);
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
		if((max == -1) ||\
				((temp > 0) && ((temp / 10000 * (max % 10000 + max / 10000)) > ((temp % 10000 + temp / 10000) * max / 10000))))
		{
			max_count = 1;
			max_index[0] = i;
			max = temp;
		}
		else if((temp / 10000 * (max % 10000 + max / 10000)) == ((temp % 10000 + temp / 10000) * max / 10000))
		{
			max_index[max_count] = i;
			max_count++;
		}
		i++;
	}
	srand(time(0));
	printf("\n%d\n", max_count);
	board[max_index[rand() % max_count]] = g_ai_choice;
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
	if (temp == g_ai_choice)
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
		if (temp < 0 && order != g_ai_choice)
		{
			board[i] = ' ';
			return (-1);
		}
		if(temp < 0)
		{
			board[i] = ' ';
			return (0);
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
	int		winner;
	void	(*player_one)(char *);
	void	(*player_two)(char *);

	player_one = &ai_move; // &random_ai_move; //&AI_move;
	player_two = &ai_move; // &random_ai_move; //&AI_move;
	if (g_player_choice == 'X')
		player_one = &player_move;
	else
		player_two = &player_move;
	while (g_moves_count < 9)
	{
		if(g_moves_count % 2 == 0)
			player_one(board);
		else
			player_two(board);
		show_board(board);
		if (g_moves_count > 3 && (winner = check_result(board)) != 0)
		{
			printf("\n------\nPlayer %c is WINner!\n------\n", winner);
			return;
		}
		g_moves_count++;
	}
	printf("\n| IT IS DRAW! | \n");
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
	g_ai_choice = g_XO ^ g_player_choice;
	memset(board, ' ', 9);
	// printf("%d", get_chances(board, player_choice, move));
	play_the_game(board);
	return (0);
}
