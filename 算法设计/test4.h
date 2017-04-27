#pragma once
#include "head.h"
using namespace std; 
void NQuenns(int n);
void NQuenns(int k, int n, vector<int> x, int &count);
//n皇后问题
bool Place(int k,int i, vector<int> x)
{
	for (int j = 0; j < k; j++)//对于已经分配的k个点，j=0~k-1,是否能容纳第k+1个取值为i的点
		if ((x[j] == i) || (abs(x[j] - i) == abs(j - k))) return false;
	return true;
}
void NQuenns(int n)
{
	vector<int> x(n,0);
	int count=0;
	NQuenns(0,n,x,count);
	cout << n << "皇后的解为" << count << "个" <<endl;
}
void NQuenns(int k, int n,vector<int> x,int& count)
{
	for (int i = 0; i < n; i++){
		if (Place(k, i, x)) {
			x[k] = i;
			if (k == n - 1) {
				/*for (auto temp : x)
					cout << temp << " ";
				cout << endl;*/
				count++;
			}
			else NQuenns(k + 1, n, x, count);
		}
	}
}