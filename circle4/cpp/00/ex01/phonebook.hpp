#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <limits>
# include <iomanip>
# include <iostream>
# include <string>
# include "Contact.hpp" 

#  define CIN std::cin
#  define COUT std::cout
#  define STRING std::string 

class PhoneBook {
 private:
  const STRING _cmd_exit;
  const STRING _cmd_add;
  const STRING _cmd_search;
  STRING _cmd;
  Contact _c[8];
  int _i;
  bool _o;

  void _panel_header(void) const;
  STRING _ellipse(STRING s) const;
  void _detail(void) const;

 public:
    void panel_cmd(void) const;
    void cmd_input(void);
    STRING cmd_type(void) const;
    void contact_add(void);
    void contact_search(void) const;

    PhoneBook(void);
    ~PhoneBook(void);
};

#endif