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

        //insertdb::data pass;
        insertdb::DataBase db;
        db.selectData(email);
        
        //std::cout << "password: " + password;

        // if (pass.data == "password: " + password) {
        //     std::cout << "Logged in!!!!!\n";
        // }else{
        //     std::cout << "Incorect login information!!!\n";
        // }
        

        return false;
    }
}
