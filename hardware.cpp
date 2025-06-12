#include<iostream>
#include<iomanip>
#include<mutex>
#include<vector>
#include<thread>
#include<string>
#include<unistd.h>
#include "hardware.h"
using namespace std;


Hardware::Hardware(int ramGB, int hdGB, int core) 
{
    if (ramGB <= 0 || hdGB <= 0 || core <= 0) {
        std::cerr << "Invalid hardware parameters" << std::endl;
        exit(1);
    }
    totalRAM = ramGB * 1024;
    availableRAM = totalRAM;
    totalHD = hdGB * 1024;
    availableHD = totalHD;
    cores = core;
    coreStatus = vector<bool>(core, false);
}
void Hardware::systemInfo()
  {
        cout << "Total RAM: " << totalRAM << " MB" << endl;
        //cout << "Available RAM: " << availableRAM << " MB" << endl;
        cout << "Total HD: " << totalHD << " MB" << endl;
        //cout << "Available HD: " << availableHD << " MB" << endl;
        cout << "Total Cores: " << cores << endl;
        //cout << "Available Cores: ";
        // for (int i = 0; i < cores; ++i) 
        // {
        //     if (!coreStatus[i]) 
        //     {
        //         cout << i + 1 << " ";
        //     }
        // }
        // cout << endl;
    }
void Hardware::resource_info()
{
    cout << "Available RAM: " << availableRAM << " MB" << endl;
    cout << "Available HD: " << availableHD << " MB" << endl;
    cout << "Available Cores: ";
        for (int i = 0; i < cores; ++i) 
        {
            if (!coreStatus[i]) 
            {
                cout << i + 1 << " ";
            }
        }
        cout << endl;
}
    bool Hardware::allocateRam(int amount) 
    {
        lock_guard<mutex> lock(mtx);
        if (availableRAM >= amount) 
        {
            availableRAM -= amount;
            return true;
        }
        return false;
    }

    void Hardware::deallocateRam(int amount) 
    {
        lock_guard<mutex> lock(mtx);
        availableRAM += amount;
        if (availableRAM > totalRAM) availableRAM = totalRAM;
    }

    bool Hardware::allocateHD(int amount) 
    {
        lock_guard<mutex> lock(mtx);
        if (availableHD >= amount) 
        {
            availableHD -= amount;
            return true;
        }
        return false;
    }

    void Hardware::deallocateHD(int amount) 
    {
        lock_guard<mutex> lock(mtx);
        availableHD += amount;
        if (availableHD > totalHD) availableHD = totalHD;
    }

    int Hardware::getAvailableCore() 
    {
        lock_guard<mutex> lock(mtx);
        for (int i = 0; i < cores; ++i) 
        {
            if (!coreStatus[i]) 
            {
                coreStatus[i] = true;
                return i;
            }
        }
        return -1;
    }

    void Hardware::releaseCore(int coreNum) 
    {
        lock_guard<mutex> lock(mtx);
        if (coreNum >= 0 && coreNum < cores) 
        {
            coreStatus[coreNum] = false;
        }
    }

    // void Hardware::getUsageStats() 
    // {
    //     lock_guard<mutex> lock(mtx);
    //     cout << "RAM Usage: " << (totalRAM - availableRAM) << " MB / " << totalRAM << " MB\n";
    //     cout << "HD Usage: " << (totalHD - availableHD) << " MB / " << totalHD << " MB\n";
    //     int busyCores = 0;
    //     for (bool b : coreStatus) if (b) busyCores++;
    //     cout << "CPU Cores Used: " << busyCores << " / " << cores << "\n";
    // }



    