#ifndef HORSE_H
#define HORSE_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

const int NUM_HORSES = 8;
const int FINISH_LINE = 100;

struct Horse {
    int speed;
    int endurance;
    int position;
    int fatigue;
};

class HorseRace {
public:
    HorseRace();
    void playGame();
    
private:
    void moveHorse(Horse* horse);
    void applyFatigue(Horse* horse);
    void applyObstacles(Horse* horse);
    void printRaceStatus(const Horse* horses) const;
    int checkWinningCondition(const Horse* horses) const;
    void initializeHorses(Horse horses[NUM_HORSES]);
    void getPlayerBet(int& selectedHorse, int& betAmount) const;
    void displayResult(int winner, int selectedHorse, int betAmount) const;
};

#endif // HORSE_RACE_H