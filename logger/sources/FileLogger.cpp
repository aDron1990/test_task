#include "FileLogger.hpp"

#include <iostream>

FileLogger::FileLogger(const std::string& fileName) : Logger{}, fileName_{fileName} 
{
    std::ofstream file(fileName_, std::ios::app | std::ios::out);
    file.close();
}

void FileLogger::log(const std::string& logMessage)
{
    mutex_.lock();
    std::cout << "mutex locked\n";

    std::ofstream file(fileName_, std::ios::app | std::ios::out);
    file << logMessage << '\n';
    file.close();
    
    mutex_.unlock();
    std::cout << "mutex unlocked\n";
}
