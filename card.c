#include <stdio.h>
#include "card.h"

static const char* suit_names[] = { "Clubs", "Spades", "Hearts", "Diamonds"
};


void Card_print(struct Card const* p_card)
{
	printf("%c %s ",
		p_card->face,
		suit_names[(int)p_card->suit]);
}


void Card_swap(struct Card* p_origin, struct Card* p_target)
{
	struct Card temp = *p_target;        p_target->suit = p_origin->suit;

	p_target->face = p_origin->face;

	p_origin->suit = temp.suit;
	p_origin->face = temp.face;


}
