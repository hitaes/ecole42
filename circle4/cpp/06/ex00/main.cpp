#include "Conversion.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
		std::cout << "Command Not Formatted Well" << std::endl
					<< "./convert [ Convert Input ]" << std::endl;
	else
		std::cout << Conversion(argv[1]);
	return (0);
}
