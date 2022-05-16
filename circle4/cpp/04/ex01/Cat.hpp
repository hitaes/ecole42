#ifndef CAT_H
# define CAT_H

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *_brain;
public:
// Constructors
    Cat();
    Cat(const Cat &Cat);
// Deconstructor
    ~Cat();
// Overloaded Operators
    Cat &operator=(const Cat &src);
// Public Methods
    void makeSound()const;
// Getter
    void getIdeas(void)const;
// Setter
    void setIdea(size_t i, std::string idea);
};

#endif
