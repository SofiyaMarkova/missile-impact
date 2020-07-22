/* your name | votre nom  */

#include <stdio.h>
#include <stdlib.h>
#include "hull_damage.h"

int main(void) {
    int hull[EDGE_LENGTH][EDGE_LENGTH];
    char greys[EDGE_LENGTH][EDGE_LENGTH];
    const int impacts[N_IMPACTS][2] = IMPACTS; //constant array of int called impacts. that is N_IMPACTS by 2. and it gets filled with the impacts values

    initialize(hull); //initialize hull using initialize function
    printf("initial hull status:\n");
    display_numeric(hull);

    convert(hull, greys); //send to convert
    display_characters(greys); //send to display the converted version

//loop through as much as there are impacts
    for (int i = 0; i < N_IMPACTS; i++) {
        //pass: hull to do work on. missle_row = impacts array for that index row, and 0 because row stored there. missile_col = impacts array for that index col, because at 1 store the col
        missile_impact(hull, impacts[i][0], impacts[i][1]);
    }

    printf("\n"); //gives space to see

    convert(hull, greys); //convert again (after done all impacts)
    display_characters(greys); //display again

//checking if breached
    if (breached(hull)) { //if breached is true
        printf("hull was breached");
    } else {
        printf("hull was not breached");
    }

    return EXIT_SUCCESS;
}
