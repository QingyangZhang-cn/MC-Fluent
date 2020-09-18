#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include "SortOut.h"
#include "ReadFR.h"
#include "rewritepower.h"
#include "ModifyMate.h"
#include "filestat.h"
#include "RMSE.h"
using namespace std;

int main()
{
    Input_File Input;
    int tag, tag2;
    int step = 0;
    int N = Input.m_Ni;
    double ero = 100;
    double rmsero = Input.m_error;
    vector<vector<string>> tempTR;    
    vector<vector<string>> lastTR;
    string str_openmc;
    string str_fluent;

    str_openmc = "openmc -s ";
    str_openmc.insert(9,Input.m_thread);
    str_fluent = "fluent 3d -t -p -g -i  ";
    str_fluent.insert(12,Input.m_thread);
    str_fluent.insert(22,Input.m_Jname);

//===========================================================MC-Fluent================================================================================
    cout << "MC-Fluent is written by Qingyang Zhang. If you have any questions, please contact the following email: zhangqingyang18@nudt.edu.cn" << endl;
    cout << "***********************************************" << endl;
    cout << "Checking nessesary files...." << endl;
    //======================================================
    if(!( Check("geometry.xml") && Check("materials.xml") && Check("setting.xml") && Check("tallies.xml")  && Check(Input.m_Hname) && Check("run.jou")))
    {
        return -1;
    }
    //======================================================
    cout << "Checking complete." << endl;
    cout << "***********************************************" << endl;
    cout << "PROGRAMMING START:" << endl;
    while(step < N || ero >= rmsero)
    {
        //Run Openmc。
        cout << "Openmc running..." << endl;
        tag = sysytem(str_openmc);
        cout << "Openmc running over and return: " << tag << endl;
        cout << "Fission rate has been obtained." << endl;
        cout <<" Ready to rewrite the power distribution of FLUENT UDF...." << endl;
        rewrite_UDFH();
        cout << "The power distribution transmission was successful." << endl;
        //RUN Fluent。
        cout << "Fluent running..."<< endl;
        system(str_fluent);
        cout << "Fluent running over and return: " << tag << endl;
        cout << "Modifying properties of materials..."
        //Computing ero.
        if(step == 0)
	{
		GetTandRou(lastTR);
	}
	else
	{
		GetTandRou(tempTR);
		ero = RMSE(tempTR,lastTR);
		lastTR = tempTR;
	}
        //**************************************************
        ModifyMaterial();
        ++step;
    }
    return 0;
}
