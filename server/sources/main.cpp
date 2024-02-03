#include "Server.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        std::cerr << "Arguments error" << std::endl;
        return -1;
    }

    Server server{static_cast<uint32_t>(std::stoi(argv[1]))};
    server.run();
    return 0;
}