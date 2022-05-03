#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <limits>
# include <iomanip>
# include <iostream>
# include <string>
# include "Contact.hpp"

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