#include "FileLogger.hpp"

#include <iostream>

FileLogger::FileLogger(const std::string& fileName) : Logger{}, fileName_{fileName} 
{
    std::ofstream file(fileName_, std::ios::app | std::ios::out);
    file.close();
}

void FileLogger::log(const std::string& logMessage)
{
    std::unique_lock<std::mutex> guard{mutex_};
    std::ofstream file(fileName_, std::ios::app | std::ios::out);
    file << logMessage << '\n';
}
