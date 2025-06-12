// Hardware.h
#ifndef HARDWARE_H
#define HARDWARE_H

#include <vector>
#include <mutex>
#include<iostream>
class Hardware 
{
private:
    int totalRAM;
    int availableRAM;
    int totalHD;
    int availableHD;
    int cores;
    std::vector<bool> coreStatus;
    std::mutex mtx;

public:


    Hardware(int ramGB, int hdGB, int core);
    Hardware(): Hardware(8, 256, 4){}
    bool allocateRam(int amount);
    void deallocateRam(int amount);
    void systemInfo();
    bool allocateHD(int amount);
    void deallocateHD(int amount);
    int getAvailableCore();
    void releaseCore(int coreNum);
    void resource_info();
    // void getUsageStats();
};

#endif // HARDWARE_H
