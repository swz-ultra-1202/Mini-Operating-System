#include "fileSystem.h"
#include <filesystem>
#include <fstream>
#include <chrono>
#include <ctime>
#include<iostream>
namespace fs = std::filesystem;

bool FileSystem::createFile(std::string filename, std::string content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    file << content;
    return true;
}

bool FileSystem::deleteFile(std::string filename) {
    return fs::remove(filename);
}

bool FileSystem::moveFile(std::string src, std::string dest) {
    try {
        fs::rename(src, dest);
        return true;
    } catch (...) {
        return false;
    }
}

bool FileSystem::copyFile(std::string src, std::string dest) {
    try {
        fs::copy(src, dest);
        return true;
    } catch (...) {
        return false;
    }
}

std::string FileSystem::getFileInfo(std::string filename) {
        try {
            auto ftime = fs::last_write_time(filename);
            auto size = fs::file_size(filename);
            
            // C++17 compatible time conversion
            auto sctp = std::chrono::time_point_cast<std::chrono::system_clock::duration>(
                ftime - fs::file_time_type::clock::now() + std::chrono::system_clock::now());
            std::time_t cftime = std::chrono::system_clock::to_time_t(sctp);
            
            std::string timeStr = std::ctime(&cftime);
            timeStr.erase(timeStr.find_last_not_of("\n") + 1);
            
            return "Size: " + std::to_string(size) + " bytes, Last modified: " + timeStr;
        } catch (...) {
            return "Error getting file info";
        }
    }

std::vector<std::string> FileSystem::listDirectory(std::string path) {
    std::vector<std::string> files;
    for (const auto& entry : fs::directory_iterator(path)) {
        files.push_back(entry.path().filename().string());
    }
    return files;
}