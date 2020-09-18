#include "ReadGEO.h"

using namespace std;

void GetCellInfo(vector<vector<string>>& Geo)
{
	xmlDocPtr pDoc = xmlParseFile("geometry.xml");
	xmlNodePtr curNode;
	xmlChar* value;
	xmlChar* idvalue;
	xmlChar* matevalue;
	xmlChar* regivalue;
	//int NC = 0;
	vector<string> vtmp;

	stringstream str_stream;
	string str;
	string temp;

	//写主程序记得专门检测下文件状态。

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
		if(!xmlStrcmp(curNode->name, (const xmlChar*)"cell") )
		{

			value = xmlGetProp(curNode, (const xmlChar *)"name");
			if(xmlStrcmp(value, (const xmlChar*) "root cell") )
			{
			vtmp.clear();
			idvalue = xmlGetProp(curNode, (const xmlChar *)"id");
			str = reinterpret_cast<char*>(idvalue);
			str_stream << str;
			str_stream >> temp;
			str_stream.clear();
			//cout << "50str : " << str << "   temp : " << temp << endl;
			vtmp.push_back(temp);

			matevalue = xmlGetProp(curNode, (const xmlChar *)"material");
			str = reinterpret_cast<char*>(matevalue);
			str_stream << str;
			str_stream >> temp;
			str_stream.clear();
			//cout << "57str : " << str << "   temp : " << temp << endl;
			vtmp.push_back(temp);
			
			/*we donot need region information right now.*/
			/*
			regivalue = xmlGetProp(curNode, (const xmlChar *)"region");

			str = reinterpret_cast<char*>(regivalue);
			str_stream << str;

			//cout << "65str : " << str << endl;
			while((str_stream >> temp))
			{
				//cout << "68temp : " << temp << endl;
				vtmp.push_back(temp);
			}
			str_stream.clear();
			*/

			//cout << "vtmp : ";
			/*for (auto itc = vtmp.begin(); itc != vtmp.end(); ++itc)
			{
				cout << *itc << " ,";
			}
			cout << endl;*/
			Geo.push_back(vtmp);
			}


		}

		curNode = curNode->next;
	}

	xmlFree(value);
	xmlFree(idvalue);
	xmlFree(matevalue);
	xmlFree(regivalue);
	xmlFree(curNode);
	xmlFreeDoc(pDoc);
}

void GetSurfaceInfo(vector<vector<string>>& Suf)
{
	xmlDocPtr pDoc = xmlParseFile("geometry.xml");
	xmlNodePtr curNode;
	xmlChar* idvalue;
	xmlChar* typevalue;
	xmlChar* coeffvalue;

	vector<string> vtmp;

	stringstream str_stream;
	string str;
	string temp;

	//写主程序记得专门检测下文件状态。

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
		if(!xmlStrcmp(curNode->name, (const xmlChar*)"surface") )
		{

			
			vtmp.clear();
			//================获取ID===========================
			idvalue = xmlGetProp(curNode, (const xmlChar *)"id");
			str = reinterpret_cast<char*>(idvalue);
			str_stream << str;
			str_stream >> temp;
			//cout << "50str : " << str << "   temp : " << temp << endl;
			vtmp.push_back(temp);
			str_stream.clear();

			//================获取type===============================
			typevalue = xmlGetProp(curNode, (const xmlChar *)"type");

			str = reinterpret_cast<char*>(typevalue);
			str_stream << str;
			str_stream >> temp;
			//cout << "50str : " << str << "   temp : " << temp << endl;
			vtmp.push_back(temp);
			str_stream.clear();


			//====================获取coeffs==========================
			coeffvalue = xmlGetProp(curNode, (const xmlChar *)"coeffs");

			str = reinterpret_cast<char*>(coeffvalue);
			str_stream << str;

			//cout << "65str : " << str << endl;
			while((str_stream >> temp))
			{
				//cout << "68temp : " << temp << endl;
				vtmp.push_back(temp);
			}
			str_stream.clear();
			//cout << "vtmp : " << endl;
			
			Suf.push_back(vtmp);

		}
		

		curNode = curNode->next;
	}
	xmlFree(idvalue);
	xmlFree(typevalue);
	xmlFree(coeffvalue);
	xmlFreeDoc(pDoc);
}

/*
int main()
{
	vector<vector<string>> Cell;
	vector<vector<string>> Surf;


	cout << "Begain to read geometry..." << endl;
		GetCellInfo(Cell);
	cout << "The information of Cells are shown as below." << endl;
	for(auto it = Cell.begin(); it != Cell.end(); ++it)
	{
		for (auto itc = (*it).begin(); itc != (*it).end(); ++itc)
		{
			cout << *itc << ", ";
		}
		cout << endl;
	}
	cout << "End of cells." << endl << endl;

	GetSurfaceInfo(Surf);
	cout << "The information of Surfaces are shown as below." << endl;
	for(auto it = Surf.begin(); it != Surf.end(); ++it)
	{
		for (auto itc = (*it).begin(); itc != (*it).end(); ++itc)
		{
			cout << *itc << "; ";
		}
		cout << endl;
	}
	cout << "End of Surfaces." << endl;

	return 0;
}
*/
