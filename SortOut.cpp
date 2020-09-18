#include "SortOut.h"
using namespace std;

int Input_File::Init()
{
	string filename = "MCF_Input";
	ifstream fin;
	string tmp_str;
	int tmp_int = 0;

	fin.open(filename);
	if(!fin)
	{
		cerr << "Cannot find MCF_Input file." << endl;
		return -1;
	}
	
	getline(fin, tmp_str);
	fin >> m_Power;
	getline(fin, tmp_str);
	getline(fin, tmp_str);
	fin >> m_NR;
	getline(fin, tmp_str);
	getline(fin, tmp_str);
	m_Rodid.clear();
	for(int i = 0; i < m_NR; ++i)
	{
		fin >> tmp_int;
		m_Rodid.push_back(tmp_int);
	}
	getline(fin, tmp_str);
	getline(fin, tmp_str);
	fin >> m_NF;
	getline(fin, tmp_str);
	getline(fin, tmp_str);
	fin >>m_Interval;
	getline(fin, tmp_str);
	getline(fin, tmp_str);
	fin >> m_Hname;
        getline(fin, tmp_str);
        getline(fin, tmp_str);
        fin >> m_Ni;
        getline(fin, tmp_str);
        getline(fin, tmp_str);
        fin >> m_error;
        getline(fin, tmp_str);
        getline(fin, tmp_str);
        fin >> m_thread;
        getline(fin, tmp_str);
        getline(fin, tmp_str);
        fin >> m_Jname;
	return 0;
}
