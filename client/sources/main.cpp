#include "Client.hpp"

#include <iostream>

int main(int argc, char** argv)
{
    if (argc != 4)
    {
        std::cerr << "Arguments error" << std::endl;
        return -1;
    }

    std::cout << std::string{argv[1]} << std::endl;
    Client client{std::string{argv[1]}, std::stoi(argv[2])};
    client.run(std::stoi(argv[3]));
    return 0;
}