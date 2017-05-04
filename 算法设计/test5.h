#pragma once
#include"head.h"
using namespace std;
bool comparion(const pair<float, float>& l, const pair<float, float>& r);
class bag
{
public:
	bag(float a, vector<pair<float, float>> b)
	{
		m = a;
		wp = b;
	}
	bag(string s) 
	{
		m = 6;
		wp = { { 2,1 },{ 3,2 },{ 4,4 } };
	}
	float greddy()
	{
		vector<pair<float, float>> temp = wp;
		float temp_m = m;
		float count = 0;
		sort(temp.begin(), temp.end(), comparion);
		for (auto i = 0; i < int(temp.size());i++)
		{
			if (temp_m - temp[i].first < 0)
				continue;
			else {
				/*cout << "取重量为" << temp[i].first << "价值为" << temp[i].second << "的重物" << endl;*/
				temp_m -= temp[i].first;
				count += temp[i].second;
			}
		}
		return count;
	}
	float dynamic()
	{
		return dynamic(wp.size()-1, m);
	}
	float dynamic(int j,float x)
	{
		if (j < 0)return ((x < 0) ? -INFINITY : 0);
		if (x < wp[j].first) return dynamic(j - 1, x);
		else {
			float a = dynamic(j - 1, x);
			float b = dynamic(j - 1, x - wp[j].first)+wp[j].second;
			return max(a, b);
		}
	}
	float bk()
	{
		float fp;
		bk(0, 0, 0, fp);
		return fp;
	}
	void bk(int k,float cp,float cw,float &fp)
	{
		if (float(cw + int(wp[k].first)) <= m){
			if (k < int(wp.size() - 1)) bk(k + 1, cp + wp[k].second, cw + wp[k].first, fp);
			if (cp + wp[k].second > fp && k == wp.size() - 1) {
				fp = cp + wp[k].second;
			}
		}
		if (bound(k, cp, cw) >= fp) {
			if (k < int(wp.size() - 1)) bk(k + 1, cp , cw , fp);
			if (cp  > fp && k == wp.size() - 1) {
				fp = cp;
			}
		}
	}
	float bound(int k, int cp, int cw)
	{
		float b = cp, c = cw;
		for (int i = k + 1; i < wp.size(); i++) {
			c += wp[i].first;
			if (c < m) b += wp[i].second;
			else return (b + (1 - (c - m) / wp[i].first)*wp[i].second);
		}
		return b;
	}
private:
	float m;
	vector<pair<float, float>> wp;
};

bool comparion(const pair<float, float>& l, const pair<float, float>& r)
{
	return (l.second / l.first) > (r.second / r.first);
}
