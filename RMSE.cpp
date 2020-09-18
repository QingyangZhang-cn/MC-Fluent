#include <RMSE.h>
using namespace std;

double RMSE(vector<vector<string>>& IDTROU1, vector<vector<string>>& IDTROU2)
{
	int count = 0;
	vector<double> T1;
	vector<double> T2;
	stringstream str_stream;
	double temp;
	double sum = 0.0;
	double result = 0.0; 
	for(auto it = IDTROU1.begin(); it != IDTROU1.end(); ++it)
	{
		str_stream << (*it).at(1);
                str_stream >> temp;
                str_stream.clear();
                T1.push_back(temp);
		count ++;
	}
        for(auto jt = IDTROU2.begin(); jt != IDTROU2.end(); ++jt)
        {
                str_stream << (*jt).at(1);
                str_stream >> temp;
                str_stream.clear();
                T2.push_back(temp);
        }
	for(int i = 0; i<count; ++i)
	{
		sum += ((T1[i]-T2[i]) * (T1[i]-T2[i]));
	}
	result = sqrt(sum/count);
	return result;
}
