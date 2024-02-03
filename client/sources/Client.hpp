#pragma once

#include <stdint.h>
#include <string>
#include <netinet/in.h>

class Client
{
private:

    int mySocket_;
    sockaddr_in serverAddress_;
    std::string name_;

public:

    Client(const std::string& name, const uint32_t port);

    void run(const uint32_t timeoutInSeconds);
};
