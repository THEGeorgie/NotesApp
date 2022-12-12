#include <iostream>
#include "SecuritySystem.h"

int main() {
    logregister::SecuritySystem security;

    std::cout  << "------------------------------------------------------\n";
    std::cout  << "|                                                    |\n";
    std::cout  << "|                 Security Dashboard                 |\n";
    std::cout  << "|                                                    |\n";
    std::cout  << "------------------------------------------------------\n";

    std::cout << "Login/register (l/r): " << std::flush;
    char choice;
    std::cin >> choice; 
    std::string name;
    std::string email;
    std::string password;
    std::string tempPass;

    switch (choice) {
        case 'l':
            std::cout << "Enter email: " << std::flush;
            std::cin >> email;
            std::cout << "Enter password: " << std::flush;
            std::cin >> password;
            security.verfiactionUSER(email, password);
            break;
        case 'r':
            std::cout << "Enter name: " << std::flush;
            std::cin >> name;
            std::cout << "Enter Email: " << std::flush;
            std::cin >> email;
            std::cout << "Enter password: " << std::flush;
            std::cin >> password;
            std::cout << "Confirm password: " << std::flush;
            std::cin >> tempPass;
            security.creatingUSER(name, email, password, tempPass);
            break;
        default:
            std::cout << "Invaild Input!!" << std::endl;
            break;
    }

    return 0;
}


