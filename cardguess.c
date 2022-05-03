

#include <stdio.h>
#include <string.h>
#include "deck.h"

//gcc -Wall -Wextra -Wpedantic cardguess.c deck.c


void prompt(struct deck* d);
void game(struct deck* d);




int main()
{
    struct deck d;
    deck_init(&d);
    //shuffle(&d);
    prompt(&d);


    return 0;
}


void prompt(struct deck* d){
    print_deck(d);
    printf("Pick a card out of the three groupings and remember it! \n");
    game(d);
}

void game(struct deck* d){
    //char input[2];
    int input;
    for(int i=0; i<3; i++){
        printf("In which row is your card? (type the number 1,2 or 3 and hit Enter) \n");
        scanf("%d", &input);
        magic_shuffle(d,input);
        print_deck(d);
    }
    //Print the 11th card, which is the magic card
    printf("\n");
    printf("The card you thought of was: %s%s \n", d->cards[10].suit, d->cards[10].rank);
}
