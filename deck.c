#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

//Hearts Diamonds Clubs Spades
char suits[4][9] = {"H", "D", "C", "S"};
char ranks[13][6] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

void deck_init(struct deck* d){
    int c_nmb=0;
    int suit_seed=0;
    int rank_seed=0;
    for(int j=0; j<DECK_SIZE; j++){
        /*Fisher -Yates shuffle*/
        int rnd_suit = suit_seed + rand() / (RAND_MAX / (SUIT_SIZE-suit_seed) + 1);
        int rnd_rank = rank_seed + rand() / (RAND_MAX / (RANK_SIZE-rank_seed) + 1);
        d->cards[c_nmb].suit = suits[rnd_suit];
        d->cards[c_nmb].rank = ranks[rnd_rank];
        c_nmb++;
        if(suit_seed < SUIT_SIZE-1){
            suit_seed++;
        }else{
            suit_seed=0;
        }
        if(rank_seed < RANK_SIZE-1){
            rank_seed++;
        }else{
            rank_seed=0;
        }
    }
}
/*Fisher -Yates shuffle*/
struct deck* shuffle(struct deck* d){
    for(int i=0; i<DECK_SIZE; i++){
        int j = i + rand() / (RAND_MAX / (DECK_SIZE-i) + 1);
        printf("j:  RAND: %d %d", j, RAND_MAX);
        struct card temp = d->cards[j];
        d->cards[j] = d->cards[i];
        d->cards[i] = temp;
    }
    return d;
}

void magic_shuffle(struct deck* d, int input){
    int c_nmb=input-1;
    int mid=1;
    //Calculate where to put the selected grouping.
    int index = P_DECK_SIZE*input;

    //printf("%s %s \n", d->cards[c_nmb].suit, d->cards[c_nmb].rank);
    struct card temp = d->cards[mid];
    d->cards[mid] = d->cards[c_nmb];
    d->cards[c_nmb] = temp;
    for(int i=0; i<17; i++){
        c_nmb += 3;
        mid += 3;
        //printf("c_nmb: %d mid:  %d \n", c_nmb, mid);
        if(c_nmb < 53){
            temp = d->cards[mid];
            d->cards[mid] = d->cards[c_nmb];
            d->cards[c_nmb] = temp;
            //printf("%s %s \n", d->cards[c_nmb].suit, d->cards[c_nmb].rank);
        }
    }
}

void print_deck(struct deck* d){
    for(int i=1; i<=DECK_SIZE; i++){
        //printf("%d %s %-20s ", (i-1),d->cards[i-1].suit, d->cards[i-1].rank);
        printf("%s%s ", d->cards[i-1].suit, d->cards[i-1].rank);
        if(i%3 == 0)
        printf("\n");
    }
    printf("\n \n");
    printf("Row 1  Row 2  Row 3 \n");
}
