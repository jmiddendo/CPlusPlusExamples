/*File: Lab03.cpp
Programmer: Jeff Middendorf
Date: 12/17/2013
Description: The purpose of this program is to demonstrate random number generation
using a blackjack game.*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <conio.h>
using namespace std;

/*This section is for function prototyping*/
void shuffle_deck(int[]);
void print_header();
void deal_cards(int[], int[], int, int&, int&, int&);
void gotoxy(int, int);
void print_card(int, int, int, int&);
void card_construct(int);
int offerCard(int[], int[], int&, int, int&, int&);
void house_ops(int[], int[], int, int);
void dealer_deal(int player[], int cards[], int i, int& dh, int& cc, int& row);
void end_game(int[]);

int main()
{

	/*  This is the main "driver" function for the program*/

	//Variable declaration
	int y;

	do //Start of blackjack loop
	{

		//Variable declaration
		int cards[52];
		string answer;

		//Variable initialization
		int player[8] = { 0, 0, 0, 0, 0, 0, 0, 0 };
		int dealer_hole, card_count = 0, plug = 0, prev_card = 0, row = 0;
		y = 0;

		//Initialize Deck
		for (int i = 0; i < 52; i++)
			cards[i] = i;

		//Function Call
		print_header();  //Prints the headers
		shuffle_deck(cards);  //Shuffles the deck and assigns them to an array.

		//Deals out the starting cards
		for (int x = 0; x < 16; x++)
			deal_cards(player, cards, x, dealer_hole, card_count, plug);

		//Loop through player's option to hit or stay.
		for (int y = 1; y < 8; y++)
		{
			while (offerCard(player, cards, card_count, y, prev_card, row));
		}

		//Set up dealer
		gotoxy(0, 16);
		cout << "The dealer is taking its turn....";

		//Function calls
		house_ops(player, cards, card_count, dealer_hole);
		end_game(player);

		cout << endl; //End Line

		gotoxy(0, 17); //Move cursor

		//Ask to play again
		cout << "Do you want to play again?";
		cin >> answer;

		//Decipher answer
		if (answer == "Y" || answer == "y")
		{
			y = 1;
			system("cls");
			gotoxy(0, 0);
		}
	} while (y);  //Restart Loop

	cout << endl; //End Line

	system("pause");

	return 0;
}

void gotoxy(int h, int w)
{

	/*The purpose of this function is to set the console cursor position*/

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (INVALID_HANDLE_VALUE != hConsole)
	{
		COORD pos = { h, w };
		SetConsoleCursorPosition(hConsole, pos);
	}

	return;
}

void shuffle_deck(int cards[])
{

	/*The purpose of this function is to set the console cursor position*/

	//Variable declaration
	int dup[52];
	int i = 0, card;

	//Random seed value
	srand(time(NULL));

	//Initializing duplicate deck
	for (i = 0; i < 52; i++)
		dup[i] = 0;

	//Initialize shuffled deck
	for (i = 0; i < 52; i++)
	{
		card = rand() % 52;

		while (dup[card])
			card = rand() % 52;

		dup[card] = 1;
		cards[i] = card;
	}

	return;

}

void print_header()
{
	/*The purpose of this function is to print out the header of the program*/

	cout << setw(7) << "Dlr" << setw(7) << "P1" << setw(7) << "P2" << setw(7) << "P3"
		<< setw(7) << "P4" << setw(7) << "P5" << setw(7) << "P6" << setw(7) << "P7"
		<< endl;

	cout << setw(7) << "---" << setw(7) << "---" << setw(7) << "---" << setw(7) << "---"
		<< setw(7) << "---" << setw(7) << "---" << setw(7) << "---" << setw(7) << "---";

	return;
}

void deal_cards(int player[], int cards[], int i, int& dh, int& cc, int& row)
{
	/*The purpose of this function is to deal out the cards to the players*/

	//Variable initialization
	int j;
	int x = cards[cc] % 13;

	//Determine the player number
	if (cc > 15)
		j = i;
	else
		j = cc % 8;

	//Update the player totals array.
	if (x >= 0 && x < 10)
		player[j] += x + 1;
	else
		player[j] += 10;

	//Hide the first dealer card
	if (cc == 0)
	{
		dh = cards[cc]; //Store the dealer hole card.
		cc++;  //Increase card count
		gotoxy(7 * j, 2);
		cout << setw(6) << '?';
	}
	else
	{
		//Deal the rest of the cards
		if (j == 0)
		{
			print_card(cards[cc], j, cc, row);
			cc++;
		}
		else
		{
			print_card(cards[cc], j, cc, row);
			cc++;
			gotoxy(7 * j, 15);
			cout << setw(6) << player[j];
		}
	}

	return;
}

void print_card(int i, int j, int k, int& row)
{

	//The purpose of this function is to move the cursor to place the cards.
	if (k < 8)
		gotoxy(7 * j, 2);
	else if (k >= 8 && k <= 15)
		gotoxy(7 * j, 3);
	else
	{
		gotoxy(7 * j, row);
		row++;
	}

	//Function Call
	card_construct(i);

	return;

}

void card_construct(int value)
{
	/*The purpose of this function is to display the card on the console*/

	//Variable initialization
	int num = value % 13;
	char suit;
	suit = char(value / 13 + 3);

	//Change the card colors
	if ((value / 13 + 3) == 3 || (value / 13 + 3 == 4))
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);

	cout << setw(6);  //Set width

	//Insert card's face value
	if (num == 0)
		cout << "A";
	else if (num >= 1 && num <= 9)
		cout << num + 1;
	else if (num == 10)
		cout << "J";
	else if (num == 11)
		cout << "Q";
	else if (num == 12)
		cout << "K";
	else
		"Error";

	//Insert card's suit
	cout << suit;

	//Return color to normal
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

	return;
}

int offerCard(int player[], int cards[], int& counter, int player_num, int& prev_player, int& row)
{
	/*The purpose of this function is to ask the player to hit or stay.*/

	//Variable initialization
	int j, i = 1;
	string response = "";

	//Determine player number
	if (counter > 15)
		j = player_num;
	else
		j = counter % 8;

	//Update appropriate row number
	if (player_num != prev_player)
		row = 4;

	//Set the previous player
	prev_player = player_num;

	if (j != 0)
	{
		if (player[j] < 21)
		{
			do
			{
				//Asking to hit or stay
				gotoxy(0, 16);
				cout << "Player " << j << ": Hit or Stay (H or S)?";
				cin >> response;
				gotoxy(31, 16);
				cout << " ";
				if (response == "H" || response == "h" || response == "S" || response == "s")
					i = 0;
			} while (i);

			if (response == "H" || response == "h")
			{

				//Function call
				deal_cards(player, cards, player_num, j, counter, row);
				counter++;  //Card counter increase
				return 1;
			}
		}
		else
			if (player[j] != 21)
			{
			gotoxy(7 * j, 15);
			cout << setw(7) << "Bust!";
			}
	}
	else
	{
		gotoxy(0, 16);
		deal_cards(player, cards, player_num, j, counter, row); //Function Call
		counter++; //Card counter increase
		if (player[0] > 21)
		{
			gotoxy(7 * j, 15);
			cout << setw(7) << "Bust!";
		}
	}

	return 0;
}

void house_ops(int player[], int cards[], int card_index, int dh)
{
	/*The purpose of this function is to handle the operations of the dealer*/

	//Variable initialization
	int value = 0;
	int row = 4;

	gotoxy(0, 2);
	card_construct(dh);  //Function call

	gotoxy(0, 15);
	cout << setw(7) << player[0];

	//Deal out the dealer cards
	while (player[0] < 17)
		dealer_deal(player, cards, card_index, value, card_index, row);

	return;
}

void dealer_deal(int player[], int cards[], int i, int& dh, int& cc, int& row)
{

	//The purpose of this function is to deal out the dealer cards.

	//Variable initialization
	int j = 0;
	int x = cards[cc] % 13;

	//Update the dealer total array
	if (x >= 0 && x < 10)
		player[j] += x + 1;
	else
		player[j] += 10;

	print_card(cards[cc], j, cc, row);  //Function call
	cc++; //Card counter increase
	gotoxy(0, 15);

	//Display the dealer total
	if (player[j] <= 21)
		cout << setw(7) << player[j];
	else
		cout << setw(7) << "Bust!";

	return;
}

void end_game(int player[])
{

	//The purpose of this function is to determine who wins and loses.

	gotoxy(0, 16);
	cout << "";

	if (player[0] <= 21)
	{
		for (int x = 1; x <= 7; x++)
		{
			if (player[x] <= 21)
			{
				if (player[x] > player[0])
				{
					gotoxy(7 * x, 15);
					cout << setw(7) << "Win!";
				}
				else if (player[x] == player[0])
				{
					gotoxy(7 * x, 15);
					cout << setw(7) << "Push!";
				}
				else
				{
					gotoxy(7 * x, 15);
					cout << setw(7) << "Lose!";
				}
			}
			else
			{
				gotoxy(7 * x, 15);
				cout << setw(7) << "Lose!";
			}
		}
	}
	else
	{
		for (int x = 1; x <= 7; x++)
		{
			if (player[x] <= 21)
			{
				gotoxy(7 * x, 15);
				cout << setw(7) << "Win!";
			}
			else
			{
				gotoxy(7 * x, 15);
				cout << setw(7) << "Lose!";
			}
		}
	}



	return;

}