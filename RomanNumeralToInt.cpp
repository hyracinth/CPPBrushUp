/*
Jonah Lou
06-28-2014

Small program to convert roman numerals.


Error checking checks to make sure nothing above three repetitions.

Largest Roman Numeral accepted is C
*/

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

void printError(string myError);

int main() {
	string userInput;
	int userInputLen, i;

	int currNum = 0, prevNum = 0, counter = 0;
	int finalSum = 0;

	bool errorFlag = false;

	printf("This program will convert roman numerals to integers.\n");
	printf("For example: VII\n");
	printf("Input 'quit' to quit program\n");

	//Infinite loop to allow multiple conversions
	while (1) {
		printf("\nPlease enter your roman numerals: ");
		getline(cin, userInput);

		//If desired, quit program
		if(userInput == "quit")
			return 0;

		//Stores length to decrease run time
		userInputLen = userInput.length();

		//Could try enumeration but this seems simpler
		for(i = 0; i < userInputLen; i++) {
			switch(userInput[i]) {
				case 'I': case 'i':
					currNum = 1;
					break;
				case 'V': case 'v':
					currNum = 5;
					break;
				case 'X': case 'x':
					currNum = 10;
					break;
				case 'L': case 'l':
					currNum = 50;
					break;
				case 'C': case 'c':
					currNum = 100;
					break;
				//If there is an invalid letter here, I want to 
				//print an error and get a new number. 
				default:
					errorFlag = true;
					finalSum = 0;
					break;
			}

			//If there is an error, bypass this entire section
			if(!errorFlag) {
				//Keep running counter to count repetition
				if(prevNum == currNum) 
					++counter;
				else
					counter = 0;
				//Once it hits three, print error and break out
				if(counter == 3) {
					printError(userInput);
					break;
				}

				//Logic is as follows:
				//If the previous number is larger than the current, then
				//	the prevoius addition was incorrect and needs to be undone. 
				//	As a result, subtract it from currNum to find the correct
				//	number to be added.
				//If the previous number is smaller, a simple add will work. 
				if(prevNum < currNum) {
					finalSum -= prevNum;
					finalSum += (currNum - prevNum);
				}
				else {
					finalSum += currNum;
				}
				prevNum = currNum;
			}
		}

		//I set finalSum to be zero if there is an error while parsing
		if(finalSum == 0) 
			printError(userInput);
		else 
			printf("%s is %d.\n", userInput.c_str(), finalSum);

		//Reset all variables
		errorFlag = false;
		currNum = 0;
		prevNum = 0;
		finalSum = 0;
	}
	return 0;
}

void printError(string myError) {
	printf("%s is an invalid roman numeral.", myError.c_str());
}
