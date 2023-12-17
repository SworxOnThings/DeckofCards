#pragma once 
#include "card.h"

struct List_Cards {
	struct Card card; 
	struct List_Cards* next; 
}; 

struct Deck {
	struct List_Cards *head;
};

typedef struct List_Cards* MCard;

MCard Deck_end(struct Deck const*);

MCard Deck_begin(struct Deck const*);

MCard Deck_at(struct Deck const* p, unsigned int index, MCard* pp_previous);

void Deck_next_card(MCard*);

struct Card* Deck_get_card(MCard);

void Deck_initialize(struct Deck* p_deck); 
void Deck_destroy(struct Deck* p_deck);

void Deck_print(struct Deck const* p_deck);

void Deck_shuffle(struct Deck* p_deck);



