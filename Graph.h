#pragma once
#include <vector>
#include <iostream>
#include <fstream>
struct Edge	//包含两个顶点，边的权重
{
	int vv;
	int gg;
	int qz;
};
struct edge	//一个顶点，边的权重
{
	int name;
	int weight;
};
struct vertex	//邻接表结点
{
	int name;	//顶点名字
	std::vector<edge> foo;	//与该顶点有边的顶点的列表
	vertex(int z) { name = z; }	//构造函数
};
class Graph	//图类
{
private:
	int V, E;	//顶点数，边数
	std::vector<vertex> lll;	//邻接表
public:
	Graph(int v) :V(v), E(0)	//构造函数，建立V个顶点无边的图
	{
		for (int i = 0; i < V; ++i)
			lll.push_back(i);
	}
	Graph(std::istream &input):E(0)	//构造函数，从流中读入数据
	{
		int eee;
		input >> V >> eee;
		for (int i = 0; i < V; ++i)
		{
			lll.push_back(i);
		}
		for (int i = 0; i < eee; ++i)
		{
			int v, w, wei;
			input >> v >> w >> wei;
			addedge(v, w, wei);
		}
	}
	~Graph() {}	//析构函数
	int v_count() { return V; }	//获取图的顶点数
	int e_count() { return E; }	//获取图的边数
	void addedge(int v, int w, int wei)	//添加一条边
	{
		lll[v].foo.push_back({ w, wei });
		lll[w].foo.push_back({ v, wei });
		E++;	//边数加一
	}
	Graph PrimMST();	//最小生成树的生成
	std::ostream &print(std::ostream &os)	//输出一张图
	{
		os << V << std::endl;	//输出顶点数并换行
		os << E << std::endl;	//输出边数并换行
		for (int i = 0; i < V; i++)
			for (int j = 0; j < lll[i].foo.size(); j++)
				if (i < lll[i].foo[j].name)	//按前小后大规则输出
					os << i << '\t' << lll[i].foo[j].name << '\t' << lll[i].foo[j].weight << std::endl;
		return os;
	}
};