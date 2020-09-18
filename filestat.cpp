#include "filestat.h"

using namespace std;

inline bool exists_file(const string& name) {
	struct stat buffer;
	return (stat (name.c_str(), &buffer) == 0);
}



bool Check(const string& name)
{
	if(exists_file(name))
	{
		cout << "exist" << endl;
		return true;
	}
	else
	{
		cout << "Can not find " << name << endl;
		return false;
	}
	return false;
}
