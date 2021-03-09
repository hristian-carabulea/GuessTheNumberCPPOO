#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
#include <stdio.h>
#include <stdlib.h> /*for system()*/
#include "clearScreen.h"
#include "guessingGame.h"

using namespace std;

#ifdef __cplusplus__
  #include <cstdlib>
#else
  #include <stdlib.h>
#endif

int main() { // The guessing game
    guessingGame myGuessingGame;
    myGuessingGame.won = false;  
    char playAgain;

    do { // runs as long as the user chooses y to play again

        clearScreen();

        cout << "*** The Guessing Game ***" << endl  // instructions for user
            << " To win this game, you must guess the randomly chosen number" << endl
            << "    1. Within the number of guesses you've entered." << endl
            << "    2. Between the min and max you've entered, and" << endl
            << endl << "************************" << endl;

        myGuessingGame.numGuessAlreadyMade = 0;

        myGuessingGame.setMinLimit(); // sets minLim
        myGuessingGame.setMaxLimit(); // sets maxLim
        myGuessingGame.setNumOfGuessesAllowed(); // sets numberOfGuessesAllowed
        myGuessingGame.setNumberToBeGuessed(); // 
        myGuessingGame.won = false;

        while ((myGuessingGame.numGuessAlreadyMade < myGuessingGame.numberOfGuessesAllowed) && !myGuessingGame.won) {
            myGuessingGame.setYourGuess();

            if ((myGuessingGame.yourGuessEntry >= myGuessingGame.minLim) && (myGuessingGame.yourGuessEntry <= myGuessingGame.maxLim)) {
                myGuessingGame.numGuessAlreadyMade++;
                if (myGuessingGame.yourGuessEntry == myGuessingGame.numberToBeGuessed) {
                    cout << "Congratulations! You guessed the correct number: "
                        << myGuessingGame.yourGuessEntry << "!" << endl;
                    myGuessingGame.won = true;
                }
                else if (myGuessingGame.yourGuessEntry > myGuessingGame.numberToBeGuessed) {
                    cout << "Your guess is higher." << endl;
                }
                else if (myGuessingGame.yourGuessEntry < myGuessingGame.numberToBeGuessed) {
                    cout << "Your guess is lower." << endl;
                }
                else {
                    cout << "Error1" << endl;
                }
            }
        }

        if (myGuessingGame.won) {
            cout << "You won in " << myGuessingGame.numGuessAlreadyMade << " guesses!" << endl;
        }
        else {
            cout << "Sorry, you lost. You were not able to guess the correct number within "
                 << myGuessingGame.numGuessAlreadyMade << " guesses." << endl;
        }

        cout << "You wanna play again (y or n)? ";
        cin >> myGuessingGame.playAgain;

    } while (myGuessingGame.playAgain == 'y');

    return 0;
}

//******************************************************************
