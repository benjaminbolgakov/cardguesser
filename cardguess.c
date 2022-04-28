

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
    //Print the 13th (11th?) card, which is the magic card
    //printf("%s %s", d->cards[13].suit, d->cards[13].rank);
}
