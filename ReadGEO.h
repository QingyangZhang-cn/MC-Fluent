#ifndef READ_CELL_AND_SURFACE_INFO_FROM_XML
#define READ_CELL_AND_SURFACE_INFO_FROM_XML

#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <libxml/parser.h>
#include <libxml/tree.h>

using namespace std;

void GetCellInfo(vector<vector<string>>& Geo);

void GetSurfaceInfo(vector<vector<string>>& Suf);

#endif