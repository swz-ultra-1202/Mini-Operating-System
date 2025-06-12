#ifndef TYPING_TEST_H
#define TYPING_TEST_H

#include <string>
#include <vector>
#include <chrono>

class TypingTest {
private:
    std::vector<std::string> sampleLines;
    
    void initializeSampleLines();
    void displayWelcomeMessage() const;
    std::string selectRandomLine() const;
    double calculateAccuracy(const std::string& target, const std::string& userInput) const;
    double calculateWPM(int correctChars, double seconds) const;
    void displayResults(const std::string& target, const std::string& userInput, 
                       double seconds, double wpm, double accuracy) const;

public:
    TypingTest();
    void runTest();
};

#endif // TYPING_TEST_H