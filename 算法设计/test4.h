#pragma once
#include "head.h"
using namespace std; 
void NQuenns(int n);
void NQuenns(int k, int n, vector<int> x, int &count);
//n�ʺ�����
bool Place(int k,int i, vector<int> x)
{
	for (int j = 0; j < k; j++)//�����Ѿ������k���㣬j=0~k-1,�Ƿ������ɵ�k+1��ȡֵΪi�ĵ�
		if ((x[j] == i) || (abs(x[j] - i) == abs(j - k))) return false;
	return true;
}
void NQuenns(int n)
{
	vector<int> x(n,0);
	int count=0;
	NQuenns(0,n,x,count);
	cout << n << "�ʺ�Ľ�Ϊ" << count << "��" <<endl;
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