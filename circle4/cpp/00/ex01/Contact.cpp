#include "Contact.hpp"

std::string Contact::clear_white_space(std::string user_input){
    const std::string whitespace = " \t\n\v\r\f";
    if (!(std::getline(std::cin >> std::ws, user_input)) || std::cin.eof())
        exit(1);
    user_input.erase(user_input.find_last_not_of(whitespace) + 1);
    return user_input;
}

void Contact::set_first_name(std::string user_input){
    std::cout << "1. First Name: ";
    _first_name = clear_white_space(user_input);
    
}
void Contact::set_last_name(std::string user_input){
    std::cout << "2. Last Name: ";
    _last_name = clear_white_space(user_input);
    
}
void Contact::set_nick_name(std::string user_input){
    std::cout << "3. Nick Name: ";
    _nick_name = clear_white_space(user_input);;
}
void Contact::set_phone_number(std::string user_input){
    std::cout << "4. Phone Number: ";
    _phone_number = clear_white_space(user_input);
}
void Contact::set_secret(std::string user_input){
    std::cout << "5. Secret: ";
    _secret = clear_white_space(user_input);;
}

std::string Contact::get_first_name(void) const {
    return _first_name;
}
std::string Contact::get_last_name(void) const {
    return _last_name;
}
std::string Contact::get_nick_name(void) const {
    return _nick_name;
}
std::string Contact::get_phone_number(void) const {
    return _phone_number;
}
std::string Contact::get_secret(void) const {
    return _secret;
}

Contact::Contact(void) {
}

Contact::~Contact(void) {
}