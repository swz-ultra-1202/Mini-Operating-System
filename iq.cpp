#include "iq.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unistd.h>

IQTest::IQTest() : score(0) {
    srand(time(0));
    initializeWords();
}

void IQTest::initializeWords() {
    words = {
        "apple", "banana", "carrot", "dragon", "elephant",
        "flower", "grape", "house", "island", "jungle",
        "kite", "lion", "mountain", "notebook", "ocean",
        "pencil", "queen", "rainbow", "star", "tree"
    };
}

std::string IQTest::reverseWord(const std::string& word) {
    std::string reversed = word;
    std::reverse(reversed.begin(), reversed.end());
    return reversed;
}

void IQTest::askQuestion(int questionNumber) {
    int index = rand() % words.size();
    std::string original = words[index];
    std::string reversed = reverseWord(original);

    std::cout << "Q " << questionNumber << ": What is this word -> " << reversed << std::endl;

    std::string userInput;
    std::cout << "Answer: ";
    std::cin >> userInput;

    if (userInput == original) {
        std::cout << "Correct!\n\n";
        score++;
    } else {
        std::cout << "Incorrect. The correct word was: " << original << "\n\n";
    }
}

void IQTest::displayResult() const {
    std::cout << "========== Quiz Finished ==========\n";
    std::cout << "Your total score: " << score << " out of 5\n";
}

void IQTest::resetGame() {
    score = 0;
    system("clear");
}

void IQTest::runTest() {
    char choice = 'y';
    
    while (choice == 'y' || choice == 'Y') {
        resetGame();
        std::cout << "========== IQ Test ==========\n\n";
        
        for (int i = 1; i <= 5; ++i) {
            askQuestion(i);
        }
        
        displayResult();
        std::cout << "Do you want to try again? (y/n): ";
        std::cin >> choice;
    }
}