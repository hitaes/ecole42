#include "iter.hpp"
#include <iostream>

void ft_double_up(int &arr)
{
    arr = arr * 2;
}

void ft_tolower(char &arr)
{
	arr = std::tolower(static_cast<unsigned char>(arr));
}

void ft_toupper(char &arr)
{
	arr = std::toupper(static_cast<unsigned char>(arr));
}

int main(void)
{
    	int a[] = {1, 2, 3};
        char b[] = {'A', 'B', 'C'};


    {
        std::cout << "-------------------------------------------------------" << std::endl;
	    std::cout << "\033[36mConverting Int: x 2\033[0m" << std::endl;
	    std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Original:" <<
        "\n\ta[0]: " << a[0] <<
        "\n\ta[1]: " << a[1] <<
        "\n\ta[2]: " << a[2] <<
        std::endl << std::endl;
        
        ::iter(a, sizeof(a) / sizeof(int), ft_double_up);

        std::cout << "Converted:" <<
        "\n\ta[0]: " << a[0] <<
        "\n\ta[1]: " << a[1] <<
        "\n\ta[2]: " << a[2] <<
        std::endl << std::endl;
    }

    {
        std::cout << "-------------------------------------------------------" << std::endl;
	    std::cout << "\033[36mConverting Upper\033[0m" << std::endl;
	    std::cout << "-------------------------------------------------------" << std::endl;

        std::cout << "Original:" <<
        "\n\ta[0]: " << b[0] <<
        "\n\ta[1]: " << b[1] <<
        "\n\ta[2]: " << b[2] <<
        std::endl << std::endl;
        
        ::iter(b, sizeof(b) / sizeof(char), ft_toupper);

        std::cout << "Converted:" <<
        "\n\ta[0]: " << b[0] <<
        "\n\ta[1]: " << b[1] <<
        "\n\ta[2]: " << b[2] <<
        std::endl << std::endl;
     
    }

    {
        std::cout << "-------------------------------------------------------" << std::endl;
	    std::cout << "\033[36mConverting Lower\033[0m" << std::endl;
	    std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Original:" <<
        "\n\ta[0]: " << b[0] <<
        "\n\ta[1]: " << b[1] <<
        "\n\ta[2]: " << b[2] <<
        std::endl << std::endl;
        
        ::iter(b, sizeof(b) / sizeof(char), ft_tolower);

        std::cout << "Converted:" <<
        "\n\ta[0]: " << b[0] <<
        "\n\ta[1]: " << b[1] <<
        "\n\ta[2]: " << b[2] <<
        std::endl << std::endl;
    }
}