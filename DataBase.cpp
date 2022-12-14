#include "DataBase.h"
namespace insertdb {
	void DataBase::insertDataUser(std::string name, std::string email, std::string password) {
		this->name = name;
		this->email = email;
		this->password = password;
		char* messaggeError;
		sqlite3* db;
		const char* s = "DB/DATABASE.db";
		int exit = sqlite3_open(s, &db);

		std::string sql("INSERT INTO Users (name, email, password) VALUES (" + quote + name + quote + ", " + quote + email + quote + ", " + quote + password + quote + ");");

		exit = sqlite3_exec(db, sql.c_str(), NULL, 0, &messaggeError);
		if (exit != SQLITE_OK) {
			std::cerr << "Error Insert" << std::endl;
			sqlite3_free(messaggeError);
		}
		else
			std::cout << "Account created Successfully!" << std::endl;

	}

	void DataBase::insertDataNotes(std::string data, std::string idUser, std::string idNote) {
		char* messaggeError;
		sqlite3* db;
		const char* s = "DB/DATABASE.db";
		int exit = sqlite3_open(s, &db);
		std::string sql("INSER INTO Notes ( data, user_id) VALUES (" + idUser + "," + data + ")");

		exit = sqlite3_exec(db, sql.c_str(), NULL, NULL, &messaggeError);
		if (exit != SQLITE_OK) {
			std::cout << "Incorect Input" << std::endl;
			sqlite3_free(messaggeError);
		}
		else {
			std::cout << "Account Created!!!" << std::endl;
		}
	}

	int DataBase::selectData(std::string email) {
		sqlite3* db;
		DataBase call;
		char* messaggeError;
		const char* s = "DB\\DATABASE.db";

		int exit = sqlite3_open(s, &db);

		std::string sql = "SELECT password FROM User WHERE " + quote + email + quote + ";";

		exit = sqlite3_exec(db, sql.c_str(), callback, NULL, &messaggeError);
		if (exit != SQLITE_OK) {
		
			sqlite3_free(messaggeError);
			sqlite3_close(db);
		}
		else {
			std::cout << "Error!!\n";
			sqlite3_close(db);
		}
		return 0;

	}

	int callback(void* NotUsed, int argc, char** argv, char** azColName) {

		for (int i = 0; i < argc; i++) {
			std::cout << azColName[i] << ": " << argv[i] << std::endl;
		}

		std::cout << std::endl;

		return 0;

	}
}