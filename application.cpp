#include<iostream>
#include<iomanip>
#include<mutex>
#include<vector>
#include<thread>
#include<string>
#include<unistd.h>
#include<ctime>
#include<fstream>
#include<cstdlib>
#include "application.h"
#include <ncurses.h>

using namespace std;

       void Applications::calculator()
       {
        cout<<"========================================================="<<endl;
        cout<<"Enter two numbers one by one : "<<endl;
        int n1,n2;
        cin>>n1>>n2;
        cout<<"Choose an operator (+,-,*,/) : "<<endl;
        char opt;
        cin>>opt;
        switch(opt)
        {
            case '+':
            {
                cout<<"Answer : "<<endl;
                cout<<n1<<" + "<<n2<<" = "<<n1+n2<<endl;
                break;
            }
            case '-':
            {
                cout<<"Answer : "<<endl;
                cout<<n1<<" - "<<n2<<" = "<<n1-n2<<endl;
                break;
            }
            case '*':
            {
                cout<<"Answer : "<<endl;
                cout<<n1<<" * "<<n2<<" = "<<n1*n2<<endl;
                break;
            }
            case '/':
            {
                if(n2==0)
                {
                    cout<<"For division denomienator cannot be zero."<<endl;
                    break;
                }
                cout<<"Answer : "<<endl;
                cout<<n1<<" / "<<n2<<" = "<<n1/n2<<endl;
                break;
            }
            default:
            {
                cout<<"Wrong operator . \n Try Again"<<endl;
            }
            cout<<"========================================================="<<endl;
        }
        
       }
       void Applications::printCalendar() 
       {
        int month, year;
    std::cout << "Enter month (1-12): ";
    std::cin >> month;
    std::cout << "Enter year: ";
    std::cin >> year;

    if (month < 1 || month > 12 || year < 1) {
        std::cout << "Invalid input!\n";
        return;
    }

    const std::string months[] = {
        "", "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    int daysInMonth[] = {
        0, 31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        daysInMonth[2] = 29;

    int m = month, y = year;
    if (m < 3) {
        m += 12;
        y--;
    }
    int K = y % 100;
    int J = y / 100;
    int h = (1 + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;
    int startDay = (h + 6) % 7;

    std::cout << "\n     " << months[month] << " " << year << "\n";
    std::cout << "Su Mo Tu We Th Fr Sa\n";

    for (int i = 0; i < startDay; ++i)
        std::cout << "   ";

    for (int day = 1; day <= daysInMonth[month]; ++day) {
        std::cout << std::setw(2) << day << " ";
        if ((startDay + day) % 7 == 0)
            std::cout << "\n";
    }

    std::cout << "\n";
        cout<<"========================================================="<<endl;
    }
       void Applications::clock()
       {
        time_t now = time(0);
        tm *ltm = localtime(&now);
    
        cout << "Current Date and Time:\n";
        cout << 1900 + ltm->tm_year << "-"<< 1 + ltm->tm_mon << "-"<< ltm->tm_mday << " ";
    
        cout << ltm->tm_hour << ":"<< ltm->tm_min << ":"<< ltm->tm_sec << endl;
       }
       

void Applications::ticTacToe() 
{
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int choice;
    int player = 1;
    char mark;
    bool winner = false;

    while (!winner) 
    {
        cout << "\nTic-Tac-Toe Board:\n";
        cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
        cout << " ---+---+---\n";
        cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
        cout << " ---+---+---\n";
        cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";

        cout << "Player " << player << ", enter a number (1-9): ";
        cin >> choice;

        mark = (player == 1) ? 'X' : 'O';

        bool validMove = false;
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (board[i][j] == '0' + choice) 
                {
                    board[i][j] = mark;
                    validMove = true;
                    break;
                }
            }
            if (validMove) break;
        }

        if (!validMove) 
        {
            cout << "Invalid move, try again.\n";
            continue;
        }

        for (int i = 0; i < 3; i++) 
        {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) || (board[0][i] == board[1][i] && board[1][i] == board[2][i])) 
            {
                winner = true;
                break;
            }
        }

        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||(board[0][2] == board[1][1] && board[1][1] == board[2][0])) 
            {
            winner = true;
        }

        bool draw = true;
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    draw = false;
                    break;
                }
            }
            if (!draw) break;
        }

        if (draw) 
        {
            cout << "\nTic-Tac-Toe Board:\n";
            cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
            cout << " ---+---+---\n";
            cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
            cout << " ---+---+---\n";
            cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
            cout << "It's a draw!\n";
            break;
        }

        player = (player == 1) ? 2 : 1;
    }

    if (winner) 
    {
        cout << "\nTic-Tac-Toe Board:\n";
        cout << "  " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << "\n";
        cout << " ---+---+---\n";
        cout << "  " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << "\n";
        cout << " ---+---+---\n";
        cout << "  " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << "\n";
        cout << "Player " << ((player == 1) ? 2 : 1) << " wins!\n";
    }
}
    void Applications::mathQuiz() 
    {
        srand(time(0));
        int a = rand() % 10 + 1;
        int b = rand() % 10 + 1;
        int answer, userAnswer;
    
        answer = a + b;
        cout << "What is " << a << " + " << b << "? ";
        cin >> userAnswer;
    
        if (userAnswer == answer)
            cout << "Correct!\n";
        else
            cout << "Wrong! The correct answer is " << answer << ".\n";
    }
    void Applications::guessNumber()
    {
        cout<<"==================== Guessing game ==================="<<endl;
        srand(time(0));
        int secret = rand() % 1000 + 1;
        int guess;
        int attempts=3;
        cout<<"Guess a number between 1 and 1000. you have "<< attempts<<" attempts ." <<endl;
        for(int i=0;i<attempts;i++)
        {
            cout<<"Attempt No."<<i+1<<"\nEnter your guess number : "<<endl;
            cin>>guess;
            if(guess==secret)
            {
                cout<<"You Won \nAttempts "<<i<<endl;
                return;
            }
            else if(guess>secret)
            {
                cout<<"You go high choose a less number ."<<endl;
            }
            else
            {
                cout<<"You choose low number choose a high number."<<endl;
            }
            

        }
        cout << "Out of attempts! The correct number was " << secret << ".\n";
  
       
    }
       //void resourceMonitor();

    void Applications::notepad()
    {
        string fileName,line;
        cout<<"Enter File Name : ";
        cin>>fileName;

        ofstream file(fileName + ".txt");
        cin.ignore();
        cout<<"======================= Notepad =================================="<<endl;
        cout<<"Write in your File "<<endl;
        while(getline(cin,line))
        {
            if(line=="end"||line=="End"||line=="END")
            {
                file<<line<<endl;
                cout<<"File Created Successfully ."<<endl;
                cout<<"======================= Notepad =================================="<<endl;
                cout<<"File Name : "<<fileName<<endl;
                cout<<"File Content : "<<endl;
                cout<<line<<endl;
                return;
               
            }
        }

        file.close();
        ifstream readFile(fileName + ".txt");
        cout << "\n\n--- Content of " << fileName << ".txt ---\n";
        while (getline(readFile, line)) {
            cout << line << endl;
        }
        readFile.close();

    }
        
