
#include <string>
#include <ctime>

class guessingGame {

public: //**********************************************************
// Member functions
    //*****************************
    int setMinLimit () {
        std::string inputString;
        while (true) {
            std::cout << "Enter the lower limit number as an integer: ";
            std::cin >> inputString;
            if (isNumber(inputString)) {
                minLim = stoi(inputString);
                break;
            }
        }
        return(0);
    };
    //*****************************
    int setMaxLimit () {
        std::string inputString;
        maxLim = -1;

        while (true) {
            while (true) {
                std::cout << "Enter the upper limit number as an integer greater or equal to the lower limit: ";
                std::cin >> inputString;
                if (isNumber(inputString)) {
                    maxLim = stoi(inputString);
                    break;
                }
            }
            if (maxLim >= minLim) {
                break;
            }
        }
        return(0);
    };
    //*****************************
    void setNumberToBeGuessed() {

        srand((unsigned)time(0));
        secret_number = rand() % (maxLim - minLim + 1) + minLim;

    }
    //*****************************
    int setNumOfGuessesAllowed () {
        std::string inputString;
        while (true) {
            std::cout << "Enter max number of guesses allowed: ";
            std::cin >> inputString;
            if (isNumber(inputString)) {
                numberOfGuessesAllowed = stoi(inputString);
                break;
            }
        }
        return(0);
    };
    //*****************************
    int setYourGuess () {
        std::string inputString;
        while (true) {
            std::cout << "Enter your guess as an integer number: ";
            std::cin >> inputString;
            if (isNumber(inputString)) {
                yourGuessEntry = stoi(inputString);
//                std::cout << "you entered: " << yourGuessEntry << std::endl;
                if ( yourGuessEntry >= minLim && yourGuessEntry <= maxLim) {
                    break;
                }
            }
        }
        return(0);
    };

    int checkYourGuess () {
        if ((yourGuessEntry >= minLim) && (yourGuessEntry <= maxLim)) {
            numGuessAlreadyMade++;
            if (yourGuessEntry == secret_number) {
                std::cout << "Congratulations! You guessed the correct number: "
                    << yourGuessEntry << "!" << std::endl;
                won = true;
            }
            else if (yourGuessEntry > secret_number) {
                std::cout << "Your guess is higher." << std::endl;
            }
            else if (yourGuessEntry < secret_number) {
                std::cout << "Your guess is lower." << std::endl;
            }
            else {
                std::cout << "Error1" << std::endl;
            }
        }
        return(0);
    };
    //*****************************
    bool isNumber(std::string str) {
        for (int i = 0; i < str.length(); i++) {
            if (isdigit(str[i]) == false)
                return false;
        }
        return true;
    };
    //*****************************
    //Data Members
    int numberOfGuessesAllowed;
    int yourGuessEntry;
    int minLim;
    int maxLim;
    int numGuessAlreadyMade = 0;
    bool won;
    int numberToBeGuessed;
    char playAgain;
//******************************************************************
private:

//Member functions

//Data Members
int secret_number;
};
