//
// Created by Kim Taeseon on 2022/05/03.
//

#include "Replacer.hpp"

int main(int argc, char* argv[])
{
    if (argc != 4)
    {
        std::cout << "[Error] Arguments are not enough.";
        exit(EXIT_FAILURE);
    }
    Replacer replacer(argv[1], argv[2], argv[3]);
    replacer.replaceFile();
    return (0);
}
 