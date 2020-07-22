/* your name | votre nom */

#include <stdio.h>
#include <stdbool.h>
#include "hull_damage.h"

void initialize(int hull[][EDGE_LENGTH]) {
    for (int row = 0; row < EDGE_LENGTH; row++) {
        for (int col = 0; col < EDGE_LENGTH; col++) {
            hull[row][col] = INITIAL_HULL_STRENGTH;
        }
    }
}

void display_numeric(int hull[][EDGE_LENGTH]) {
    for (int row = 0; row < EDGE_LENGTH; row++) {
        for (int col = 0; col < EDGE_LENGTH; col++) {
            printf("%-3d", hull[row][col]);
        }
        printf("\n");
    }
}

void display_characters(char greys[][EDGE_LENGTH]) {
    for (int row = 0; row < EDGE_LENGTH; row++) {
        for (int col = 0; col < EDGE_LENGTH; col++) {
            printf("%-2c", greys[row][col]);
        }
        printf("\n");
    }
}

void convert(int hull[][EDGE_LENGTH], char greys[][EDGE_LENGTH]) {
    const char greyscale[] = GREYSCALE;
    // yours | a vous
    //declaring what ASCII to what value corresponds for the ASCII art
    for (int i = 0; i < EDGE_LENGTH; i++) {
        for (int j = 0; j < EDGE_LENGTH; j++) {
            if (hull[i][j] == 0) {
                greys[i][j] = ' ';
            } else if (hull[i][j] >= 1 && hull[i][j] <= 10) {
                greys[i][j] = '.';
            } else if (hull[i][j] >= 11 && hull[i][j] <= 20) {
                greys[i][j] = ':';
            } else if (hull[i][j] >= 21 && hull[i][j] <= 30) {
                greys[i][j] = '-';
            } else if (hull[i][j] >= 31 && hull[i][j] <= 40) {
                greys[i][j] = '=';
            } else if (hull[i][j] >= 41 && hull[i][j] <= 50) {
                greys[i][j] = '+';
            } else if (hull[i][j] >= 51 && hull[i][j] <= 60) {
                greys[i][j] = '*';
            } else if (hull[i][j] >= 61 && hull[i][j] <= 70) {
                greys[i][j] = '#';
            } else if (hull[i][j] >= 71 && hull[i][j] <= 80) {
                greys[i][j] = '%';
            } else if (hull[i][j] >= 81 && hull[i][j] <= 90) {
                greys[i][j] = '@';
            } else {
                greys[i][j] = '?'; //in case none of those happens to be
            }
        }
    }

}

void missile_impact(int hull[][EDGE_LENGTH], int missle_row, int missile_col) {
    const int damage_grid[][3] = DAMAGE;
// yours | a vous

//put in the same mini cycle over small hitting space so that if hitting square goes out of bounds, not accessing parts not given to array
    for (int m = missle_row - 1; m <= (missle_row + 1); m++) {
        for (int n = missile_col - 1; n <= (missile_col + 1); n++) {
            if (m >= 0 && m < EDGE_LENGTH && n >= 0 &&
                n < EDGE_LENGTH) {
                //based on location does different subtraction
                if (m == missle_row && n == missile_col) {
                    hull[m][n] -= 50;
                } else if ((m == missle_row && n != missile_col) || (m != missle_row && n == missile_col)) {
                    hull[m][n] -= 22;
                } else { //it just happens on else, no other options exist
                    hull[m][n] -= 10;
                }
            }
            //so that (-) num just changed to 0. after did operation
            if (hull[m][n] < 0) {
                hull[m][n] = 0;
            }
        }
    }
}

bool breached(int hull[][EDGE_LENGTH]) {
    // yours | a vous
    for (int i = 0; i < EDGE_LENGTH; i++) {
        for (int j = 0; j < EDGE_LENGTH; j++) {
            if (hull[i][j] == 0) {
                return true;
            }
        }
    }
    return false;
}



