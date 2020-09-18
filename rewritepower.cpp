#include <iostream>

#include "rewritepower.h"

using namespace std;

void rewrite_core(string Filename, vector<vector<double>>& vPower, int NR, int NZ)
{
	ifstream Readfile;
	ofstream Writefile;
	string line;

	int flag;
	int num = 0;

	Readfile.open(Filename, ios::in);
	Writefile.open("_temp_MCF_", ios::trunc);
	while(getline(Readfile, line))
	{
		if(regex_match (line, regex(".*real Power_.*\\[.*\\].*;")) & (num < NR))
		{

				Writefile << "real Power_"<< vPower[num][0]<< "[" << NZ <<"] = {";
                for(int i = 1; i < NZ; ++i)
                {
                    Writefile << vPower[num][i] << ", ";
                }
				Writefile << vPower[num][NZ] << "};" << endl;
				
				num ++;
		}else{
			Writefile << line << endl;
		}

	}

	Readfile.close();
	Writefile.close();

    Readfile.open("_temp_MCF_", ios::in);
    Writefile.open(Filename, ios::trunc);
	while(getline(Readfile, line))
	{
		Writefile << line << endl;
	}
	Readfile.close();
	Writefile.close();

	flag = remove("_temp_MCF_");

	return;
}

void rewrite_UDFH()
{
	string Filename;
	Input_File Input;
	vector<vector<double>> vPower;
	int NR,NZ;

	Input.Init();
	Filename = Input.m_Hname;
	NR = Input.m_NR;
	NZ = Input.m_NF;

	GetPowerofCell(vPower);

	rewrite_core(Filename, vPower, NR,NZ);

}
