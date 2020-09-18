#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <cmath>
#include "ReadGEO.h"
#include "ReadTRou.h"

using namespace std;

//从geometry.xml读取几何信息，并提取cell ID, 材料编号, 
//然后从Fluent的输出文件中获得每种材料的T & Rou.
void GetTandRou(vector<vector<string>>& IDTROU);

//输入ID T Rou然后修改对应的materials.xml；
void ModifyMateCore(string IDD, string TT, string RRou);

//根据IDTROU二维vector来修改一次次materials.xml
void ModifyMaterial();
