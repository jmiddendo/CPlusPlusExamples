#include <iostream>
#include <string>

const int min = 1, max = 101;
void guessNumber(int, int);

int main()
{
	int num = 0;

	do
	{
		std::cout << "Please enter a number: ";
		std::cin >> num;

		system("cls");

	} while (num < min || num > max - 1);

	guessNumber(num, ((min + max) / 2));

	system("pause");

	return 0;

}

void guessNumber(int originalGuess, int guess)
{

	int newGuess = 0;
	static int prevLow = min, prevHigh = max;


	if (guess == originalGuess)
	{
		std::cout << "Your number is: " << guess << std::endl;
		return;
	}
	else
	{
		std::cout << "I guess the number guess: " << guess << std::endl;
		

		if (originalGuess > guess)
		{
			std::cout << "I was too low!" << std::endl;
			
			newGuess = (guess + prevHigh) / 2;
			
			if (guess > prevLow)
				prevLow = guess;

		}

		else if (originalGuess < guess)
		{
			std::cout << "I was too high!" << std::endl;

			newGuess = (guess + prevLow) / 2;

			if (guess < prevHigh)
				prevHigh = guess;

		}

		else
		{
			std::cout << "Beats me!";

		}

		guessNumber(originalGuess, newGuess);
	}

	return;

}
