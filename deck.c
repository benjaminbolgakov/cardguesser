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

void shuffle(struct deck* d){
    int deck_halv = DECK_SIZE/2;
    for(int i=0; i<DECK_SIZE; i++){
        int j = i + rand() / (RAND_MAX / (DECK_SIZE-i) + 1);
        struct card temp = d->cards[j];
        d->cards[j] = d->cards[i];
        d->cards[i] = temp;
    }
/*    for(int i=0; i<DECK_SIZE; i++){
        char *t_rank = d->cards[i].rank;
        char *t_suit = d->cards[i].suit;
        printf("%s \n", d->cards[i].suit);
        printf("%s \n", t_suit);
        d->cards[i+1].rank = t_rank;
        d->cards[i+1].suit = t_suit;
        }*/
/*    for(int i=0; i < DECK_SIZE; i++){
        int j = i + rand() / (RAND_MAX / (DECK_SIZE-i) + 1);
        //int suit_rnd = i + rand() / (RAND_MAX / (SUIT_SIZE-i) + 1);
        //int rank_rnd = i + rand() / (RAND_MAX / (RANK_SIZE-i) + 1);
        //printf("%d \n", suit_rnd);
        //printf("%d \n", rank_rnd);
        printf("%d \n", j);
        int t = *d.cards[j];

        char suit_temp = *d.cards[suit_rnd].suit;
        char rank_temp = *d.cards[rank_rnd].rank;
        *d.cards[suit_rnd].suit = *d.cards[i].suit;
        *d.cards[rank_rnd].rank = *d.cards[i].rank;

        *d.cards[i].rank = rank_temp;
        *d.cards[i].suit = suit_temp;*/
}

void print_deck(struct deck* d){
    for(int i=0; i<DECK_SIZE; i++){
        printf("%2s %-20s ", d->cards[i].suit, d->cards[i].rank);
        //printf("%s    " ,d.cards[i].rank);
        if(i%3 == 0)
        printf("\n");
    }
}
