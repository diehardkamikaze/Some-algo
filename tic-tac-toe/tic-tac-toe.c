#include <stdio.h>

int main(void)
{
	char player_choice = 0;

	do
	{
		printf("Select X or O\n");
		scanf(" %c", &player_choice);
	}
	while (player_choice != 'X' && player_choice != 'O');

	printf("%c", player_choice);
	return (0);
}
