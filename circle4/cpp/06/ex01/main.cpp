#include "Serializer.hpp"

int main()
{
	Data *a = new Data();

	a->age = 1;
	a->name = "ts";
	a->next = NULL;

	Data *b = new Data();
	b->age = 2;
	b->name = "tss";
	b->next = a;

	std::cout << "Here is the original structs:" <<
				"\n\taddress: " << &b <<
				"\n\tname: " << b->name <<
				"\n\tage: " << b->age <<
				"\n\taddress next: " << b->next <<
	std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\taddress a: " << &a <<
				"\n\tname: " << a->name <<
				"\n\tage: " << a->age <<
				"\n\taddress next: " << a->next <<
	std::endl << std::endl;

	std::cout << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << std::endl;

	Serializer c;

	Data *reserialized_data = c.unserialize(c.serialize(a));

	std::cout << "Here is the reserialized structs:" <<
				"\n\taddress: " << reserialized_data <<
				"\n\tname: " << reserialized_data->name <<
				"\n\tage: " << reserialized_data->age <<
				"\n\taddress next: " << reserialized_data->next <<
	std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "\taddress ptr2: " << &a <<
				"\n\tname: " << a->name <<
				"\n\tage: " << a->age <<
				"\n\taddress next: " << a->next <<
	std::endl << std::endl;

	delete a;
	delete b;

	return (0);
}
