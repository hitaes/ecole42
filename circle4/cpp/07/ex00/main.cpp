#include "whatever.hpp"

int main(void)
{
    int left = 1;
    int right = 2;

    std::cout << "------------before data----------" << std::endl;
    std::cout << "left: " << left << std::endl;
    std::cout << "right: " << right << std::endl;
    
    std::cout << "----------max() is Called--------" << std::endl;
    std::cout << max(left, right) << std::endl;

    std::cout << "------------after data----------" << std::endl;
    std::cout << "left: " << left << std::endl;
    std::cout << "right: " << right << std::endl;

    std::cout << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << std::endl;

    std::cout << "------------before data----------" << std::endl;
    std::cout << "left: " << left << std::endl;
    std::cout << "right: " << right << std::endl;
    
    std::cout << "----------swap() is Called--------" << std::endl;
    swap(left, right);

    std::cout << "------------after data----------" << std::endl;
    std::cout << "left: " << left << std::endl;
    std::cout << "right: " << right << std::endl;

    std::cout << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << std::endl;

    std::cout << "------------before data----------" << std::endl;
    std::cout << "left: " << left << std::endl;
    std::cout << "right: " << right << std::endl;
    
    std::cout << "----------min() is Called--------" << std::endl;
    std::cout << min(left, right) << std::endl;

    std::cout << "------------after data----------" << std::endl;
    std::cout << "left: " << left << std::endl;
    std::cout << "right: " << right << std::endl;

    
    return 0;
}