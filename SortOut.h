#ifndef SORT_OUT_INFO_AND_FR
#define SORT_OUT_INFO_AND_FR

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "string.h"
#include <iomanip>
using namespace std;

class Input_File
{
    public:
        int Init();
        double m_Power;
        int m_NR;
        vector<int> m_Rodid;
        int m_NF;
        int m_Interval;
        string m_Hname;
	int m_Ni;
	double m_error;
	string m_thread;
        string m_Jname
};





#endif
