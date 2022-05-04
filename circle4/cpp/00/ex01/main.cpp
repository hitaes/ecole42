#include "PhoneBook.hpp"

int main(void) {
    PhoneBook pb;
  
    while (true)
    {
        pb.panel_cmd();   
        pb.cmd_input();
        if (pb.cmd_type() == "EXIT")
            return 0;
        else if (pb.cmd_type() == "ADD")
            pb.contact_add();
        else if (pb.cmd_type() == "SEARCH")
            pb.contact_search();
        else
            COUT << "Wrong CMD!\nUse the Available CMD\n";
    }
}