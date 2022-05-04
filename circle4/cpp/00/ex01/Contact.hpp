

#ifndef CONTACT_H
#define CONTACT_H

# include <string>
# include <iostream>

#  define CIN std::cin
#  define COUT std::cout
#  define STRING std::string 

class Contact
{
    private:
        STRING _first_name;
        STRING _last_name;
        STRING _nick_name;
        STRING _phone_number;
        STRING _secret;
        STRING clear_white_space(STRING user_input);

    public:
        void set_first_name(STRING user_input);
        void set_last_name(STRING user_input);
        void set_nick_name(STRING user_input);
        void set_phone_number(STRING user_input);
        void set_secret(STRING user_input);
        STRING get_first_name(void) const;
        STRING get_last_name(void) const;
        STRING get_nick_name(void) const;
        STRING get_phone_number(void) const;
        STRING get_secret(void) const;

        Contact(void);
        ~Contact(void);
};

#endif