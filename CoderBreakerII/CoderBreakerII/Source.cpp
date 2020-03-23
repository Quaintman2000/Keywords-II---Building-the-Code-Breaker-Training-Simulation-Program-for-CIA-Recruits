#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
#include <ctime>
#include <cctype>

using namespace std;

void Introduction()
{

	// Display Title of the program to the user
	cout << "\t\t *** Code Breakers II ***\n" << endl;
	// Ask the recruit to log in using their name
	cout << "Please enter your name: ";
	// Hold the recruit's name in a var, and address them by it throughout the simulation.
	string recruitName;
	getline(cin, recruitName);
	// Display an overview of what Keywords II is to the recruit 
	cout << "Welcome Private " << recruitName << ", to the next course of your training." << endl;
	cout << "This is Code Breakers II, while the end goal is similar to Code Breakers I but, it would evidently be more challenging." << endl;
	cout << "The objective is discover what the hidden keyword is but, unlike the previous program, you will not be shown the scrambled keyword and you will have a limited amount of guesses" << endl;
	cout << "All that will be displayed for you is the letters guessed and number of 'guesses' you have left.\n\n";
	cout << "Good luck, Private " << recruitName << ".\n\n";
	// Display directions to the recruit on how to use Keywords
	cout << "To guess a letter, you simply guess have to type the letter and hit 'Enter'" << endl;
	cout << "You may guess only ONE letter at a time" << endl;
	cout << "If you wish to exit program, type 'Quit'\n\n";
}

void showStack(stack <char> s)
{
	
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
	
}

bool runSimulation(string word1, string word2, string word3)
{

	
	int numIncorrectGuesses = 0;
	int maxIncorrectGuesses = 10;
	
	


	string words[3] = { word1,word1,word3 };
	for (int i = 0; i < 3; i++) {
		string wordSoFar;
		stack <char> lettersGuessed;
		//fills the wordSoFar string with underscores for the time being
		for (int b = 0; b < words[i].length(); b++)
		{
			wordSoFar += "_";
		}
		// While recruit hasn’t made too many incorrect guesses and hasn’t guessed the secret word
		while (numIncorrectGuesses < maxIncorrectGuesses && wordSoFar != words[i])
		{
		
			//     Tell recruit how many incorrect guesses he or she has left
			cout << "You have " << maxIncorrectGuesses - numIncorrectGuesses << " incorrect guesses left." << endl;
			//     Show recruit the letters he or she has guessed
			cout << "So far, the letters you have guessed are:";
			showStack(lettersGuessed);
			cout << endl;
			//     Show player how much of the secret word he or she has guessed
			cout << "Your word so far: " << wordSoFar << endl;
			//     Get recruit's next guess
			char guess;
			cin >> guess;
			//covert guess into uppercase
			guess = toupper(guess);
			//     Add the new guess to the group of used letters
			lettersGuessed.push(guess);
			//     If the guess is in the secret word
			bool guessIsRight = false;
			for (int a = 0; a < words[i].length(); a++)
			{
				//checks each letter in the word to see if the guess char is in there
				if (guess == words[i][a])
				{
					guessIsRight = true;
					break;
				}
			}
			//          Tell the recruit the guess is correct
			if (guessIsRight)
			{
				cout << "That guess is correct! Well Done!" << endl;

				//          Update the word guessed so far with the new letter
				for (int a = 0; a < words[i].length(); a++)
				{
					if (guess == words[i][a])
					{
						wordSoFar[a] = guess;
					}					
				}
			}
			//     Otherwise
			else
			{
				//          Tell the recruit the guess is incorrect
				cout << "Sorry, that guess is within the code word." << endl;
				//          Increment the number of incorrect guesses the recruit has made
				numIncorrectGuesses++;
			}
			//if he completes the word
			if (wordSoFar == words[i]) {
				cout << "\n Congrats, the word was " << wordSoFar << endl;
			}
		}
	}
	// If the recruit has made too many incorrect guesses
	if (numIncorrectGuesses == maxIncorrectGuesses)
	{
		//     Tell the recruit that he or she has failed the Keywords II course.
		cout << "I'm sorry but, you have made to many incorrect guesses inorder to pass this course.\n\n";
		return true;
	}
	// Otherwise
	else {
		//     Congratulate the recruit on guessing the secret words
		cout << "Congratulations Private, you have successfully passed the Code Breakers II course.\n\n";
		return true;
	}
}


int main()
{
	//Display the introductions
	Introduction();

	// Create a collection of 10 words you had written down manually
	string codeWords[10] = { "SILENCER","BOND","MISSION","SECRET","TARGET","SPY","ASSASSINATE","CIA","IMPOSSIBLE","SNIPER" };
	// Create an int var to count the number of simulations being run starting at 1


	bool playAgain = true;
	//while playAgain = true, it keep running the simulation
	while (playAgain)
	{
		int simulationNumber = 1;
		// Display the simulation # is starting to the recruit. 
		cout << "This is simulation number: " << simulationNumber << endl;
		// Pick new 3 random words from your collection as the secret code word the recruit has to guess. 
		string theWord[3];
		for (int i = 0; i < 3; i++)
		{
			//generates random number to pick the word
			srand(static_cast<unsigned int>(time(0)));
			int choice = (rand() % 10);

			//checks if it hasnt already been chosen
			bool cleared = false;
			
			while (!cleared)
			{
				//generates random number to pick the word
				
				if (codeWords[choice] == theWord[0] || codeWords[choice] == theWord[1] || codeWords[choice] == theWord[2])
				{
					srand(static_cast<unsigned int>(time(0)));
					 choice = (rand() % 10);
				}
				else
				{
					cleared = true;
				}
			}
			//enters the word as one of the three
			theWord[i] = codeWords[choice];
		}
		runSimulation(theWord[0], theWord[1], theWord[2]);
		// Ask the recruit if they would like to run the simulation again
		cout << "Would you like to run the simulation again? YES or NO?" << endl;
		// If the recruit wants to run the simulation again
		string answer;
		cin >> answer;

		if (answer == "YES" || answer == "yes" || answer == "Yes") {
			//     Increment the number of simulations ran counter
			simulationNumber++;
			//     Move program execution back up to // Display the simulation # is starting to the recruit. 
			playAgain = true;
		}
		// Otherwise 
		else
		{
			//     Display End of Simulations to the recruit
			cout << "Thank you, for completing the Code Breakers II training course, please restart the program for the next person please.\n\n";
			//     Pause the Simulation with press any key to continue
			cin.get();
		}
	}


}
