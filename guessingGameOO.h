
#include <string>
#include <ctime>

/* 
2021.04.07: removed all the warnings by initializing all the variables in the data members section.
*/
class guessingGame {
public:
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
    //*****************************
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

    //Data Members
    int numberOfGuessesAllowed = 0;
    int yourGuessEntry = 0;
    int minLim = 0;
    int maxLim = 0;
    int numGuessAlreadyMade = 0;
    bool won = false;
    int numberToBeGuessed = 0;
    char playAgain = 'n';
//******************************************************************
private:
//Member functions

//Data Members
int secret_number = 0;
};
