/* DO NOT MODIFY | NE MODIFIEZ PAS */

#ifndef HULL_DAMAGE_H_
#define HULL_DAMAGE_H_

#include <stdbool.h>

#define GREYSCALE " .:-=+*#%@";
#define EDGE_LENGTH 10
#define INITIAL_HULL_STRENGTH 90
#define DAMAGE { { 10, 22, 10 }, { 22, 50, 22 }, { 10, 22, 10 } }
#define N_IMPACTS 9
#define IMPACTS { { 5, 5 }, { 0, 1 }, { 4, 4 }, { 5, 3 }, { 9, 9 }, { 3, 5 }, { 4, 3 }, { 0, 9 }, { 2, 8 } }

void initialize(int hull[][EDGE_LENGTH]);

void display_numeric(int hull[][EDGE_LENGTH]);

void display_characters(char greys[][EDGE_LENGTH]);

void convert(int hull[][EDGE_LENGTH], char greys[][EDGE_LENGTH]);

void missile_impact(int hull[][EDGE_LENGTH], int missile_row, int missile_col);

bool breached(int hull[][EDGE_LENGTH]);

#endif /* HULL_DAMAGE_H_ */
