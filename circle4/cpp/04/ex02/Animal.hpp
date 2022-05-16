#ifndef ANIMAL_H
# define ANIMAL_H

#include <string>
#include <iostream>
#include <cstdio>
#include <cstdlib>

class Animal
{
	protected:
		std::string _type;
		Animal();

	public:
	// Constructors
		Animal(const Animal &copy);

	// Deconstructors
		virtual ~Animal();

	// Overloaded Operators
		Animal &operator=(const Animal &src);

	// Public Methods
		virtual void makeSound(void)const = 0;
	// Getter
		std::string getType(void)const;
	// Setter

};

#endif
