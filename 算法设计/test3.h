#pragma once
#include"head.h"
using namespace std;
class ENode
{
public:
	ENode(int n,int a)
	{
		adjVex = a;
		node = n;
	}
	ENode(int n)
	{
		node = n;
	}
	//w表示点w；
	//nextArc里面的ENode的adjVex表示点w到点nextArc[某个点]的边的权
	int adjVex;
	int node;
	vector<ENode> nextArc;
};
class Graph
{
public:
	Graph(int size)
	{
		for (auto i = 0; i < size; i++)
		{
			g.push_back(ENode(i));
			int a, n;
			cout << "输入点" << i << "的邻接点及其权。"<<endl;
			while (cin >> n >> a)
			{
				g[i].nextArc.push_back(ENode(n, a));
			}
			
		}
	}
	Graph(string s)
	{
		int size = 12;
		for (auto i = 0; i < size; i++)
			g.push_back(ENode(i));
		g[0].nextArc.push_back(ENode(1, 9));
		g[0].nextArc.push_back(ENode(2, 7));
		g[0].nextArc.push_back(ENode(3, 3));
		g[0].nextArc.push_back(ENode(4, 2));
		g[1].nextArc.push_back(ENode(5,4));
		g[1].nextArc.push_back(ENode(6,2));
		g[1].nextArc.push_back(ENode(7,1));
		g[2].nextArc.push_back(ENode(5,2));
		g[2].nextArc.push_back(ENode(6,7));
		g[3].nextArc.push_back(ENode(7, 11));
		g[4].nextArc.push_back(ENode(6,11));
		g[4].nextArc.push_back(ENode(7,18));
		g[5].nextArc.push_back(ENode(8,6));
		g[5].nextArc.push_back(ENode(9,5));
		g[6].nextArc.push_back(ENode(8,4));
		g[6].nextArc.push_back(ENode(9,3));
		g[7].nextArc.push_back(ENode(9,5));
		g[7].nextArc.push_back(ENode(10,6));
		g[8].nextArc.push_back(ENode(11,4));
		g[9].nextArc.push_back(ENode(11,2));
		g[10].nextArc.push_back(ENode(11,5));
	}
	friend ostream& operator << (ostream &os, const Graph & g)
	{
		for (auto n : g.g)
		{
			cout << n.node << "	";
			for (auto nn : n.nextArc)
				cout << "(" << nn.node << "," << nn.adjVex << ")" << "	";
			cout << endl;
		}
		return os;
	}
	int FMultiGraph()
	{
		vector<int> cost(g.size());
		cost[g.size() - 1] = 0;
		for (int j = g.size() - 2; j >= 0; j--)
		{
			float min = INFINITY;
			for (auto r : g[j].nextArc)
				if (r.adjVex + cost[r.node] < min)
					min = float(r.adjVex + cost[r.node]);
			cost[j] = min;
		}
		return cost[0];
	}
private:
	vector<ENode> g;
};