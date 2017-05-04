#include "test1.h"
#include "test2.h"
#include "test3.h"
#include "test4.h"
#include "test5.h"
using namespace std;
int main(void)
{
	////test1---分治法合并排序
	//Divide d(5);
	//cout << d << endl;
	//d.MergeSort();
	//cout << d << endl;

	////test2---贪心法作业调度
	/*Work w;
	cout << w << endl;
	w.greddy();*/

	//test3---动态规划法求多段图问题
	//Graph g("default");//将g初始化为课本p124，图7-1的5段图
	//cout << g;
	//cout << "s到t的最短长度为：" << g.FMultiGraph() << endl;

	//test4---回溯法求n皇后问题
	/*NQuenns(8);*/

	//test5---贪心法、动态规划、回溯法、分支限界法的背包问题
	//bag b("default");
	//cout << b.greddy() << endl;//贪心法
	//cout << b.dynamic() << endl;//动态规划
	//cout << b.bk() << endl;//回溯
	return 0;
}
