#include "Client.hpp"

#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>

Client::Client(const std::string& name, const uint32_t port)
: name_{name}
{
    mySocket_ = socket(AF_INET, SOCK_STREAM, 0);
    serverAddress_.sin_family = AF_INET;
    serverAddress_.sin_port = htons(port);
    serverAddress_.sin_addr.s_addr = INADDR_ANY;
}

void Client::run(const uint32_t timeoutInSeconds)
{
    if (connect(mySocket_, (struct sockaddr*)&serverAddress_, sizeof(serverAddress_)) == -1)
    {
        std::cerr << "Failed to connect" << std::endl;
    }
    write(mySocket_, name_.c_str(), name_.size());
    close(mySocket_);
}