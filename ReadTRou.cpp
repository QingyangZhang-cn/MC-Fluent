#include "ReadTRou.h"

using namespace std;
/*get T and density. 2020.0722*/
void ReadTRou(vector<vector<string>>& TR)
{
    vector<string> vtemp;
    string temp;
    int count = 0;
    string filename = "Fluent_Output.txt";
    ifstream input(filename);

    if(!input)
    {
        fprintf(stderr, "Open Output.txt Error. \n");
        return;
    }

    while(input >> temp)
    {
        count += 1;
        if((count%3) != 0)
        {
            vtemp.push_back(temp);
        }
        else
        {
            vtemp.push_back(temp);
            TR.push_back(vtemp);
            vtemp.clear();
        }
    }
    return;
}

/*
int main()
{
	vector<vector<string>> TR;
	ReadTRou(TR);
	for(auto it = TR.begin(); it != TR.end(); it++)
	{
		for(auto jt = (*it).begin(); jt != (*it).end(); jt++)
		{
			cout << (*jt) << "    ";
		}
		cout << endl;
	}
	return 0;
}
*/
