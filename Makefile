CC=gcc
cardguess: cardguess.c deck.c
	$(CC) -o cardguess cardguess.c deck.c

debug: cardguess.c deck.c
	$(CC) -g -o cardguess cardguess.c deck.c

clean:
	rm cardguess deck
