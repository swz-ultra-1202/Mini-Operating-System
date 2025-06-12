#ifndef UI_H
#define UI_H

#include "hardware.h"
#include "Manager.h"
#include "application.h"
#include <iostream>
#include <vector>
#include<filesystem>
#include <thread>
#include <string>
#include <unistd.h>
#include "fileSystem.h"
#include "MINI_INSTAGRAM.h"
#include "Manager.h"
#include<fstream>
#include "horse.h"
#include "iq.h"
#include "os.h"
#include "typing_test.h"
using namespace std;
namespace fs = std::filesystem;

class User_Interface
{
public:
    Hardware hr;
    process_manager::ProcessManager pm;
    Applications ap;
    user_networks network;
    OS os;
    FileSystem file;
    HorseRace hrace;
    IQTest test;
    TypingTest typingTest;

    User_Interface(){}

    void showBootScreen();
    void showMainMenu();
    void drawBox(int startX, int startY, int width, int height, const std::string& title);
    void displayIcon(int startX, int startY, const std::string& icon, const std::string& label);
    // void showprocess_manager();
    // void showFileManager();
    // void showGamesMenu();
    void setPassword();
    std::string getPassword();
    void login();
    void shutdownAnimation();
    void clearScreen();
    //void changePassword();
};

#endif // UI_H
