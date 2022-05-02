#include <stdio.h>
#include <stdlib.h>
#include "deck.h"

//Hearts Diamonds Clubs Spades
char suits[4][9] = {"H", "D", "C", "S"};
char ranks[13][6] = {"A","2","3","4","5","6","7","8","9","10","J","Q","K"};

void deck_init(struct deck* d){
    int s_nmb=0;
    int r_nmb=0;
    for(int i=0; i<DECK_SIZE; i++){
        d->cards[i].suit = suits[s_nmb];
        d->cards[i].rank = ranks[r_nmb];
        r_nmb++;
        if(i == 12){
            s_nmb++;
            r_nmb=0;
        }
    }
    /*int c_nmb=0;
    int suit_seed=0;
    int rank_seed=0;
    for(int j=0; j<DECK_SIZE; j++){
        Fisher -Yates shuffle
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
    }*/
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
    /*int index=(input*7)-7;
    struct card temp;
    for(int i=7; i<14; i++){
        temp = d->cards[i];
        d->cards[i]=d->cards[index];
        d->cards[index] = temp;
        index++;
        }

HA H2 H3
H4 H5 H6
H7 H8 H9
H10 HJ HQ
HK DA D2
D3 D4 D5
D6 D7 D8
->
H10 H9 H8
HK HQ HJ
H2 HA DA
H5 H4 H3
D2 H7 H6
D5 D4 D3
D8 D7 D6




*/

    int row_nmb= input;
    int t=4;
    struct card temp;
    for(int i=0; i<DECK_SIZE; i++){
        temp = d->cards[i];
        d->cards[i] = d->cards[t];
        d->cards[t] = temp;
        t+=4;
        if(i%7==0){
            t=row_nmb;
            row_nmb++;
        }
    }
}

void print_deck(struct deck* d){
    for(int i=1; i<=DECK_SIZE; i++){
        printf("%s%s ", d->cards[i-1].suit, d->cards[i-1].rank);
        if(i%3 == 0){
            printf("\n");
        }
    }
/*    int row_nmb=1;
    int t=0;
    for(int i=1; i<=DECK_SIZE; i++){
        //printf("%d %s %-20s ", (i-1),d->cards[i-1].suit, d->cards[i-1].rank);
        printf("%s%s ", d->cards[t].suit, d->cards[t].rank);
        t+=3;
        if(i%7 == 0){
            printf("   Row %d", row_nmb);
            printf("\n");
            t=row_nmb;
            row_nmb++;
        }
        }*/
}
