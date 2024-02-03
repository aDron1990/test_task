#include "FileLogger.hpp"

FileLogger::FileLogger(const std::string& fileName) : Logger{}, file{fileName, std::ios::out | std::ios::app} {}

void FileLogger::log(const std::string& logMessage)
{
    file << logMessage << std::endl;
}
