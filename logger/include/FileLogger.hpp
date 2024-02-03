#pragma once

#include "Logger.hpp"

#include <fstream>
#include <mutex>

class FileLogger: public Logger
{
protected:

    std::mutex mutex_;
    std::string fileName_;

public:

    FileLogger(const std::string& fileName);

    virtual void log(const std::string& logMessage) override;

};