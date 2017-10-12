// INFO450PigLatin.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include <string>
#include <iostream> 
#include <sstream>
#include <cctype>


using namespace std;
int translateToPigLatin(string word);
int grabWord();
void repeat();

int main()
{
	//Initialize the function to retrieve input from user
	grabWord();
	//Initialize function that annoys user until they say no
	repeat(); 
	return 0;
}
//Write the function to accept input
int grabWord() 
{
	string word;
	//Ask user to enter a word
	cout << "Enter a word to be converted into Pig Latin. Please, no numbers, and no more than 47 characters!" << endl;
	cin >> word;
	//First of many if statements, check to make sure user can read
	if (isdigit(word[0]) || word.length() > 47)
	{
		//user fails to read
		cout << "...did you even try?" << endl;
		return -1;
	}
	if (word.length() <= 47) 
	{
		//user succeeds, despite all expectations, to follow instructions, word is sent to translate function
		translateToPigLatin(word);
	}
	return 0;
}
//Write the actual meat function that does the translating
int translateToPigLatin(string word) 
{
	//ayyyy
	string addAy = "ay";
	//excluded dictionary, checked over by classmates, as my dyslexic clueless ass missed a word twice
	if (word == "the" || word == "The" || word == "and" || word == "And" || word == "but" || word == "But" || word == "for" || word == "For" || word == "nor" || word == "Nor" || word == "yet" || word == "Yet")
	{
		cout << "You entered an article, so your word remains the same, and it was " << word << endl;

	}
	//I don't know why someone would try a two letter word but just in case
	else if (word.length() <= 2) 
	{
		cout << "Your word translated to Pig Latin is... your word,  " << word << endl;
	}
	//for the user with Intent, an actual translator
	else if (word.length() > 2) 

	{
		//check to see if it starts with a vowel
		char firstletter = word[0];
		if (firstletter == 'a' || firstletter == 'A' || firstletter == 'e' || firstletter == 'E' || firstletter == 'i' || firstletter == 'I' || firstletter == 'o' || firstletter == 'O' || firstletter == 'u' || firstletter == 'U') 
		{
			cout << "Your word translated to Pig Latin is " << word + addAy << endl; 
		}
		//if it starts with a consonant, move a letter AND add ay
		else 
		{
			char lastletter = word[0]; 
			//some fancy functions introduced to me by tech nerd friend (I suppose I'm also a tech nerd though)
			string translated = word.erase(0, 1) + lastletter + addAy;  
			cout << "Your word translated to Pig Latin is " << translated << endl;
		}
	}

	return 0;

}
//a final function to ask if there are other words that desperately need translating
void repeat()
{
	char response;
	cout << "To translate another word, enter Y. If not, enter N." << endl;
	cin >> response;
	if (response == 'y' || response == 'Y')  
	{
		grabWord();
	}
	else if (response == 'n' || response == 'N') 
	{
		return;
	}
	else if (answer != 'y' || answer != 'Y' || answer != 'n' || answer != 'N') 
	{
		cout << " Uhhhhhhhhh what was that again?" << endl;
		repeat();
	}


}
