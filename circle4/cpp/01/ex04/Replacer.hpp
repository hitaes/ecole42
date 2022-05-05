#ifndef REPLACER_H
# define REPLACER_H

# include <fstream>
# include <iostream>
# include <string>
# include <stdlib.h>

class Replacer
{
    private:
        const std::string _filename;
        const std::string _oldString;
        const std::string _newString;
        const std::string _parseFile();
        bool _replaceable(const std::string& parsedString);
        
    public:
        void replaceFile(void);
        Replacer(const std::string& filename,
                 const std::string& oldString,
                 const std::string& newString);
        ~Replacer();
};

#endif