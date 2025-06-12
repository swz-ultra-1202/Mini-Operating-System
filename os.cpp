#include "os.h"
#include <iostream>
#include <thread>
#include <string>
#include <unistd.h>
#include <cstdlib>
//#include "UI.h"
#include <chrono>

OS::OS(int ramMB, int hdGB, int cores) : hardware(ramMB, hdGB, cores), osName("CrashOS") {}

    // void OS::boot()
    // {
    //             cout<<"========================================================\n";
    //             ui.showBootScreen();
    
    // }
    //         //void run();
    // void OS::shutdown()
    // {
    //             cout<<"----------------------- SHUTTING DOWN THE CrashOS -----------------\n"<<endl;
    //             exit(0);
    // }

void OS::killProcess(int pid) {
    pm.terminateProcess(pid);
}

void OS::allocateResources(int pid, int ram, int hd) {
    if (hardware.allocateRam(ram) && hardware.allocateHD(hd)) {
        std::cout << "Allocated " << ram << "MB RAM and " << hd << "MB HD to process " << pid << std::endl;
    } else {
        std::cout << "Failed to allocate resources for process " << pid << std::endl;
    }
}

void OS::deallocateResources(int pid) {
    // Get resources from the process table
    int ram = 0, hd = 0;
    for (const auto& p : pm.getProcessTable()) {
        if (p.pid == pid) {
            ram = p.ramUsage;
            hd = p.hdUsage;
            break;
        }
    }
    
    hardware.deallocateRam(ram);
    hardware.deallocateHD(hd);
    std::cout << "Deallocated " << ram << "MB RAM and " << hd << "MB HD from process " << pid << std::endl;
}