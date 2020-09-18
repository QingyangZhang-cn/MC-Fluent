#include "ReadFR.h"

using namespace std;

void ReadFR(vector<vector<double>>& FR)
{
    vector<double> vtemp;
    string temp, temp2;
    stringstream str_stream;
    double cellid, fisrate;
    ifstream input("tallies.out");

    if(!input)
    {
        fprintf(stderr, "Open tallies.out Error. \n");
        return;
    }

    while(input >> temp)
    {
        if (temp == "Cell")
        {
            input.seekg( 1, ios::cur );
            input >> temp2;
	    str_stream << temp2;
	    str_stream >> cellid;
	    str_stream.clear();
	    vtemp.push_back(cellid);
        }
        else if (temp == "Fission")
        {
            input.seekg( 29, ios::cur );
            input >> temp2;
	    str_stream << temp2;
	    str_stream >> fisrate;
	    str_stream.clear();
	    vtemp.push_back(fisrate);
            FR.push_back(vtemp);
            vtemp.clear();
        }
    }
    return;
}
void GetPowerofCell(vector<vector<double>>& v_Power)
{
	double Power, temp, temp_P;
	double total = 0.0;
	int NR, NF, Interval, Ntemp, flag;
	vector<int> Rod;
	vector<double> tempv;
	vector<vector<double>> FR;
	stringstream str_stream;
	Input_File Input;
	flag = Input.Init();
	Power = Input.m_Power;
	NR = Input.m_NR;
	Rod = Input.m_Rodid;
	NF = Input.m_NF;
	Interval = Input.m_Interval;

	ReadFR(FR);

	for(int i = 0; i < NR; i++)
	{
		Ntemp = 0;
		tempv.push_back(Rod[i]);
		for(auto it = FR.begin(); it != FR.end(); ++it)
		{
			if(((int)(*it).at(0) % Interval == Rod[i]) & (Ntemp < NF) )
			{
				temp_P = (*it).at(1);
				tempv.push_back(temp_P);
				total += (*it).at(1);
				Ntemp++;
			}
                }
		v_Power.push_back(tempv);
		tempv.clear();
	}


	for(auto it = v_Power.begin(); it != v_Power.end(); ++it)
        {
                for(auto jt = (*it).begin()+1; jt != (*it).end(); ++jt)
                {
					(*jt) = (*jt)/total*Power;
                }
        }


	return;
}
/*
int main()
{
	cout << "Begin main." << endl;
	vector<vector<double>> vPower;
	GetPowerofCell(vPower);
	for(auto it = vPower.begin(); it != vPower.end(); ++it)
    {
        for(auto jt = (*it).begin(); jt != (*it).end(); ++jt)
        {
			cout << (*jt) << ", ";
        }
		cout << endl;
    }

	return 0;
}*/

