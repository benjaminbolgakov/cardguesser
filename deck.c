#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

char suits[4][9] = {"Hearts", "Diamonds", "Clubs", "Spades"};
char ranks[13][6] = {"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};

void deck_init(struct deck* d){
    int c_nmb=0;
    for(int i=0; i<SUIT_SIZE; ++i){
        for(int j=0; j<RANK_SIZE; ++j){
            d->cards[c_nmb].suit = suits[i];
            d->cards[c_nmb].rank = ranks[j];
            c_nmb++;
        }
    }
}

/*Fisher -Yates shuffle*/
void shuffle(struct deck* d){
    for(int i=0; i<DECK_SIZE; i++){
        int j = i + rand() / (RAND_MAX / (DECK_SIZE-i) + 1);
        printf("j:  RAND: %d %d", j, RAND_MAX);
        struct card temp = d->cards[j];
        d->cards[j] = d->cards[i];
        d->cards[i] = temp;
    }
}

void magic_shuffle(struct deck* d, int input){
    int c_nmb=0;
    for(int i=0; i<DECK_SIZE; i++){

    }
}

void print_deck(struct deck* d){
    for(int i=0; i<DECK_SIZE; i++){
        printf("%2s %-20s ", d->cards[i].suit, d->cards[i].rank);
        if(i%3 == 0)
        printf("\n");
    }
    printf("Row 1  Row 2  Row 3");
}
