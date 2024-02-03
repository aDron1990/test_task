#include "Server.hpp"

#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/socket.h>
#include <sys/types.h> 
#include <string>
#include <cstring>
#include <future>
#include <thread>
#include <list>
#include <algorithm>

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
    std::list<std::future<void>> flist;
    std::thread clientDeleter{[&flist]()
    {
        while(1)
        flist.remove_if([](std::future<void>& f)
        {
            return (bool)(f.wait_for(std::chrono::seconds(0)) == std::future_status::ready);
        });
    }};

    while(1)
    {
        int clientSocket = accept(serverSocket, NULL, NULL);
        if (clientSocket < 0)
        {
            std::cout << "Error to connct to client\n";
            continue;
        }
        else
        {
            std::cout << "connected to client\n"; 
        }

        std::future<void> f;

        flist.emplace_front(std::move(std::async(std::launch::async, 
        [&, clientSocket]()
        {
            while (1)
            {
                char buffer[64];
                memset(buffer, '\0', sizeof(buffer));
                if (read(clientSocket, buffer, sizeof(buffer)) <= 0)
                {
                    std::cout << "Client close socket" << std::endl;
                    break;
                }
                logger->log(buffer);
            }
            close(clientSocket);
        })));
    } 
    clientDeleter.join();
}