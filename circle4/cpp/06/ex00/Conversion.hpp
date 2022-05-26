#ifndef CONVERSION_H
# define CONVERSION_H

# include <cmath>
# include <cstdlib>
# include <limits>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <string>

class Conversion
{
private:
	bool _error;
	const std::string _input;
	const double _value;
	Conversion();
public:
// Public Methods
	char toChar() const;
	int toInt() const;
	float toFloat()	const;
	double toDouble() const;

// Getter
	bool getError() const;
	const double& getValue() const;
	const std::string& getInput() const;

// Constructor
	explicit Conversion(const std::string& input);

// Canonical Form
	Conversion &operator=(const Conversion& src);
	Conversion(const Conversion &copy);
	~Conversion();
};

std::ostream& operator<<(std::ostream& o, const Conversion& c);

#endif