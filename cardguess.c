
#include <stdio.h>
#include <string.h>
#include "deck.h"

void prompt(struct deck* d);





int main()
{
    struct deck d;
    deck_init(&d);
    prompt(&d);
    shuffle(&d);
    printf("//////////////");
    print_deck(&d);

    return 0;
}


void prompt(struct deck* d){
    printf("Pick a card out of the three groupings and remember it! \n");
    print_deck(d);
    printf("Ready? \n");
}
