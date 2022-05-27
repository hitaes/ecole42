#ifndef SPAN_H
# define SPAN_H

#include <string>
#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>
#include <iterator>
#include <climits>

// classes

class Span
{
	private:
		std::vector<int> _storage;
		unsigned int _size;
		unsigned int _pos;

		Span();
	public:
	// Constructors
		Span(unsigned int N);
		Span(const Span &src);

	// Deconstructor
		~Span();

	// Overloaded Operators
		Span &operator=(const Span &src);

	// Public Methods
		void addNumber(int number);
		void addNumber(unsigned int range, time_t seed);
		unsigned int shortestSpan()const;
		unsigned int longestSpan()const;

	// Getter
		unsigned int getSize()const;
		unsigned int getPos()const;
        
	// Exceptions
	class	VectorInvalidException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	ArrayFullException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};

	class	ComparisonInvalidException : public std::exception
	{
		public:
			virtual const char	*what() const throw();
	};
};

#endif
