#include "LoggerDateTimeFormatter.hpp"

#include <ctime>
#include <chrono>
#include <iomanip>
#include <sstream>

LoggerDateTimeFormatter::LoggerDateTimeFormatter(std::unique_ptr<Logger> logger)
: logger_{std::move(logger)}{}

void LoggerDateTimeFormatter::log(const std::string& logMessage)
{
    using namespace std::chrono;

    std::time_t time = std::time(nullptr);
    std::tm* now = std::localtime(&time);
    auto ch_now = system_clock::now();

    std::stringstream formattedMessage_ss;
    formattedMessage_ss  << std::put_time(now, "[%Y-%m-%d %H:%M:%S.") << std::setfill('0') << std::setw(3) << duration_cast<milliseconds>(ch_now.time_since_epoch()).count() % 1000 << "] " << logMessage;
    std::string formattedMessage = formattedMessage_ss.str();

    logger_->log(formattedMessage);
}