#include "ModifyMate.h"

using namespace std;

//利用ReadTRou读取Fluent的计算结果
//从geometry.xml读取几何信息，将cell ID修改为 材料id, 
void GetTandRou(vector<vector<string>>& IDTROU)
{
    vector<vector<string>> GEOInfo;
    float ftmp;
    int itmp;
    string stmp;
    stringstream str_stream;

    GetCellInfo(GEOInfo);  //获得几何信息。
    ReadTRou(IDTROU);//读取Fluent结果；

    for(auto it = IDTROU.begin(); it != IDTROU.end(); it++)
    {
    	for(auto jt = GEOInfo.begin(); jt != GEOInfo.end(); jt++)
	{
	    if((*jt).at(0) == (*it).at(0))
	    {
		stmp = (*jt).at(1);
	    	(*it).push_back(stmp);
	    }
	}
	str_stream << (*it).at(1);
	str_stream >> ftmp;
	str_stream.clear();
        itmp = (int)round(ftmp);//温度不需要那么高精度，四舍五入成整数。
        str_stream << itmp;
	str_stream >> stmp;
	str_stream.clear();
	(*it).at(1) = stmp;
    }
}

//输入ID T Rou然后修改对应的materials.xml；
void ModifyMateCore(string IDD, string TT, string RRou)
{
    const char* ID = IDD.c_str();
    const char* T = TT.c_str();
    const char* Rou = RRou.c_str();
	xmlDocPtr pDoc = xmlParseFile("materials.xml");
	xmlNodePtr curNode;
	xmlChar* idvalue;
    xmlNodePtr tempNode;


	if(NULL == pDoc)
	{
		fprintf(stderr, "Document not parsed successfully. \n");
		return;	
	}

	curNode = xmlDocGetRootElement(pDoc);
	if(NULL == curNode)
	{
		fprintf(stderr, "Empty document.\n");
		xmlFreeDoc(pDoc);
		return;
	}



	curNode = curNode->xmlChildrenNode;
	while(NULL != curNode)
	{
		if(!xmlStrcmp(curNode->name, (const xmlChar*)"material") )
		{
            //cout << "45material count" << endl;
			idvalue = xmlGetProp(curNode, (const xmlChar *)"id");
			if(!xmlStrcmp(idvalue, (const xmlChar*) ID) )
			{
                //cout << "49found id" << endl;
		xmlSetProp(curNode, (const xmlChar *)"temperature", (const xmlChar*) T);
                tempNode = curNode -> xmlChildrenNode;
                while(NULL != tempNode)
                {
                    if(!xmlStrcmp(tempNode->name, (const xmlChar*)"temperature"))
                    {
                        //cout << "55 modify T" << endl;
                        xmlNodeSetContent(tempNode, (const xmlChar *) T); 
                    }
                    else if(!xmlStrcmp(tempNode->name, (const xmlChar*)"density"))
                    {
                       // cout << "60 modify Rou" << endl;
                        xmlSetProp(tempNode, (const xmlChar *)"value", (const xmlChar *) Rou);  
                    }

                    tempNode = tempNode -> next;
                }
            }
        }

        curNode = curNode -> next;
    }
    xmlSaveFormatFileEnc("materials.xml", pDoc, "UTF-8", 0);

    xmlFree(idvalue);
	xmlFree(curNode);
	xmlFree(tempNode);
	xmlFreeDoc(pDoc);
    return;
}

//根据IDTROU二维vector来修改一次次materials.xml
void ModifyMaterial()
{
    vector<vector<string>> IDTROU;

    GetTandRou(IDTROU);
    //int N = 0;
    for(auto it = IDTROU.begin(); it != IDTROU.end(); ++it)
    {
	//N++;
        ModifyMateCore((*it).at(3), (*it).at(1), (*it).at(2));
        //cout << N << "    "<< (*it).at(0) << endl;
    }

    return;
}


