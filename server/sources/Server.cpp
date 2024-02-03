#include "Server.hpp"

#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/socket.h>
#include <sys/types.h> 
#include <string>
#include <cstring>
#include <future>

#include <iostream> //////////////////////////////////

Server::Server(const uint32_t port)
: serverAddress{0}, logger{new LoggerDateTimeFormatter{std::move(std::unique_ptr<Logger>(new FileLogger{"log.txt"}))}}
{
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in servAddr;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(port);
    servAddr.sin_addr.s_addr = INADDR_ANY;

    bind(serverSocket, (struct sockaddr*)&servAddr, sizeof(servAddr));
    listen(serverSocket, 1);
}

void Server::run()
{
    while(1)
    {
        int clientSocket = accept(serverSocket, NULL, NULL);
        if (clientSocket < 0) continue;

        char buffer[64];
        memset(buffer, '\0', sizeof(buffer));

        read(clientSocket, buffer, sizeof(buffer));
        logger->log(buffer);
        close(clientSocket);
    } 
}