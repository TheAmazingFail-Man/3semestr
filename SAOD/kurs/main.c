#include "functions.h"

int main(void)
{
	srand(time(NULL));
	int number_of_teams, iheight, key = 0, winner;
	float fheight;
	struct tournament* tree = NULL;
	
	while (key == 0) {
		printf("\nEnter number of teams: ");
		scanf("%d", &number_of_teams);
		iheight = log2(number_of_teams);
		fheight = log2(number_of_teams);
		if (iheight / fheight != 1 && number_of_teams != 2) {
			printf("\nIncorrect number of teams. Please try again");
		} else
			key = 1;
	}
	
	tree = create_tree(tree, iheight, number_of_teams);
	tree = create_game(tree);
	winner = final_match(tree);
	print_game(tree, 0);
	printf("\nWinner: %d", winner);
	free_tree(tree);
	
	return 0;
}
