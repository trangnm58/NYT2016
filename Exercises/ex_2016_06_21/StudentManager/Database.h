#ifndef DATABASE_H
#define DATABASE_H

#include<fstream>
#include<vector>

#include "Class.h"

using namespace std;


class Database
{
	public:
		Database();

		void readFromDatabase(vector<Class> &classList, string fileName);
		void saveToDatabase(vector<Class> &classList, string fileName);
};

#endif

