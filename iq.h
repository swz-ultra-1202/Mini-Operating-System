#ifndef IQ_H
#define IQ_H

#include <string>
#include <vector>

class IQTest {
private:
    std::vector<std::string> words;
    int score;
    
    void initializeWords();
    std::string reverseWord(const std::string& word);
    void askQuestion(int questionNumber);
    void displayResult() const;
    void resetGame();

public:
    IQTest();
    void runTest();
};

#endif // IQ_TEST_H