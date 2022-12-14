#include <iostream>
#include <string>
#include "sqlite3.h"

#ifndef _DATABASE_H_
#define _DATABASE_H_
namespace insertdb {
	class DataBase
	{
	private:
		std::string name;
		std::string email;
		std::string password;
		std::string INdata;
		std::string idUser;
		std::string idNote;
		const std::string quote = "\'";
		
		
	public:
		 void insertDataUser(std::string name, std::string email, std::string password);
		 void insertDataNotes(std::string INdata, std::string idUser, std::string idNote);
		 int selectData(std::string email);
	};
		struct data {
		std::string data;
	};
	
	int callback(void* NotUSed, int argc, char** argv, char** azColName);
}
#endif // !_DATABASE_H_




