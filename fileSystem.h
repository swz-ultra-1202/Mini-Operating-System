// In fileSystem.h
#ifndef FILESYSTEM_H
#define FILESYSTEM_H
#include <vector>
#include <string>
#include<iostream>
#include<filesystem>
class FileSystem 
{
    public:
    FileSystem(){}
    bool createFile(std::string filename, std::string content);  
    bool deleteFile(std::string filename);
    bool moveFile(std::string src, std::string dest);
    bool copyFile(std::string src, std::string dest);
    std::string getFileInfo(std::string filename);
    std::vector<std::string> listDirectory(std::string path);
    };
#endif