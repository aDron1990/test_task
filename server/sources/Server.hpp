#pragma once

#include "LoggerDateTimeFormatter.hpp"
#include "FileLogger.hpp"

#include <stdint.h>
#include <netinet/in.h>

class Server
{
private:

    sockaddr_in serverAddress;
    int serverSocket;
    std::unique_ptr<Logger> logger;

public:

    Server(const uint32_t port);

    void run();

};