# Guess the number Game in Python 3
def checkIfInt(message):
    while True:
        valueIn=input(message)
        if valueIn.isnumeric():
            return int(valueIn)

from random import seed
from random import randint

seedNum = 1 # seed random number generator
numRuns = 0
randomValue = 0

while True: 
    lower = checkIfInt("Enter lower limit: ")
    upper = checkIfInt("Enter upper limit: ")
    numTries = checkIfInt("Enter number of tries you are willing to make: ")

    seedNum = seedNum + 1
    seed(int(seedNum))
    randomValue = randint(int(lower), int(upper)) #print(randomValue)
    numRuns = 0
    
    while True:
        while True:
            numRuns = numRuns + 1
            guess = checkIfInt(f"Enter your guess value between {lower} and {upper}: ")
            if (guess >= lower and guess <= upper):
                break

        if guess > randomValue:
            print("Your value is higher")
        elif guess < randomValue:
            print("Your guess is lower")
        elif guess == randomValue:
            print(f'Congratulations, you won in {numRuns} tries!')
            break
    
    continueValue = input("If you want to play again enter y. Else enter any other key: ")
    if continueValue != "y":
        print ("Thank you for playing. Bye Bye!")
        break

