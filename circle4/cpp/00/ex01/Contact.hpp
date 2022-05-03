

#ifndef CONTACT_H
#define CONTACT_H

# include <string>
# include <iostream>

class Contact
{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nick_name;
        std::string _phone_number;
        std::string _secret;
        std::string clear_white_space(std::string user_input);

    public:
        void set_first_name(std::string user_input);
        void set_last_name(std::string user_input);
        void set_nick_name(std::string user_input);
        void set_phone_number(std::string user_input);
        void set_secret(std::string user_input);
        std::string get_first_name(void) const;
        std::string get_last_name(void) const;
        std::string get_nick_name(void) const;
        std::string get_phone_number(void) const;
        std::string get_secret(void) const;

        Contact(void);
        ~Contact(void);
};

#endif