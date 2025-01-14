#include <iostream>
#include <cstdlib>
#include <ctime>

void playGame() {
    // Seed the random number generator
    std::srand(static_cast<unsigned>(std::time(0)));
    int randomNumber = std::rand() % 100 + 1; // Generate a random number between 1 and 100

    int userGuess = 0, attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have chosen a number between 1 and 100. Can you guess it?" << std::endl;

    while (true) {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;

        // Input validation
        if (std::cin.fail() || userGuess < 1 || userGuess > 100) {
            std::cin.clear(); // Clear the input buffer
            std::cin.ignore(1000, '\n'); // Ignore invalid input
            std::cout << "Invalid input. Please enter a number between 1 and 100." << std::endl;
            continue;
        }

        attempts++; // Increment attempts

        if (userGuess == randomNumber) {
            std::cout << "?? Congratulations! You guessed the number " << randomNumber 
                      << " in " << attempts << " attempts." << std::endl;
            break;
        } else if (userGuess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Too low! Try again." << std::endl;
        }
    }
}

int main() {
    char playAgain;

    do {
        playGame();
        std::cout << "Would you like to play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    std::cout << "Thank you for playing! Goodbye!" << std::endl;
    return 0;
}

