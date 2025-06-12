#include "os.h"
#include "hardware.h"
#include "Manager.h"
#include "fileSystem.h"
#include "UI.h"
#include "application.h"
#include "MINI_INSTAGRAM.h"
#include<iostream>
using namespace std;
int main(int argc, char* argv[]) 
{
    if (argc != 4) 
    {
        cout << "Usage: ./os <RAM_MB> <HDD_GB> <Cores>\n";
        return 1;
    }

    int ram = atoi(argv[1]);    
    int hdd = atoi(argv[2]);
    int cores = atoi(argv[3]);
    OS os(ram,hdd,cores);
    Hardware hd(ram,hdd,cores);



    User_Interface ui;
    ui.showBootScreen();
    ui.login();
    //ui.showMainMenu();




}