#include "typing_test.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <unistd.h>

using namespace std;
using namespace std::chrono;

TypingTest::TypingTest() {
    srand(time(0));
    initializeSampleLines();
}

void TypingTest::initializeSampleLines() {
    sampleLines = {
        "India will lose the war ASAP.",
        "Tea is very nice looking today.",
        "Typing is very difficult when blind.",
        "Slow and steady will win the race.",
        "Pakistan is a nuclear power.",
        "The temperatue is too hot.",
        "Pak navy army all are best.",
        "Condition is in control .",
        "What is cease fire.",
        "CRASH OS is building."
    };
}

void TypingTest::displayWelcomeMessage() const {
    system("clear");
    sleep(1);
    cout << "===== TYPING TEST =====" << endl;
    cout << "Type the following line as quickly and accurately as possible.\n" << endl;
}

string TypingTest::selectRandomLine() const {
    int index = rand() % sampleLines.size();
    return sampleLines[index];
}

double TypingTest::calculateAccuracy(const string& target, const string& userInput) const {
    int correctChars = 0;
    int minLength = min(target.length(), userInput.length());
    for (int i = 0; i < minLength; i++) {
        if (target[i] == userInput[i]) {
            correctChars++;
        }
    }
    return (static_cast<double>(correctChars) / target.length()) * 100;
}

double TypingTest::calculateWPM(int correctChars, double seconds) const {
    double words = correctChars / 5.0;
    double minutes = seconds / 60.0;
    return words / minutes;
}

void TypingTest::displayResults(const string& target, const string& userInput, 
                              double seconds, double wpm, double accuracy) const {
    cout << "\n===== RESULTS =====" << endl;
    cout << "Time taken: " << seconds << " seconds" << endl;
    cout << "Your typing speed: " << wpm << " WPM" << endl;
    cout << "Accuracy: " << accuracy << "%" << endl;

    if (userInput == target) {
        cout << "\nPerfect! You typed the line correctly!" << endl;
    } else {
        cout << "\nOriginal: " << target << endl;
        cout << "Your text: " << userInput << endl;
    }
}

void TypingTest::runTest() {
    char choice = 'y';
    
    while (choice == 'y' || choice == 'Y') {
        displayWelcomeMessage();
        
        string target = selectRandomLine();
        cout << target << "\n" << endl;

        cout << "Press Enter when ready to start typing...";
        cin.ignore();
        
        auto start = high_resolution_clock::now();
        
        string userInput;
        cout << "Start typing now:\n";
        getline(cin, userInput);

        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start);
        double seconds = duration.count() / 1000.0;

        // Calculate metrics
        int correctChars = 0;
        int minLength = min(target.length(), userInput.length());
        for (int i = 0; i < minLength; i++) {
            if (target[i] == userInput[i]) {
                correctChars++;
            }
        }
        
        double accuracy = calculateAccuracy(target, userInput);
        double wpm = calculateWPM(correctChars, seconds);

        displayResults(target, userInput, seconds, wpm, accuracy);
        
        cout << "\nDo you want to perform another Test? (y/n): ";
        cin >> choice;
    }
}