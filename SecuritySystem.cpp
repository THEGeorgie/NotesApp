#include "SecuritySystem.h"
namespace logregister {
    bool SecuritySystem::creatingUSER(std::string name, std::string email, std::string password, std::string tempPass) {
        this->email = email;
        this->password = password;
        this->name = name;

        if (password != tempPass) {
            std::cout << "Password did not match" << std::endl;
            return false;
        }
        else {
            insertdb::DataBase db;
            db.insertDataUser(name, email, password);
            return true;
        }
    }

    bool SecuritySystem::verfiactionUSER(std::string email, std::string password) {
        this->email = email;
        this->password = password;

        std::string line;
        int currentLine = 0;
        insertdb::DataBase db;
        std::cout << db.SEdata << std::endl;
        return false;
        /*if (db.SEdata == email || db.SEdata == password) {
            cout << "Login Secsesfull" << endl;
        }
        else{
            cout << "Login failed!!!" << endl;
            return false;
        }
        */
    }
}
