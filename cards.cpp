#include "cards.h"
#include <cstdlib>
#include <iostream>


#include <iomanip>
#include <algorithm>



/* *************************************************
   Card class
   ************************************************* */

/* 
   Default constructor for the Card class.
   It could give repeated cards. This is OK.
   Most variations of Blackjack are played with 
   several decks of cards at the same time.
*/
Card::Card(){
   int r = 1 + rand() % 4;
   switch (r) {
      case 1: suit = OROS; break;
      case 2: suit = COPAS; break; 
      case 3: suit = ESPADAS; break;
      case 4: suit = BASTOS; break; 
      default: break;
   }

   r = 1 + rand() % 10;  
   switch (r) {
      case  1: rank = AS; break; 
      case  2: rank = DOS; break; 
      case  3: rank = TRES; break; 
      case  4: rank = CUATRO; break; 
      case  5: rank = CINCO; break; 
      case  6: rank = SEIS; break; 
      case  7: rank = SIETE; break; 
      case  8: rank = SOTA; break; 
      case  9: rank = CABALLO; break; 
      case 10: rank = REY; break; 
      default: break;
   }
}

// Accessor: returns a string with the suit of the card in Spanish 
string Card::get_spanish_suit() const { 
   string suitName;
   switch (suit) {
      case OROS: 
         suitName = "oros"; 
	 break;
      case COPAS: 
         suitName = "copas"; 
	 break; 
      case ESPADAS: 
         suitName = "espadas"; 
	 break;
      case BASTOS: 
         suitName = "bastos"; 
	 break; 
      default: break;
   }
   return suitName;
}

// Accessor: returns a string with the rank of the card in Spanish 
string Card::get_spanish_rank() const { 
   string rankName;
   switch (rank) {
      case AS:
         rankName = "As"; 
	 break; 
      case DOS: 
         rankName = "Dos"; 
	 break; 
      case TRES: 
         rankName = "Tres"; 
	 break; 
      case CUATRO: 
         rankName = "Cuatro"; 
	 break; 
      case CINCO: 
         rankName = "Cinco"; 
	 break; 
      case SEIS: 
         rankName = "Seis"; 
	 break; 
      case SIETE: 
         rankName = "Siete"; 
	 break; 
      case SOTA: 
         rankName = "Sota"; 
	 break; 
      case CABALLO: 
         rankName = "Caballo"; 
	 break; 
      case REY: 
         rankName = "Rey"; 
	 break; 
      default: break;
   }
   return rankName;
}



// Accessor: returns a string with the suit of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_suit() const { 
    string suitName;
    switch (suit) {
        case OROS:
            return "coins";
            break;
        case COPAS:
            return "cups";
            break;
        case ESPADAS:
            return "spades";
            break;
        case BASTOS:
            return "clubs";
            break;
        default: break;
    }

}

// Accessor: returns a string with the rank of the card in English 
// This is just a stub! Modify it to your liking.
string Card::get_english_rank() const { 
    switch (rank) {
        case AS:
            return  "Ace";
            break;
        case DOS:
            return  "Two";
            break;
        case TRES:
            return  "Three";
            break;
        case CUATRO:
            return  "Four";
            break;
        case CINCO:
            return  "Five";
            break;
        case SEIS:
            return "Six";
            break;
        case SIETE:
            return "Seven";
            break;
        case SOTA:
            return "Jack";
            break;
        case CABALLO:
            return "Knight";
            break;
        case REY:
            return "King";
            break;
        default: break;
    }

}



// Assigns a numerical value to card based on rank.
// AS=1, DOS=2, ..., SIETE=7, SOTA=10, CABALLO=11, REY=12
int Card::get_rank() const {
   return static_cast<int>(rank) + 1 ;
}

// Comparison operator for cards
// Returns TRUE if card1 < card2
bool Card::operator < (Card card2) const {
   return rank < card2.rank;
}



/* *************************************************
   Hand class
   ************************************************* */
// Implemente the member functions of the Hand class here.

Hand::Hand(){
}
void Hand::draw_card() {
    Card newCard; //Creates a random card.
    cards.push_back(newCard);
    return;
}
void Hand::reset_hand() {
    cards.resize(0);
    return;
}
void Hand::print() {
    for ( int i=0 ; i<cards.size() ; i++ )
        cout  <<cards[i].get_spanish_rank() << " of " << cards[i].get_spanish_suit() << setw(10) << right << "(" <<cards[i].get_english_rank() << " of " << cards[i].get_english_suit() << ")" <<endl;
    return;
}
void Hand::newprint() {
    double x = cards.size()-1;
    cout << cards[x].get_spanish_rank() << " of " << cards[x].get_spanish_suit() << setw(10) << "(" <<cards[x].get_english_rank() << " of " << cards[x].get_english_suit() << ")" <<endl;
    return;
}
double Hand::sum(){
    double sum = 0;
    for ( int i=0 ; i<cards.size() ; i++ ){
        if (cards[i].get_rank() <= 7)
            sum += cards[i].get_rank();
        else sum += 0.5;
    }
    return sum;
}




/* *************************************************
   Player class
   ************************************************* */
// Implemente the member functions of the Player class here.
Player::Player(int m) {
    money = m;
}

int Player::get_money() {
    return money;
}
int Player::new_money(int y) {
	money += y;
    return money;
}


