#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef TIC_TAC_TOE_H
# define TIC_TAC_TOE_H

extern char    g_XO;
extern char    g_player_choice;
extern char    g_ai_choice;
extern int		g_moves_count;

int		check_result(char *);

int		get_chances(char *board, char order, int move);

void    show_board(char *board);

void    move(char *board, char choice);

void    player_move(char *board);

void    random_ai_move(char *board);

void    player2_move(char *board);

void    ai_move(char *board);

#endif

