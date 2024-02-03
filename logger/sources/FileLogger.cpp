#include "FileLogger.hpp"

FileLogger::FileLogger(const std::string& fileName) : Logger{}, file_{fileName, std::ios::out | std::ios::app} {}

void FileLogger::log(const std::string& logMessage)
{
    std::lock_guard<std::mutex> lock{mutex_};
    file_ << logMessage << std::endl;
}
