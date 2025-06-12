#ifndef MANAGER_H
#define MANAGER_H

#include <string>
#include <vector>
#include <queue>
#include<iostream>
namespace process_manager {

struct Process {
    int pid;
    std::string name;
    int ramUsage;
    int hdUsage;
    int coreAffinity;
    int priority;
    
    Process(int id, std::string n, int ram, int hd, int cores, int prio);
};

class ProcessManager {
public:
ProcessManager(){}
    int createProcess(std::string appName, int ramReq, int hdReq, int coreReq, int priority = 1);
    bool terminateProcess(int pid);
    void scheduleProcesses();
    void showPCBTable();
    void roundRobin();
    void priorityScheduling();
    
    // Additional helper functions
    const std::vector<Process>& getProcessTable() const { return processTable; }
    
private:
    std::vector<Process> processTable;
    std::queue<Process> readyQueue;
    int pidCounter = 1;
};

} // namespace process_manager

#endif