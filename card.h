#pragma once

typedef char Face;

typedef enum { clubs, spades, hearts, diamonds } Suit; 

struct Card {
	Suit suit;
	Face face;
};

void Card_print(struct Card const* p_card); 
void Card_swap(struct Card* p_origin, struct Card* p_target); 