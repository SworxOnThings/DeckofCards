#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

#include "deck.h"
#include "card.h"


struct List_Cards* LC_create()
{
	struct List_Cards* result = (struct List_Cards*)malloc(sizeof(struct List_Cards)); 	if (!result) { return NULL; }
	result->next = NULL; 	return result;
}

void Deck_print(struct Deck const* p_deck)
{
	puts("---");
	MCard p_end = Deck_end(p_deck); 	for (MCard pc = Deck_begin(p_deck); pc != p_end; Deck_next_card(&pc)) {
		Card_print(Deck_get_card(pc));
	}
	puts("");
}

MCard Deck_begin(struct Deck const* p)
{
	return (MCard)p->head;
}


void Deck_next_card(MCard* pm)
{
	*pm = (*pm)->next;
}


MCard Deck_end(struct Deck const* p)
{
	return NULL;
}

struct Card* Deck_get_card(MCard m)
{
	return &m->card;
}

MCard Deck_at(struct Deck const* p, unsigned int index, MCard* pp_previous) {
	if (pp_previous) { *pp_previous = (MCard)p->head; }
	MCard p_end = Deck_end(p);
	for (MCard pc = Deck_begin(p); pc != p_end; Deck_next_card(&pc))
	{
		if (index == 0) {
			return pc;
		}
		if (pp_previous) { *pp_previous = (MCard)pc; }

		--index;
	}
	return NULL;
}

void Deck_pushback(struct Deck* p, MCard m)
{
	MCard p_end = Deck_end(p);
	MCard pc = Deck_begin(p);
	for (; pc != p_end; Deck_next_card(&pc))
	{
		if (pc->next == NULL)
		{
			pc->next = m;
			return;
		}
	}

}

void Deck_shuffle(struct Deck* p_deck)
{
	for (int counter = 0; counter < 1000; ++counter) {
		unsigned int cut1 = (rand() % 48) + 1; 		unsigned int cut2 = (rand() % (49 - cut1)) + cut1 + 2;  			   		MCard p1, p2;
		MCard p_origin = (Deck_begin(p_deck)); 		MCard p_cut1 = (Deck_at(p_deck, cut1, &p1));
		MCard p_cut2 = (Deck_at(p_deck, cut2, &p2));
		Deck_pushback(p_deck, p_cut1);
		p1->next = p_cut2;
		p2->next = NULL;
		p2->next = p_origin;
		p1->next = NULL;
		p_deck->head = p_cut2;
	}

}

void Deck_initialize(struct Deck* p_deck) {

	struct List_Cards** p_c = &p_deck->head; 	
	const char card_faces[] = "A23456789TJQK"; 	
	for (Suit i = clubs; i <= diamonds; ++i) {
		for (Face const* j = card_faces; *j != '\0'; ++j) {
			struct List_Cards* new_card = LC_create();
			new_card->card.suit = i;
			new_card->card.face = *j;
			*p_c = new_card;
			p_c = &new_card->next;
		}
	}

}

void Card_destroy(MCard card)
{
	if (!card)
	{ 
		return; 
	} 	

	Card_destroy(card->next); 	
	free(card);
}

void Deck_destroy(struct Deck* p_deck)
{
	Card_destroy(p_deck->head);
}