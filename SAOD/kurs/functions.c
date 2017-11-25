#include "functions.h"

struct tournament* create_tree(struct tournament* tree, int iheight, int number_of_teams)
{
	int i = 1, key = 0, number = 1;

	tree = create_match(tree);
	if (!tree)
	
		return NULL;
	while (key == 0) {
		while (i < iheight) {
			tree->left_match = create_match(tree);
			if (!tree->left_match)
				
				return NULL;
			tree = tree->left_match;
			i++;
		}
		tree->left_team = number++;
		tree->right_team = number++;
		if (number == number_of_teams + 1)
			key = 1;
		if (key == 0) {
			while (tree->next_match->right_match) {
				tree = tree->next_match;
				i--;
			}
			if (!tree->next_match->right_match) {
				tree = tree->next_match;
				tree->right_match = create_match(tree);
				if (!tree->right_match)
				
					return NULL;
				tree = tree->right_match;
			}
		}
	}
	while (tree->next_match)
		tree = tree->next_match;
	
	return tree;
}

struct tournament* create_match(struct tournament* tree)
{
	struct tournament *match;
	match = malloc(sizeof(*match));
	match->left_match = NULL;
	match->right_match = NULL;
	match->left_team = 0;
	match->right_team = 0;
	if (!match)
	
		return NULL;
	if (tree) {
		match->next_match = tree;
	} else
		match->next_match = NULL;
	
	return match;
}

struct tournament* create_game(struct tournament* tree)
{
	int key = 0, number;
	
	while (key == 0) {
		while (!tree->left_team && !tree->right_team) {
			tree = tree->left_match;
		}
		if (!tree->next_match)
			key = 1;
			
		if (key == 0) {
			number = rand() % 100;
			if (!tree->next_match->left_team) {
				if (number < 50) {
					tree->next_match->left_team = tree->left_team;
				} else {
					tree->next_match->left_team = tree->right_team;
				}
			} else if (!tree->next_match->right_team) {
				if (number < 50) {
					tree->next_match->right_team = tree->left_team;
				} else {
					tree->next_match->right_team = tree->right_team;
				}
			}
			if (tree->next_match->left_team && tree->next_match->right_team) {
				tree = tree->next_match;
			} else if (tree->next_match->left_team && !tree->next_match->right_team) {
				tree = tree->next_match->right_match;
			}
		}
	}
	
	return tree;
}

int final_match(struct tournament* tree)
{
	int number;
	number = rand() & 100;
	if (number < 50) {
		
		return tree->left_team;
	} else {
		
		return tree->right_team;
	}
}

void print_game(struct tournament* tree, int step)
{
	int i;
	if (tree != NULL) {
		print_game(tree->right_match, step + 1);
		for (i = 0; i < step; i++) {
			printf("	");
		}
		printf("%d:%d", tree->left_team, tree->right_team);
		print_game(tree->left_match, step + 1);
	} else {
		printf("\n");
	}
}

void free_tree(struct tournament* tree)
{
	if (tree != NULL) {
		free_tree(tree->right_match);
		free_tree(tree->left_match);
		free(tree->left_match);
		free(tree->right_match);
		free(tree);
	}
}
