#ifndef FUNCTIONS_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

struct tournament {
	struct tournament* next_match;
	struct tournament* left_match;
	struct tournament* right_match;
	int left_team;
	int right_team;
};

struct tournament* create_tree(struct tournament* tree, int iheight, int number_of_teams);
struct tournament* create_match(struct tournament* tree);
struct tournament* create_game(struct tournament* tree);
int final_match(struct tournament* tree);
void print_game(struct tournament* tree, int step);
void free_tree(struct tournament* tree);

#endif
