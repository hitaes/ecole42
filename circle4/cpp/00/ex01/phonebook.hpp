#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <limits>
# include <iomanip>
# include <iostream>
# include <string>

class Contact
{
    private:
        std::string _first_name;
        std::string _last_name;
        std::string _nick_name;
        std::string _phone_number;
        std::string _secret;

    public:
        std::string clear_white_space(std::string* user_input);
        void set_first_name(std::string* user_input);
        void set_last_name(std::string* user_input);
        void set_nick_name(std::string* user_input);
        void set_phone_number(std::string* user_input);
        void set_secret(std::string* user_input);
        std::string get_first_name(void) const;
        std::string get_last_name(void) const;
        std::string get_nick_name(void) const;
        std::string get_phone_number(void) const;
        std::string get_secret(void) const;

        Contact(void);
        ~Contact(void);
};

class PhoneBook {
 private:
  const std::string _cmd_exit;
  const std::string _cmd_add;
  const std::string _cmd_search;
  std::string _cmd;
  Contact _c[8];
  int _i;
  bool _o;

  void _panel_header(void) const;
  std::string _ellipse(std::string s) const;
  void _detail(void) const;

 public:
    void panel_cmd(void) const;
    void cmd_input(void);
    std::string cmd_type(void) const;
    void contact_add(void);
    void contact_search(void) const;

    PhoneBook(void);
    ~PhoneBook(void);
};

#endif