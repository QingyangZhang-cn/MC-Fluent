#ifndef REWRITE_POWER_UDF_OF_FLUENT
#define REWRITE_POWER_UDF_OF_FLUENT

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <regex>
#include "ReadFR.h"

using namespace std;

void rewrite_core(string Filename, vector<vector<double>>& vPower, int NR, int NZ);
void rewrite_UDFH();

#endif
