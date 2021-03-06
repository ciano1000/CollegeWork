#include "stdafx.h"
#include <stdio.h>
#include "string.h"
#include "stdarg.h"
#include "stdlib.h"
#include "time.h"

typedef enum S { CLUBS, DIAMONDS, HEARTS, SPADES } SUIT;
char suits[][10] = { "CLUBS", "DIAMONDS", "HEARTS", "SPADES" };

typedef enum F { TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, ACE } FACE;
char faces[][10] = { "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE", "TEN", "JACK", "QUEEN", "KING", "ACE" };

typedef struct
{
	SUIT suit;
	FACE face;
} card;

typedef struct
{
	card cards[5];
} hand;

// function deals a random hand of cards - BUT .... same card CANNOT be dealt twice!
// so if same card already in the hand, you would need to draw again
// also, the card cannot appear in another hand either
hand dealHand(hand handsDealt[], int numHandsDealt);

// returns pointer to string containing, for example, "ACE of HEARTS"
char * printCard(card aCard);

// compares the FACE values of two cards (TWO is lowest, ACE is highest)
// returns pointer to string containing name of winner: "You" or "Dealer" (or "Draw" if the face values are the same)
char * compareCards(card yourCard, card dealersCard);

// returns true if the hand contains four ACES
bool fourAces(hand aHand);

#define CARDS 52
void main()
{
	int i = 0;
	hand myHand, dealersHand;
	int seed = time(NULL);
	srand(seed);
	hand hands[10];
	
	// deal the first hand
	myHand = dealHand(hands, 0);

	// add this new hand to the set of dealt hands
	hands[0] = myHand;

	// deal another hand; let dealHand know what has already been dealt
	dealersHand = dealHand(hands, 1);

	// here you are just comparing each card one at a time in the two hands
	while (i<5)
	{
		printf("card#%d: %s (you) vs. %s (dealer). Winner: %s \n", i + 1, printCard(myHand.cards[i]), printCard(dealersHand.cards[i]), compareCards(myHand.cards[i], dealersHand.cards[i]));
		i++;
	}

	// now try to deal 4 Aces !
	while (1)
	{
		// deal a new hand; assume new deck every time, so nothing dealt already
		myHand = dealHand(hands, 0);

		// does it contain 4 ACES?
		if (fourAces(myHand)) break;
		i++; // keep track of number of hands dealt
	}
	// print out how many hands it took to find 4 aces
	printf("\n\n4 aces found after %d hands \n\n\n", i);
}

// compares the FACE values of two cards (TWO is lowest, ACE is highest)
// returns pointer to string containing name of winner: "You" or "Dealer" (or "Draw" if the face values are the same)
char * compareCards(card yourCard, card dealersCard)
{
	char * sptr;
	sptr = (char *)malloc(10 * sizeof(char));
	char temp[20];
	temp[0] = '\0';

	if (yourCard.face > dealersCard.face)
	{
		strcat(temp, "You");
	}
	if (yourCard.face < dealersCard.face)
	{
		strcat(temp, "Dealer");
	}
	if (yourCard.face == dealersCard.face)
	{
		strcat(temp, "Draw");
	}
	// your code goes here
	strcpy(sptr, temp);
	return sptr;
}

// returns pointer to string containing, for example, "ACE of HEARTS"
char * printCard(card aCard)
{
	char * sptr;
	// your code goes here
	char temp[20];
	temp[0] = '\0';
	switch (aCard.face)
	{
	case TWO:
		strcat(temp, faces[0]);
		break;
	case THREE:
		strcat(temp, faces[1]);
		break;
	case FOUR:
		strcat(temp, faces[2]);
		break;
	case FIVE:
		strcat(temp, faces[3]);
		break;
	case SIX:
		strcat(temp, faces[4]);
		break;
	case SEVEN:
		strcat(temp, faces[5]);
		break;
	case EIGHT:
		strcat(temp, faces[6]);
		break;
	case NINE:
		strcat(temp, faces[7]);
		break;
	case TEN:
		strcat(temp, faces[8]);
		break;
	case JACK:
		strcat(temp, faces[9]);
		break;
	case QUEEN:
		strcat(temp, faces[10]);
		break;
	case KING:
		strcat(temp, faces[11]);
		break;
	case ACE:
		strcat(temp, faces[12]);
		break;
	default:
		break;
	}

	strcat(temp, " of ");

	switch (aCard.suit)
	{
	case CLUBS:
		strcat(temp, suits[0]);
		break;
	case DIAMONDS:
		strcat(temp, suits[1]);
		break;
	case HEARTS:
		strcat(temp, suits[2]);
		break;
	case SPADES:
		strcat(temp, suits[3]);
		break;
	default:
		break;
	}
	sptr = (char *)malloc(sizeof(char)*strlen(temp));
	strcpy(sptr, temp);
	return sptr;
}

// function deals a random hand of cards - BUT .... same card CANNOT be dealt twice!
// so if same card already in the hand, you would need to draw again
// also, the card cannot appear in another hand either
hand dealHand(hand handsDealt[], int numHands)
{
	hand newHand;
	card newCard;
	SUIT newSuit;
	FACE newFace;

	for (int i = 0; i< 5; i++)
	{
		int card = rand() % CARDS;
		int suit = card % 4;
		int face = card % 13;

		if (suit < 0)
			suit + 4;
		if (face < 0)
			face + 13;

		switch (suit)
		{
		case 0:
			newSuit = CLUBS;
			break;
		case 1:
			newSuit = DIAMONDS;
			break;
		case 2:
			newSuit = HEARTS;
			break;
		case 3:
			newSuit = SPADES;
			break;
		default:
			break;
		}

		switch (face)
		{
		case 0:
			newFace = TWO;
			break;
		case 1:
			newFace = THREE;
			break;
		case 2:
			newFace = FOUR;
			break;
		case 3:
			newFace = FIVE;
			break;
		case 4:
			newFace = SIX;
			break;
		case 5:
			newFace = SEVEN;
			break;
		case 6:
			newFace = EIGHT;
			break;
		case 7:
			newFace = NINE;
			break;
		case 8:
			newFace = TEN;
			break;
		case 9:
			newFace = JACK;
			break;
		case 10:
			newFace = QUEEN;
			break;
		case 11:
			newFace = KING;
			break;
		case 12:
			newFace = ACE;
			break;

		default:
			break;
		}

		if (i > 0)
		{
			if ((newFace == newHand.cards[i-1].face )&&(newSuit == newHand.cards[i-1].suit))
			{
				i = i - 1;
				continue;
			}
			
		}
		if (numHands == 1)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int k = 0; k < 5; k++)
				{
					if ((newFace == handsDealt[j].cards[k].face) && (newSuit == handsDealt[j].cards[k].suit))
					{
						i = i - 1;
						continue;
					}
				}
					
			}
		}
		
		newCard.face = newFace;
		newCard.suit = newSuit;
		newHand.cards[i] = newCard;
	}

	return newHand;
}

// returns true if the hand contains four ACES
bool fourAces(hand aHand)
{
	int i;
	int numAces = 0;
	bool fourAces = false;

	// your code goes here
	for (int i = 0; i < 5; i++)
	{
		if (aHand.cards[i].face == ACE)
		{
			numAces++;
		}
	}
	if (numAces == 4)
	{
		fourAces = true;
	}
	return fourAces;

}