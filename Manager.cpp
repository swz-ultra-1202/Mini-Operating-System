#include "Manager.h"
#include <algorithm>
#include <iostream>
#include <iomanip>

namespace process_manager {

Process::Process(int id, std::string n, int ram, int hd, int cores, int prio)
    : pid(id), name(n), ramUsage(ram), hdUsage(hd), coreAffinity(cores), priority(prio) {}

int ProcessManager::createProcess(std::string appName, int ramReq, int hdReq, int coreReq, int priority) {
    Process newProcess(pidCounter++, appName, ramReq, hdReq, coreReq, priority);
    processTable.push_back(newProcess);
    readyQueue.push(newProcess);
    std::cout << "Process " << appName << " created with PID: " << newProcess.pid << std::endl;
    return newProcess.pid;
}

bool ProcessManager::terminateProcess(int pid) {
    auto it = std::find_if(processTable.begin(), processTable.end(), 
        [pid](const Process& p) { return p.pid == pid; });
    
    if (it != processTable.end()) {
        processTable.erase(it);
        
        // Remove from ready queue if present
        std::queue<Process> temp;
        while (!readyQueue.empty()) {
            Process p = readyQueue.front();
            readyQueue.pop();
            if (p.pid != pid) {
                temp.push(p);
            }
        }
        readyQueue = temp;
        
        std::cout << "Process with PID: " << pid << " terminated." << std::endl;
        return true;
    }
    
    std::cout << "Process with PID: " << pid << " not found." << std::endl;
    return false;
}

void ProcessManager::scheduleProcesses() {
    std::cout << "\nScheduling Processes:" << std::endl;
    std::queue<Process> temp = readyQueue;
    
    while (!temp.empty()) {
        Process p = temp.front();
        temp.pop();
        std::cout << "PID: " << p.pid << ", Name: " << p.name 
                  << ", RAM: " << p.ramUsage << " MB, HDD: " << p.hdUsage 
                  << " MB, Cores: " << p.coreAffinity << std::endl;
    }
}

void ProcessManager::showPCBTable() {
    std::cout << "\nProcess Control Block (PCB) Table:" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    std::cout << "| PID | Name          | RAM (MB) | HDD (MB) | Cores | Priority |" << std::endl;
    std::cout << "-------------------------------------------------------------" << std::endl;
    
    for (const auto& p : processTable) {
        std::cout << "| " << std::setw(3) << p.pid << " | " << std::setw(12) << p.name << " | " 
                  << std::setw(7) << p.ramUsage << " | " << std::setw(7) << p.hdUsage << " | " 
                  << std::setw(5) << p.coreAffinity << " | " << std::setw(8) << p.priority << " |" << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
}

void ProcessManager::roundRobin() {
    std::cout << "\nRound Robin Scheduling:" << std::endl;
    std::queue<Process> temp = readyQueue;
    
    while (!temp.empty()) {
        Process p = temp.front();
        temp.pop();
        std::cout << "Executing Process PID: " << p.pid << " (" << p.name << ") for 1 quantum." << std::endl;
    }
}

void ProcessManager::priorityScheduling() {
    std::cout << "\nPriority Scheduling:" << std::endl;
    std::vector<Process> sortedProcesses = processTable;
    
    std::sort(sortedProcesses.begin(), sortedProcesses.end(), 
        [](const Process& a, const Process& b) {
            return a.priority > b.priority;
        });
    
    for (const auto& p : sortedProcesses) {
        std::cout << "Executing Process PID: " << p.pid << " (" << p.name 
                  << ") with priority " << p.priority << "." << std::endl;
    }
}

} // namespace process_manager