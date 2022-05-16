#ifndef DOG_H
# define DOG_H

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *_brain;
public:
// Constructors
    Dog();
    Dog(const Dog &Dog);
// Deconstructor
    ~Dog();
// Overloaded Operators
    Dog &operator=(const Dog &src);
// Public Methods
    void makeSound()const;
// Getter
    void getIdeas(void)const;
// Setter
    void setIdea(size_t i, std::string idea);
};

#endif
