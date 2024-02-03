#pragma once

#include "Logger.hpp"

#include <memory>
#include <functional>

class LoggerDateTimeFormatter : public Logger
{
protected:

    std::unique_ptr<Logger> logger_;

public:

    LoggerDateTimeFormatter(std::unique_ptr<Logger> logger);

    void log(const std::string& logMessage) override;

};