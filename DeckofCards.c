
#include <stdlib.h> 
#include <stdio.h>
#include <time.h>

#include "card.h"
#include "deck.h"


int main()
{
   srand((unsigned int)time(NULL));    
   struct Deck deck;     
   Deck_initialize(&deck);    
   Deck_print(&deck);
   puts("\n  and now we will shuffle... \n");
   Deck_shuffle(&deck);
   Deck_print(&deck);
   Deck_destroy(&deck);
}

