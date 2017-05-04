#pragma once
#include"head.h"
using namespace std;
bool comparion(const pair<float, float>& l, const pair<float, float>& r);
class Work
{
public:
	Work() {
		vector<pair<float, float>> temp(dp_map.begin(), dp_map.end());
		dp_vector = temp;
	}
	void Sort()
	{
		sort(dp_vector.begin(), dp_vector.end(), comparion);
	}
	void greddy()
	{
		Sort();
		int time = 0;
		for (int i = 0; i < int(dp_vector.size()); i++)
		{
			if (dp_vector[i].first > time)
			{
				cout << "取工作" << dp_vector[i].first << "利润" << dp_vector[i].second << endl;
				time++;
			}
		}
	}
	friend ostream& operator << (ostream &os, const Work &w)
	{
		for (auto i : w.dp_vector)
			cout << i.first<<"	"<<i.second<<endl;
		return os;
	}
	vector<pair<float, float>> dp_vector;
private:
	multimap<float, float> dp_map = { {2,100},{1,10} ,{2,15} ,{1,27} };
};

bool compare(const pair<float, float>& l, const pair<float, float>& r)
{
	return (l.second / l.first) > (r.second / r.first);
}