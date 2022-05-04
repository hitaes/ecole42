#ifndef WEAPONE_H
# define WEAPONE_H

# include <string>
# include <iostream>

class Weapon {
    private:
    std::string _type;

    public:
    const std::string& getType(void);
    void setType(const std::string& type);
    Weapon(const std::string& typeInput);
    ~Weapon(void);
};

#endif