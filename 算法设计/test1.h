#pragma once
#include"head.h"
using namespace std;
class Divide
{
private:
	vector<int> List;
	void Merge(int left,int mid,int right)
	{
		vector<int> temp(right-left+1);
		int i = left, j = mid + 1, k = 0;
		while ((i <= mid) && (j <= right))
		{
			if (List[i] <= List[j]) temp[k++] = List[i++];
			else temp[k++] = List[j++];
		}
		while (i <= mid) temp[k++] = List[i++];
		while (j <= right) temp[k++] = List[j++];
		for (i = 0, k = left; k <= right;)List[k++] = temp[i++];
	}
public:
	Divide(int size)
	{
		default_random_engine generator;
		uniform_int_distribution<int> dis(0, 1000);
		for (int i = 0; i < 5; i++)
			List.push_back(dis(generator));
	}
	friend ostream& operator << (ostream &os,const Divide &d) 
	{
		for (auto i : d.List)
			cout << i << " ";
		return os;
	}
	void MergeSort()
	{
		MergeSort(0, int(List.size()-1));
	}
	void MergeSort(int left,int right)
	{
		if (left < right)
		{
			int mid = (left + right) / 2;
			MergeSort(left, mid);
			MergeSort(mid+1, right);
			Merge(left, mid, right);
		}
	}
};