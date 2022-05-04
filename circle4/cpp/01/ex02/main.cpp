//
// Created by Kim Taeseon on 2022/05/03.
//

#include <string>
#include <iostream>

int main(void)
{
    std::string brain("HI THIS IS BRAIN");
    std::string* stringPTR(&brain);
    std::string& stringREF(brain);

    std::cout << "=================ADDRESS=================" << std::endl;
    std::cout << "Brain Address : " << &brain << std::endl;
    std::cout << "stringPTR Address : " << &stringPTR << std::endl;
    std::cout << "stringREF Address : " << &stringREF << std::endl;

    std::cout << "==================Value=================" << std::endl;
    std::cout << "Brain Value : " << brain << std::endl;
    std::cout << "stringPTR Value : " << stringPTR << std::endl;
    std::cout << "stringREF Value : " << stringREF << std::endl;

    return (0);
}

