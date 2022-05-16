#ifndef BRAIN_H
# define BRAIN_H

# include <iostream>
# include <string>

class Brain
{
private:
    std::string _ideas[100];
public:
    // Constructors
    Brain();
    Brain(const Brain &copy);

    // Deconstructor
    ~Brain();

    // Overloaded Operators
    Brain &operator =(const Brain &src);

    // Getter
		const std::string getIdea(size_t i)const;
		const std::string *getIdeaAddress(size_t i)const;
	// Setter
		void setIdea(size_t i, std::string idea);
};

#endif

