#ifndef HARL_H
# define HARL_H

# include <string>
# include <iostream>

class Harl
{
    private:
        void _debug(void);
        void _info(void);
        void _warning(void);
        void _error(void);

    public:
        void complain(std::string level);
        Harl();
        ~Harl();
};

#endif
