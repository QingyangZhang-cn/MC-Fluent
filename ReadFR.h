#ifndef READ_FISSION_RATE_FROM_XML
#define READ_FISSION_RATE_FROM_XML

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include "string.h"
#include "SortOut.h"
#include <iomanip>

using namespace std;

void ReadFR(vector<vector<string>>& FR);

void GetPowerofCell(vector<vector<double>>& v_Power); 

//void ModifiedCore();

//void ModefiedUDF();

#endif
