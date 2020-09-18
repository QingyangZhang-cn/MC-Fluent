#ifndef CHECK_FILE_STATS_FUNCTION
#define CHECK_FILE_STATS_FUNCTION

#include <iostream>
#include <sys/stat.h>
#include <unistd.h>
#include <string>
#include <fstream>


inline bool exists_file(const string& name);


bool Check(const string& name);

#endif
