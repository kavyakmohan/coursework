/*
 * Name: Kavya Mohan, 2001362917, Assignment 1
 * Description: Accordion Solitaire
 * Input: decks of card from input file
 * Output: play accordion solitaire and display results
 */

#include <iostream>
#include <fstream>
#include <string>
#include "myStack.h"
using namespace std;

int main()
{
	string inputFile;
	ifstream infile;
	string cardInput;
	bool moveMade = false;
	string currentCard;
	string comparisonCard;
	string temp;
	int stacksRemaining = 0;

	//prompt for valid input file until successfully opened
	while (!infile.is_open())
	{
		cout << "Enter filename: ";
		cin >> inputFile;
		infile.open(inputFile.c_str());
	}

	cout << endl;

	//allocate array of 52 myStack objects
	myStack <string> * cards;
	cards = new myStack <string> [52];

	while (infile)
	{
		//reading in cards from input file
		//pushing input onto array of myStack objects
		for (int i = 0; i < 52; i++)
		{
			infile >> cardInput;

			if (cardInput != "#")
				cards[i].push(cardInput);
		}

		//stop reading file once # is read
		if (cardInput == "#")
			break;

		int i = 1;

		//ACCORDION SOLITAIRE ALGORITHM BEGINS HERE
		while (i < 52)
		{
			//checking for gaps in the array and shifting over stacks if necessary
			for (int j = 0; j < 51; j++)
			{
				if (cards[j].isEmpty())
				{
					cards[j] = cards[j+1];
					cards[j+1].clearStack();
				}
			}

			//ensure that leftmost match is always made by resetting array iterator
			if (moveMade == true)
			{
				i = 1;
				moveMade = false;
			}

			//retrieve info of current card to evaluate
			//if current card is empty ... stop reading ... don't proceed with game
			if (cards[i].isEmpty() == false)
				currentCard = cards[i].peek();
			else
				break;

			//if looking at 2nd or 3rd stacks in the array
			//can only compare with the top of the stack immediately to the left
			if (i == 1 || i == 2)
			{
				//retrieve info of the card to the left
				comparisonCard = cards[i-1].peek();

				//pop stack top and push onto appropriate stack if match found
				if (currentCard[0] == comparisonCard[0] || currentCard[1] == comparisonCard[1])
				{
					temp = cards[i].pop();
					cards[i-1].push(temp);
					moveMade = true;
				}
				else
					moveMade = false;
			}
			//general comparison algorithm for the rest of the stacks in the array
			else
			{
				//retrieve info of the 3rd card to the left
				comparisonCard = cards[i-3].peek();

				//pop stack top and push onto appropriate stack if match found
				if (currentCard[0] == comparisonCard[0] || currentCard[1] == comparisonCard[1])
				{
					temp = cards[i].pop();
					cards[i-3].push(temp);
					moveMade = true;
				}
				else
				{
					//conduct comparisons with card immediately to the left
					comparisonCard = cards[i-1].peek();

					if (currentCard[0] == comparisonCard[0] || currentCard[1] == comparisonCard[1])
					{
						temp = cards[i].pop();
						cards[i-1].push(temp);
						moveMade = true;
					}
					else
						moveMade = false;
				}
			}
			//update iterator
			i++;
		}

		//OUTPUT RESULTS
		//count number of stacks left
		for (int j = 0; j < 52; j++)
		{
			if(cards[j].isEmpty() == false)
				stacksRemaining++;
		}

		if (stacksRemaining == 1)
			cout << "Only 1 pile with 52 cards with " << cards[0].peek() << " card on top" << endl;
		else
		{
			cout << stacksRemaining << " piles remaining => ";

			for (int i = 0; i < stacksRemaining; i++)
				cout << cards[i].peek() << ":" << cards[i].stackSize() << " ";

			cout << endl;
		}

		//deallocate stacks before reading in the next deck
		for (int j = 0; j < 52; j++)
			cards[j].clearStack();

		//reset stacksRemaining
		stacksRemaining = 0;
	}
	cout << endl;
	for (int i = 0; i < 52; i++)
		cards[i].clearStack();
	delete [] cards;
	return 0;
}
