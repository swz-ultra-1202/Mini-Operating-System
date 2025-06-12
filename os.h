#ifndef OS_H
#define OS_H

#include "hardware.h"
#include "Manager.h"
#include "fileSystem.h"
//#include "UI.h"
#include "application.h"
#include<iostream>
class OS {
public:
    OS(int ramMB, int hdGB, int cores);
    OS(){}
    // void boot();
    // void run();
    // void shutdown();
    void killProcess(int pid);
    void allocateResources(int pid, int ram, int hd);
    void deallocateResources(int pid);
    
private:
    std::string osName;
    Hardware hardware;
    process_manager::ProcessManager pm;
    FileSystem fs;
    Applications apps;
    //User_Interface ui;
};

#endif