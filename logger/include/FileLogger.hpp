#pragma once

#include "Logger.hpp"

#include <fstream>

class FileLogger: public Logger
{
protected:

    std::ofstream file;

public:

    FileLogger(const std::string& fileName);

    virtual void log(const std::string& logMessage) override;

};