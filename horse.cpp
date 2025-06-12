#include "horse.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

HorseRace::HorseRace() 
{
    srand(static_cast<unsigned>(time(nullptr)));
}

void HorseRace::moveHorse(Horse* horse) {
    int movement = horse->speed - (horse->fatigue / 10);
    horse->position += (movement > 0) ? movement : 0;
}

void HorseRace::applyFatigue(Horse* horse) {
    horse->fatigue += horse->speed / 4 + horse->endurance / 6;
}

void HorseRace::applyObstacles(Horse* horse) {
    if (rand() % 10 == 0) {
        horse->speed -= rand() % 2 + 1;
        horse->fatigue += rand() % 2 + 1;
        horse->speed = (horse->speed > 0) ? horse->speed : 0;
        horse->fatigue = (horse->fatigue > 0) ? horse->fatigue : 0;
    }
}

void HorseRace::printRaceStatus(const Horse* horses) const {
    system("clear");
    
    for (int i = 0; i < NUM_HORSES; ++i) {
        std::cout << "Horse " << i+1 << ": ";
        for (int j = 0; j < horses[i].position; ++j) {
            std::cout << '-';
        }
        std::cout << '*' << std::endl;
    }
    
    std::cout << "-------------------------------------" << std::endl;
    std::cout << "Horse | Speed | Endurance | Position | Fatigue" << std::endl;
    std::cout << "-------------------------------------" << std::endl;
    for (int i = 0; i < NUM_HORSES; ++i) {
        std::cout << "  " << i+1 << "   | " << horses[i].speed << "    | " << horses[i].endurance << "       | "
            << horses[i].position << "      | " << horses[i].fatigue << std::endl;
    }
    std::cout << "-------------------------------------" << std::endl;
}

int HorseRace::checkWinningCondition(const Horse* horses) const {
    for (int i = 0; i < NUM_HORSES; ++i) {
        if (horses[i].position >= FINISH_LINE) {
            return i + 1;
        }
    }
    return 0;
}

void HorseRace::initializeHorses(Horse horses[NUM_HORSES]) {
    for (int i = 0; i < NUM_HORSES; ++i) {
        horses[i].speed = rand() % 10 + 10;
        horses[i].endurance = rand() % 10 + 10;
        horses[i].position = 0;
        horses[i].fatigue = 0;
    }
}

void HorseRace::getPlayerBet(int& selectedHorse, int& betAmount) const {
    std::cout << "Welcome to the Horse Race Game!" << std::endl;
    std::cout << "There are " << NUM_HORSES << " horses in the race." << std::endl;
    std::cout << "Enter the horse number you want to bet on (1-" << NUM_HORSES << "): ";
    std::cin >> selectedHorse;
    
    while (selectedHorse < 1 || selectedHorse > NUM_HORSES) {
        std::cout << "Invalid horse number. Please enter a number between 1 and " << NUM_HORSES << ": ";
        std::cin >> selectedHorse;
    }
    
    std::cout << "Enter your bet amount: ";
    std::cin >> betAmount;
}

void HorseRace::displayResult(int winner, int selectedHorse, int betAmount) const {
    std::cout << "Horse " << winner << " wins the race!" << std::endl;
    
    if (winner == selectedHorse) {
        std::cout << "Congratulations! You won the bet!" << std::endl;
        std::cout << "Your prize is: $" << betAmount * 2 << std::endl;
    } else {
        std::cout << "Sorry! Your horse didn't win. Better luck next time!" << std::endl;
    }
}

void HorseRace::playGame() {
    int selectedHorse, betAmount;
    getPlayerBet(selectedHorse, betAmount);

    Horse horses[NUM_HORSES];
    initializeHorses(horses);

    std::cout << "Initial Horse Information:" << std::endl;
    printRaceStatus(horses);
    std::cout << "Race starting in 3 seconds..." << std::endl;
    sleep(3);

    int winner = 0;
    while (!(winner = checkWinningCondition(horses))) {
        for (int i = 0; i < NUM_HORSES; ++i) {
            moveHorse(&horses[i]);
            applyFatigue(&horses[i]);
            applyObstacles(&horses[i]);
        }
        printRaceStatus(horses);
        sleep(1);
    }

    displayResult(winner, selectedHorse, betAmount);
}