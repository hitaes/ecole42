#include "Contact.hpp"

STRING Contact::clear_white_space(STRING user_input){
    const STRING whitespace = " \t\n\v\r\f";
    if (!(std::getline(CIN >> std::ws, user_input)))
        exit(1);
    user_input.erase(user_input.find_last_not_of(whitespace) + 1);
    return user_input;
}

void Contact::set_first_name(STRING user_input){
    COUT << "1. First Name: ";
    _first_name = clear_white_space(user_input);
    
}
void Contact::set_last_name(STRING user_input){
    COUT << "2. Last Name: ";
    _last_name = clear_white_space(user_input);
    
}
void Contact::set_nick_name(STRING user_input){
    COUT << "3. Nick Name: ";
    _nick_name = clear_white_space(user_input);;
}
void Contact::set_phone_number(STRING user_input){
    COUT << "4. Phone Number: ";
    _phone_number = clear_white_space(user_input);
}
void Contact::set_secret(STRING user_input){
    COUT << "5. Secret: ";
    _secret = clear_white_space(user_input);;
}

STRING Contact::get_first_name(void) const {
    return _first_name;
}
STRING Contact::get_last_name(void) const {
    return _last_name;
}
STRING Contact::get_nick_name(void) const {
    return _nick_name;
}
STRING Contact::get_phone_number(void) const {
    return _phone_number;
}
STRING Contact::get_secret(void) const {
    return _secret;
}

Contact::Contact(void) {
}

Contact::~Contact(void) {
}