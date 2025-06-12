#include<iostream>
#include<iomanip>
#include<mutex>
#include<vector>
#include<thread>
#include<chrono>
#include<random>
#include<string>
#include<unistd.h>
#include"hardware.h"
#include"Manager.h"
#include"fileSystem.h"
#include"application.h"
#include<cstring>
#include "UI.h"
#include<fstream>
#include<cstdlib>
#include <filesystem>
#include "MINI_INSTAGRAM.h"
#include "os.h"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN "\033[1;36m"
#define RESET "\033[0m"
using namespace std;
//namespace fs = std::filesystem;


void User_Interface::clearScreen() {
    system("clear");
}
       
void User_Interface::showMainMenu()
{
    int choice;
    while (true)
    {
        cout << "\t\t\t\t\t\t\t\t=====================================================================================" << endl;
        cout << "\t\t\t\t\t\t\t\t|1. Calculator                                 | (1 Core, 125 MB HDD, 3 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|2. Calendar                                   | (1 Core, 50 MB HDD, 2 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|3. Clock                                      | (1 Core, 25 MB HDD, 1 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|4. Notepad                                    | (1 Core, 30 MB HDD, 5 MB RAM)" << endl;
        //cout << "\t\t\t\t\t\t\t\t|5. File create                                | (1 Core, 50 MB HDD, 10 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|5. File delete                                | (1 Core, 25 MB HDD, 5 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|6. Horse Bet Game                             | (1 Core, 100 MB HDD, 15 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|7. System info                                | (1 Core, 20 MB HDD, 2 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|8. PCB table                                  | (1 Core, 50 MB HDD, 5 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|9. Mini Instagram                            | (1 Core, 75 MB HDD, 8 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|10. List Current Directory                    | (1 Core, 10 MB HDD, 2 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|11. Terminate Process                         | (1 Core, 30 MB HDD, 4 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|12. Schedule tasks                            | (1 Core, 40 MB HDD, 5 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|13. TicTacToe                                 | (1 Core, 50 MB HDD, 5 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|14. Math Quiz                                 | (1 Core, 60 MB HDD, 4 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|15. Guess the number                          | (1 Core, 30 MB HDD, 3 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|16. Resource Monitor (RAM/CPU usage)          | (1 Core, 40 MB HDD, 6 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|17. IQ checke                                 | (1 Core, 50 MB HDD, 4 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|18. Typing Test                               | (1 Core, 50 MB HDD, 5 MB RAM)" << endl;
        cout << "\t\t\t\t\t\t\t\t|19. Sutting Down                              |" << endl;
        cout << "\t\t\t\t\t\t\t\t=====================================================================================" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Calculator task is selected." << endl;
            if(hr.allocateRam(3) && hr.allocateHD(125)) {
                pm.createProcess("Calculator", 2, 50, 1, 1);
                pm.scheduleProcesses();
                pm.roundRobin();
                pm.priorityScheduling();
                
                // function to access new window
                
                //ap.calculator();
                 system("gnome-calculator &");
            } else {
                cout << "Cannot have enough resources to execute task." << endl;
            }
            sleep(5);
            system("clear");
            break;
        }
        case 2:
        {
            cout << "Calendar task is selected." << endl;
            if(hr.allocateRam(2) && hr.allocateHD(50)) {
                pm.createProcess("Calendar", 2, 50, 1, 1);
                pm.scheduleProcesses();
                pm.roundRobin();
                pm.priorityScheduling();
                ap.printCalendar();
                //system("gnome-calendar &");
            } else {
                cout << "Cannot have enough resources to execute task." << endl;
            }
            sleep(5);
    system("clear");
            break;
        }
        case 3:
        {
            cout << "Clock task is selected." << endl;
            if(hr.allocateRam(1) && hr.allocateHD(25)) {
                pm.createProcess("Clock", 2, 25, 1, 1);
                pm.scheduleProcesses();
                pm.roundRobin();
                pm.priorityScheduling();
                // system("gnome-shell --replace &");
                // system("gnome-control-center datetime &");
                ap.clock();
            } else {
                cout << "Not enough resources." << endl;
            }
            sleep(5);
    system("clear");
            break;
        }
        case 4:
        {
            cout << "Notepad task is selected." << endl;
            if(hr.allocateRam(5) && hr.allocateHD(30)) 
            {
                pm.createProcess("Notepad", 2, 30, 1, 1);
                pm.scheduleProcesses();
                pm.roundRobin();
                pm.priorityScheduling();
               // ap.notepad();
                std::string filename;

                std::cout << "Enter file name to open with Gedit : ";
              cin>>filename;  // Get filename from user

              std::string command = "gedit \"" + filename + "\" &";  // Prepare command
              system(command.c_str());  // Run the command
   
            }
            sleep(5);
    system("clear");
            break;
        }
    //     case 5:
    //     {
    //         cout << "File create task is selected." << endl;
    //         if(hr.allocateRam(10) && hr.allocateHD(50)) {
    //             pm.createProcess("FileCreate", 2, 50, 1, 1);
    //             pm.scheduleProcesses();
    //             pm.roundRobin();
    //             pm.priorityScheduling();
    //             string str, cont;
    //             cout<<"Enter File name : ";
    //             cin>>str;
    //             cin.ignore();
    //             cout<<"Enter Content of File : ";
    //             cin>>cont;
    //             cout<<"Creating file "<<str<<endl;
    //             cout<<"Content of file : "<<cont<<endl;
    //             if(file.createFile(str,cont))
    //             {
    //                 cout<<"File created."<<endl;
    //             }
    //             else
    //             {
    //                 cout<<"Error in creating file."<<endl;
    //             }
    //         } else {
    //             cout << "Not enough resources." << endl;
    //          }
    //          sleep(5);
    // system("clear");
    //         break;
    //     }
        case 5:
        {
            cout << "File delete task is selected." << endl;
        
                string filename;
                cout<<"Enter File name to delete : ";
                cin>>filename;
                cout<<"Deleting file "<<filename<<endl;
                if(file.deleteFile(filename))
                {
                    cout<<"File deleted."<<endl;
                }
                else
                {
                    cout<<"Error in deleting file."<<endl;
                }
                sleep(5);
                system("clear");
            break;
        }
        case 6:
        {
            cout << "Horse Bet Game is selected." << endl;
            if(hr.allocateRam(8) && hr.allocateHD(75)) {
                pm.createProcess("MiniInstagram", 8, 75, 1, 1);
                pm.scheduleProcesses();
                pm.roundRobin();
                //pm.priorityScheduling();
                hrace.playGame();
            } else {
                cout << "Not enough resources." << endl;
            }
            
    
            //system("clear");
            sleep(1);
            sleep(5);
            system("clear");
            break;
        }
        case 7:
        {
            cout << "System info task is selected." << endl;
            hr.systemInfo();
            sleep(5);
            system("clear");
            break;
        }
        case 8:
        {
            cout << "PCB table task is selected." << endl;
            
                pm.showPCBTable();
                sleep(5);
                system("clear");
            break;
        }
        case 9:
            cout << "Mini Instagram is selected." << endl;
            if(hr.allocateRam(8) && hr.allocateHD(75)) {
                pm.createProcess("MiniInstagram", 8, 75, 1, 1);
                pm.scheduleProcesses();
                pm.roundRobin();
                //pm.priorityScheduling();
                system("clear");
                network.showMenu();
            } else {
                cout << "Not enough resources." << endl;
            }
            sleep(5);
            system("clear"); 
            break;
        case 10:
        {
            cout << "List Current Directory task is selected." << endl;
            string path = "."; // Current directory

            cout << "Files in current directory:\n";
            for (const auto& entry : fs::directory_iterator(path)) 
            {
                cout << entry.path().filename() << '\n';
            }
            sleep(5);
    system("clear");
            break;
        }
        
        case 11:
        {
            cout << "Terminate Process task is selected." << endl;
            int pid;
            cout<<"Enter pid to terminate that process : "<<endl;
            cin>>pid;
           pm.terminateProcess(pid);

           sleep(5);
           system("clear");
            break;
        }
        case 12:
        {
            cout << "Schedule tasks is selected." << endl;
            cout << "\n\n---------Scheduling-----------" << endl;
            cout << "1. Priority Scheduling" << endl;
            cout << "2. Round Robin Scheduling" << endl;
            cout << "3. Ready Queue" << endl;
            int sc;
            cout << "\n\nEnter choice : ";
            cin >> sc;
            switch (sc)
            {
                case 1:
                    pm.priorityScheduling();
                    break;
                case 2:
                    pm.roundRobin();
                    break;
                case 3:
                    pm.scheduleProcesses();
                    break;
            }
            sleep(5);
            system("clear");
            break;
        }
        case 13:
        {
            cout << "TicTacToe game is selected." << endl;
            if(hr.allocateRam(5) && hr.allocateHD(50)) {
                pm.createProcess("TicTacToe", 2, 50, 1, 1);
                pm.scheduleProcesses();
                pm.roundRobin();
                pm.priorityScheduling();
                ap.ticTacToe();
            } else {
                cout << "Not enough resources." << endl;
            }
            sleep(5);
            system("clear");
            break;
        }
        case 14:
        {
            cout << "Math Quiz game is selected." << endl;
            if(hr.allocateRam(4) && hr.allocateHD(60)) {
                pm.createProcess("MathQuiz", 2, 60, 1, 1);
                pm.scheduleProcesses();
                pm.roundRobin();
                pm.priorityScheduling();
                ap.mathQuiz();
            } else {
                cout << "Not enough resources." << endl;
            }
            sleep(5);
            system("clear");
            break;
        }
        case 15:
        {
            cout << "Guess the Number game is selected." << endl;
            if(hr.allocateRam(3) && hr.allocateHD(30)) {
                pm.createProcess("GuessNumber", 2, 30, 1, 1);
                pm.scheduleProcesses();
                pm.roundRobin();
                pm.priorityScheduling();
                ap.guessNumber();
            } else {
                cout << "Not enough resources." << endl;
            }
            sleep(5);
            system("clear");
            break;
        }
        case 16:
        {

            hr.resource_info();
            sleep(5);
    system("clear");
            break;
        }
        case 17:
        {
            if(hr.allocateRam(3) && hr.allocateHD(30)) {
                pm.createProcess("GuessNumber", 2, 30, 1, 1);
                pm.scheduleProcesses();
                pm.roundRobin();
                pm.priorityScheduling();
                test.runTest();
            } else {
                cout << "Not enough resources." << endl;
            }
            
            sleep(5);
            system("clear");
            break;
        }
        case 18:
        {
            cout << "Typing Test is selected." << endl;
            if(hr.allocateRam(3) && hr.allocateHD(30)) {
                pm.createProcess("GuessNumber", 2, 30, 1, 1);
                pm.scheduleProcesses();
                pm.roundRobin();
                pm.priorityScheduling();
                typingTest.runTest();
            } else {
                cout << "Not enough resources." << endl;
            }
           
            
            

            sleep(5);
            system("clear");
                
            break;
        }
        case 19:
        {
            // cout<<"Shutting down the system..."<<endl;
            // cout<<"----------------------- SHUTTING DOWN THE CrashOS -----------------\n"<<endl;
            // exit(0);



            shutdownAnimation();
            
            break;
        }
           
            //return;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}


void User_Interface::shutdownAnimation() {
    clearScreen();
    
    // Red alert frame
    cout << RED;
    for (int i = 0; i < 3; i++) {
        cout << "\t\t\t##################################################\n";
        cout << "\t\t\t#                                                #\n";
    }
    cout << RESET;
    
    // Blinking shutdown text
    for (int i = 0; i < 3; i++) {
        cout << RED << "\t\t\t\t    !!! SHUTTING DOWN CrashOS !!!" << RESET << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
        clearScreen();
        this_thread::sleep_for(chrono::milliseconds(300));
    }
    
    // Countdown animation
    cout << RED;
    for (int i = 5; i > 0; i--) {
        cout << "\t\t\t\t   SYSTEM SHUTDOWN IN: " << i << " \n";
        cout << "\t\t\t\t   ";
        for (int j = 0; j < 5-i; j++) cout << "■ ";
        cout << RESET << flush;
        this_thread::sleep_for(chrono::milliseconds(1000));
        clearScreen();
    }
    
    // Final shutdown message
    cout << RED << R"(
        ███████╗██╗  ██╗██╗   ██╗████████╗███████╗██████╗ 
        ██╔════╝██║  ██║██║   ██║╚══██╔══╝██╔════╝██╔══██╗
        ███████╗███████║██║   ██║   ██║   █████╗  ██║  ██║
        ╚════██║██╔══██║██║   ██║   ██║   ██╔══╝  ██║  ██║
        ███████║██║  ██║╚██████╔╝   ██║   ███████╗██████╔╝
        ╚══════╝╚═╝  ╚═╝ ╚═════╝    ╚═╝   ╚══════╝╚═════╝ 
    )" << RESET << endl;
    
    // Fading dots animation
    for (int i = 0; i < 3; i++) {
        cout << "\t\t\t\t   Shutting down services";
        for (int j = 0; j < 3; j++) {
            cout << "." << flush;
            this_thread::sleep_for(chrono::milliseconds(300));
        }
        cout << "\r                           \r";
    }
    
    exit(0);
}

//set password to access the system
void User_Interface::setPassword() {
    string password;
    cout << "Enter new password: ";
    cin >> password;

    // Write password to file
    ofstream passwordFile("password.txt");
    if (passwordFile.is_open()) {
        passwordFile << password;
        passwordFile.close();
        cout << "Password set successfully!" << endl;
    } else {
        cout << "Error: Unable to set password!" << endl;
    }
}

std::string User_Interface::getPassword() {
    string password;
    ifstream passwordFile("password.txt");
    
    if (passwordFile.is_open()) {
        getline(passwordFile, password);
        passwordFile.close();
    } else {
        cout << "Error: Password file not found!" << endl;
        password = ""; // Return empty string if file doesn't exist
    }
    
    return password;
}



        void clearScreen() {
            system("clear");
        }


        




















        void matrixEffect(int durationSec) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(33, 126);
            uniform_int_distribution<> len(5, 15);
            uniform_int_distribution<> pos(0, 80);
        
            auto end = chrono::steady_clock::now() + chrono::seconds(durationSec);
            // while (chrono::steady_clock::now() < end) {
            //     cout << GREEN;
            //     for (int i = 0; i < 5; i++) {
            //         int x = pos(gen);
            //         int l = len(gen);
            //         cout << "\033[" << l << ";" << x << "H";
            //         for (int j = 0; j < l; j++) {
            //             cout << static_cast<char>(dis(gen));
            //         }
            //     }
            //     cout << RESET;
            //     usleep(50000);
            // }
            // cout << "\033[0;0H"; 
        }
        
        void drawProgressBar(int progress, int total = 100, int barWidth = 50) {
            float percentage = static_cast<float>(progress) / total;
            int pos = barWidth * percentage;
            
            cout << MAGENTA << "\t\t\t[";
            for (int i = 0; i < barWidth; ++i) {
                if (i < pos) cout << "≡";
                else if (i == pos) cout << ">";
                else cout << " ";
            }
            cout << "] " << int(percentage * 100.0) << "%\r" << RESET;
            cout.flush();
        }
        
        void animateTyping(const string& text, int delayMs = 30, bool randomColor = false) {
            vector<string> colors = {RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN};
            random_device rd;
            mt19937 gen(rd());
            
            for (char c : text) {
                if (randomColor) {
                    uniform_int_distribution<> dis(0, colors.size()-1);
                    cout << colors[dis(gen)] << c << RESET << flush;
                } else {
                    cout << c << flush;
                }
                this_thread::sleep_for(chrono::milliseconds(delayMs));
            }
        }
        
       
        

        void User_Interface::showBootScreen() {
            clearScreen();
        
            // Stylized CRASHOS Title
            cout << RED << R"(
                     ██████╗██████╗  █████╗ ███████╗██╗  ██╗ ██████╗ ███████╗
                    ██╔════╝██╔══██╗██╔══██╗██╔════╝██║  ██║██╔═══██╗██╔════╝
                    ██║     ██████╔╝███████║███████╗███████║██║   ██║███████╗
                    ██║     ██╔══██╗██╔══██║╚════██║██╔══██║██║   ██║╚════██║
                    ╚██████╗██║  ██║██║  ██║███████║██║  ██║╚██████╔╝███████║
                     ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ ╚═════╝ ╚══════╝
                 )" << RESET << endl << endl;
                
        
            // Simulated Matrix Background
            matrixEffect(1);
        
            // Typing Animation for Boot Message
            animateTyping("\n\n\t\t\t>>> SYSTEM BOOT SEQUENCE INITIATED...\n\n", 25, true);
            this_thread::sleep_for(chrono::milliseconds(1000));
        
            // Author Credits with Centering
            string author = "DEVELOPED BY: M.SHAH NAWAZ & ABDUL MUJEEB";
            cout << "\t\t\t";
            animateTyping(author, 35);
            cout << "\n\n";
        
            // Decorative Line
            cout << "\t\t\t";
            for (int i = 0; i < 75; ++i) cout << "─";
            cout << "\n";
        
            // Progress Bar Animation
            cout << "\n\t\t\tSYSTEM INITIALIZATION:\n\n";
            for (int i = 0; i <= 100; ++i) {
                drawProgressBar(i, 100, 60);
                this_thread::sleep_for(chrono::milliseconds(30 + rand() % 25));
            }
            cout << GREEN << "\n\t\t\tSYSTEM READY ✓\n" << RESET << endl;
        
            // System Checks (like BIOS)
            vector<string> checks = {
                "• MEMORY TEST .............. ",
                "• STORAGE CONTROLLER ....... ",
                "• NETWORK INTERFACES ........ ",
                "• SECURITY MODULES .......... ",
                "• USER INTERFACE ............ "
            };
        
            cout << endl;
            for (auto& check : checks) {
                cout << "\t\t\t" << YELLOW;
                animateTyping(check, 10);
                this_thread::sleep_for(chrono::milliseconds(200));
                cout << GREEN << "OK" << RESET << endl;
                this_thread::sleep_for(chrono::milliseconds(150));
            }
        }
        void User_Interface::login() {
            string storedPassword = getPassword();
            clearScreen();
            
            cout << BLUE << R"(
            ██╗      ██████╗  ██████╗ ██╗███╗   ██╗
            ██║     ██╔═══██╗██╔════╝ ██║████╗  ██║
            ██║     ██║   ██║██║  ███╗██║██╔██╗ ██║
            ██║     ██║   ██║██║   ██║██║██║╚██╗██║
            ███████╗╚██████╔╝╚██████╔╝██║██║ ╚████║
            ╚══════╝ ╚═════╝  ╚═════╝ ╚═╝╚═╝  ╚═══╝
            )" << RESET << endl << endl;
        
            animateTyping("\t\t\tACCESS TO CRASHOS SECURE SYSTEM\n\n", 30, true);
            
            if (storedPassword.empty()) {
                cout << RED;
                animateTyping("\t\tNO ADMIN CREDENTIALS DETECTED\n", 20);
                animateTyping("\t\tINITIALIZING SECURITY PROTOCOL\n", 20);
                cout << RESET;
                sleep(1);
                setPassword();
                return;
            }
        
            string enteredPassword;
            int attempts = 3;
        
            while (attempts > 0) {
                cout << "\n\t\t" << CYAN << "ENTER SECURITY CODE (" << attempts << " ATTEMPTS REMAINING): " << RESET;
                
                #ifdef __linux__
                system("stty -echo");
                #endif
                
                cin >> enteredPassword;
                
                #ifdef __linux__
                system("stty echo");
                #endif
                cout << endl;
                
                if (enteredPassword == storedPassword) {
                    cout << "\t\t";
                    animateTyping("✓ BIOMETRIC VERIFICATION COMPLETE\n", 10, true);
                    
                    cout << "\t\t";
                    for (int i = 0; i < 3; i++) {
                        cout << "LOADING SYSTEM";
                        for (int j = 0; j < 3; j++) {
                            cout << "." << flush;
                            this_thread::sleep_for(chrono::milliseconds(300));
                        }
                        cout << "\r             \r";
                    }
                    
                    clearScreen();
                    showMainMenu();
                    return;
                } else {
                    cout << "\t\t" << RED;
                    animateTyping("✗ ACCESS DENIED\n", 10);
                    cout << RESET;
                    attempts--;
                }
            }
        
            cout << "\n\t\t" << RED;
            animateTyping("⚠ TOO MANY FAILED ATTEMPTS\n", 20);
            cout << RESET;
            exit(0);
        }