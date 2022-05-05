//
// Created by Kim Taeseon on 2022/05/03.
//

#include "Harl.hpp"

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Arguments are not proper." << std::endl;
        std::cout << "Available Inputs : DEBUG, INFO, WARNING, ERROR" << std::endl;
        exit(EXIT_FAILURE);
    }
    Harl h;
    h.complain(argv[1]);
    return 0;
}
 