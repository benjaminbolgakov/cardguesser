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
/*Row 1 select:
1: 1 4 7 10 13 16 19
2: 0 3 6 9 12 15 18
3: 2 5 8 11 14 17 20

Row 2 select:
1: 0 3 6 9 12 15 18
2: 1 4 7 10 13 16 19
3: 2 5 8 11 14 17 20

Row 3 select:
1: 1 4 7 10 13 16 19
2: 2 5 8 11 14 17 20
3: 0 3 6 9 12 15 18
*/
    struct deck temp;
    int index = input;
    if(input == 1){
        index = 1;
    }
    if(input == 2){
        index = 0;
    }
    if(input == 3){
        index = 1;
    }

    for(int i=0; i<DECK_SIZE; i++){
        temp.cards[i] = d->cards[index];
        index += 3;

        if((i+1)%7 == 0){
            if(input ==1){
                index = 0;
            }else{
                index = 1;
            }
        }
        if((i+1)%14 == 0){
            if(input == 1){
                index = 2;
            }else{
                index = 2;
            }
        }
    }
    //Assign the sorted deck to the playing-deck
    *d = temp;
}

void print_deck(struct deck* d){
    for(int i=1; i<=DECK_SIZE; i++){
        printf("%s%s ", d->cards[i-1].suit, d->cards[i-1].rank);
        if(i%3 == 0){
            printf("\n");
        }
    }
}
