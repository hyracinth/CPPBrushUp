#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

int main() {

	string userInput;
	int userInputLen, i;

	int currNum = 0, prevNum = 0;

	int finalSum = 0;

	printf("This program will convert roman numerals to integers.\n");
	printf("Please enter your roman numerals: ");
	getline(cin, userInput);

	userInputLen = userInput.length();

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
		}

		


		if(prevNum < currNum) {
			finalSum -= prevNum;
			finalSum += (currNum - prevNum);
		}
		else {
			finalSum += currNum;
		}
printf("%d\t%d\t%d\t%d\n", userInputLen, currNum, prevNum, finalSum);
		prevNum = currNum;

	}

	printf("%d.\n", finalSum);

	return 0;

}
