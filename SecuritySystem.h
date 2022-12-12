#include "DataBase.h"
#ifndef _SECURTYSYSTEM_H_
#define _SECURTYSYSTEM_H_
namespace logregister {
	class SecuritySystem {
	private:
		std::string email;
		std::string password;
		std::string name;
	public:
		bool verfiactionUSER(std::string email, std::string password);
		bool creatingUSER(std::string name, std::string email, std::string password, std::string tempPass);
	};
}
#endif // !_SECURTYSYSTEM_H_


