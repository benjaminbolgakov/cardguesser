#ifndef DECK_H_
#define DECK_H_

#define DECK_SIZE 52
#define P_DECK_SIZE 18
#define SUIT_SIZE 4
#define RANK_SIZE 13

//char *suits[4];
//char *ranks[13];

struct card{
    char *rank;
    char *suit;
};

struct deck{
    struct card cards[DECK_SIZE];
};

struct p_deck{
    struct card cards[P_DECK_SIZE];
};

void deck_init(struct deck* d);
void print_deck(struct deck* d);
void shuffle(struct deck* d);
void magic_shuffle(struct deck* d, int input);

#endif
