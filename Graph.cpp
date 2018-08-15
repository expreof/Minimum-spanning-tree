#include "Graph.h"
#include <algorithm>

Graph Graph::PrimMST()
{
	Graph res(V);	//V个点无边的图，保存最小生成树
	std::vector<bool> intree(V, false);	//true表示该点在集合U中，是生长中的MST
	intree[0] = true;	//0号顶点初始在MST里
	for (int i = 0; i < V - 1; i++)	//每次循环U多一个点
	{
		Edge minv = { 0,0,99999 };	//用以找出最小权重边
		std::vector<Edge> mina;		//存储每个顶点最小的横切边
		for (int s=0;s<V;s++)		//找每个顶点最小的横切边
		{
			if (!intree[s])			//只找U中的点
				continue;
			for (int x = 0; x < lll[s].foo.size(); x++)
			{
				if (intree[lll[s].foo[x].name])	//如果边的两个点都在U中则跳过
					continue;
				if (lll[s].foo[x].weight < minv.qz)	//找出最小权重边
				{
					minv.qz = lll[s].foo[x].weight;
					minv.gg = s;
					minv.vv = lll[s].foo[x].name;
				}
			}
			mina.push_back(minv);
		}
		/*使用C++泛型算法库中的min_element函数找出U中最小权重横切边，这里使用lambda表达式比较边*/
		auto ls = std::min_element(mina.begin(), mina.end(), [](Edge &a, Edge &b) {return a.qz < b.qz; });
		res.addedge(ls->gg, ls->vv, ls->qz);	//给res添加一条边
		intree[ls->gg] = true;	//将新顶点加入U
		intree[ls->vv] = true;
	}
	return res;
}
