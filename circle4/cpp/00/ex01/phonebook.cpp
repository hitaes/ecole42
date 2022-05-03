#include "PhoneBook.hpp"

void PhoneBook::_panel_header(void) const {
    std::cout << "- Phone Book -" << std::endl;
}

void PhoneBook::panel_cmd(void) const {
  std::cout << std::endl
    << "Type the command to process [ "
    << "EXIT (exit)" << " | "
    << "ADD (add)" << " | "
    << "SEARCH (search)" << " ]\n";
}

void PhoneBook::cmd_input(void) {
  std::size_t size;
  const std::string whitespace = " \t\n\v\r\f";

  if (!(std::getline(std::cin >> std::ws, _cmd)) || std::cin.eof())
    exit(1);
  _cmd.erase(_cmd.find_last_not_of(whitespace) + 1);
  size = _cmd.size();
  for (std::size_t i = 0 ; i < size ; ++i)
    _cmd[i] = std::toupper(_cmd[i]);
  std::cout << std::endl;
}

std::string PhoneBook::_ellipse(std::string s) const {
    if (s.size() > 10) {
        s[10 - 1] = '.';
        s.erase(10);
    }
    return s;
}
void PhoneBook::_detail(void) const{
    int opt;
    int tmp_index = _o ? 8 : _i;

    while (true) {
        std::cout << std::endl << "Select the index to search (1 to end)\t>>\t";
        std::cin >> opt;
        if (std::cin.fail() || opt > tmp_index|| opt <= 0) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Wrong Input" << std::endl << std::endl;
            continue;
        }
        break;
    }
    std::cout << std::endl
      << "1. First Name : "
      << _c[opt - 1].get_first_name() << std::endl
      << "2. Last Name : "
      
      <<_c[opt - 1].get_last_name() << std::endl
      << "3. Nickname : "
      << _c[opt - 1].get_nick_name() << std::endl
      << "4. Phone Number : "
      << _c[opt - 1].get_phone_number() << std::endl
      << "5. Darkest Secret : "
      << _c[opt - 1].get_secret() << std::endl << std::endl;
}


std::string PhoneBook::cmd_type(void) const {
    if(_cmd == _cmd_exit)
        return "EXIT";
    else if (_cmd == _cmd_add)
        return "ADD";
    else if (_cmd == _cmd_search)
        return "SEARCH";
    return "NO_MATCH";
}

void PhoneBook::contact_add(void) {
    std::string temp;

    _c[_i].set_first_name(&temp);
    _c[_i].set_last_name(&temp);
    _c[_i].set_nick_name(&temp);
    _c[_i].set_phone_number(&temp);
    _c[_i].set_secret(&temp);
    if (!_o && _i == 7)
        _o = true;
    _i = (_i + 1) % 8;
}

void PhoneBook::contact_search(void) const{
    int size = _o ? 8 : _i;

    if (!size) {
        std::cout << "Empty Phone Book" << std::endl;
        return;
    }
    std::cout << "=============================================\n" << "|"
      << std::setfill(' ') << std::setw(10)
      << "index" << "|"
      << std::setfill(' ') << std::setw(10)
      << "first name" << "|"
      << std::setfill(' ') << std::setw(10)
      << "last name" << "|"
      << std::setfill(' ') << std::setw(10)
      << "nickname" << "|" << std::endl
      << "=============================================" << std::endl;
    for (int i = 0 ; i < size ; ++i) {
        std::cout << "|"
          << std::setfill(' ') << std::setw(10) << i + 1
          << "|"
          << std::setfill(' ') << std::setw(10)
          << _ellipse(_c[i].get_first_name()) << "|"
          << std::setfill(' ') << std::setw(10)
          << _ellipse(_c[i].get_last_name()) << "|"
          << std::setfill(' ') << std::setw(10)
          << _ellipse(_c[i].get_nick_name()) << "|" << std::endl
          << std::endl;
    }
    _detail();
}

PhoneBook::PhoneBook(void)
  : _cmd_exit("EXIT"), _cmd_add("ADD"), _cmd_search("SEARCH")
    ,_i(0), _o(false){
  std::cout << "Opening Phone Book..." << std::endl;
  std::cout << "Phone Book has been opened" << std::endl;
  _panel_header();
}

PhoneBook::~PhoneBook(void) {
  std::cout << "Closing Phone Book..." << std::endl;
  std::cout << "Phone Book has been closed" << std::endl;
}