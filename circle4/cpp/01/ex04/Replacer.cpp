#include "Replacer.hpp"

void Replacer:: Replacer::replaceFile(void) {
    std::string parsedString(_parseFile());
    if (!_replaceable(parsedString))
    {
        std::cout << "[Error] There is nothing to change.";
        exit(EXIT_FAILURE);
    }
    std::size_t position(parsedString.find(_oldString));
    while (position != std::string::npos) {
        parsedString.erase(position, _oldString.size());
        parsedString.insert(position, _newString);
        position = parsedString.find(_oldString, position + _newString.size());
    }
    const std::string outFilename(_filename + ".replace");
    std::ofstream outFileStream(outFilename.c_str());
    outFileStream << parsedString;
    std::cout << "[Success] Replacement is complete.";
}

const std::string Replacer::_parseFile(void) {
    std::ifstream inputFileStream(_filename);
    if (!inputFileStream)
    {
        std::cout << "[Error] There is no file.";
        exit(EXIT_FAILURE);
    }
    std::string tempText;
    while (!inputFileStream.eof())
    {
        std::string tmpLine;
        getline(inputFileStream, tmpLine);
        tempText.append(tmpLine + "\n");
    }
    return tempText;
}

bool Replacer::_replaceable(const std::string& parsedString){
    if (_newString.compare(_oldString) == 0){
        return false;
    }
    else if (parsedString.find(_oldString) == std::string::npos) {
        return false;
    } else {
        return true;
    }
}

Replacer::Replacer(const std::string& filename,
             const std::string& oldString,
             const std::string& newString) 
: _filename(filename), _oldString(oldString), _newString(newString)
{}

Replacer::~Replacer()
{}