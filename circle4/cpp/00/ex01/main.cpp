/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kimtaeseon <kimtaeseon@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:40:28 by kimtaeseon        #+#    #+#             */
/*   Updated: 2022/05/02 15:05:32 by kimtaeseon       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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
            std::cout << "Wrong CMD!\nUse the Available CMD\n";
    }
}