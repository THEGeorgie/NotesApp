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
		const char* s = "DB\\DATABASE.db";
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

	int selectData(std::string selecetion, std::string wh) {
		sqlite3* db;
		DataBase call;
		int rc;
		char* messaggeError;
		const char* s = "DB\\DATABASE.db";
		int exit = sqlite3_open(s, &db);

		std::string sl = "\'" + selecetion + "\'";
		std::string whe = "\'" + wh + "\'";

		std::string sql = "SELECT " + sl + " FROM User; WHERE " + whe + ";";

		rc = sqlite3_exec(db, sql.c_str(), callback, NULL, NULL);
		if (rc != SQLITE_OK) {
			std::cout << "Error!!! Failed to select\n";

			sqlite3_free(messaggeError);
			sqlite3_close(db);
		}
		else {
			fprintf(stdout, "Operation done successfully\n");
			sqlite3_close(db);
		}


		call.SEdata = sql;

		sqlite3_close(db);
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