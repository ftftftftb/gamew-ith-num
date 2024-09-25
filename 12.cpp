#include <iostream>
#include <ctime>

using namespace std;

class GuessGame {
public:
    // First game: the program guesses your number
    void PlayGame1() {
        char playAgain;
        do {
            int min = 1;
            int max = 100;
            int guessNum;
            char answer;

            cout << "Think of a number between 1 and 100, and I will try to guess it." << endl;

            do {
                guessNum = rand() % (max - min + 1) + min; 
                cout << "My guess is: " << guessNum << ". Is it greater than, less than, or equal to your number? (enter '>', '<', '='): ";
                cin >> answer;

                if (answer == '>') {
                    min = guessNum + 1; 
                } else if (answer == '<') {
                    max = guessNum - 1;  
                } else if (answer == '=') {
                    cout << "Great! I guessed your number!" << endl;
                } else {
                    cout << "Invalid input. Please enter '>', '<', or '='." << endl;
                }
            } while (answer != '=');

            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;

        } while (playAgain == 'y' || playAgain == 'Y');

        cout << "Thanks for playing." << endl;
    }

    // Second game: you guess the number chosen by the program
    void PlayGame2() {
        char playAgain;
        do {
            int randomNum = rand() % 100 + 1; 
            int userGuess = 0;

            cout << "I have chosen a number between 1 and 100. Try to guess it." << endl;

            while (userGuess != randomNum) {
                cout << "Enter your guess: ";
                cin >> userGuess;

                if (userGuess > randomNum) {
                    cout << "The chosen number is smaller." << endl;
                } else if (userGuess < randomNum) {
                    cout << "The chosen number is larger." << endl;
                } else {
                    cout << "Congratulations! You guessed the number!" << endl;
                }
            }

            cout << "Do you want to play again? (y/n): ";
            cin >> playAgain;

        } while (playAgain == 'y' || playAgain == 'Y');

        cout << "Thanks for playing." << endl;
    }
};

int main() {
    srand(time(nullptr)); 

    GuessGame game;

    int choice;

    cout << "Choose a game:" << endl;
    cout << "1. The program guesses your number" << endl;
    cout << "2. You guess the number chosen by the program" << endl;
    cout << "Enter the game number (1 or 2): ";
    cin >> choice;

    if (choice == 1) {
        game.PlayGame1();  
    } else if (choice == 2) {
        game.PlayGame2(); 
    } else {
        cout << "Invalid choice. Please restart the program and choose 1 or 2." << endl;
    }

    return 0;
}