#pragma once
#include <vector>
#include <iostream>
#include <fstream>
struct Edge	//�����������㣬�ߵ�Ȩ��
{
	int vv;
	int gg;
	int qz;
};
struct edge	//һ�����㣬�ߵ�Ȩ��
{
	int name;
	int weight;
};
struct vertex	//�ڽӱ���
{
	int name;	//��������
	std::vector<edge> foo;	//��ö����бߵĶ�����б�
	vertex(int z) { name = z; }	//���캯��
};
class Graph	//ͼ��
{
private:
	int V, E;	//������������
	std::vector<vertex> lll;	//�ڽӱ�
public:
	Graph(int v) :V(v), E(0)	//���캯��������V�������ޱߵ�ͼ
	{
		for (int i = 0; i < V; ++i)
			lll.push_back(i);
	}
	Graph(std::istream &input):E(0)	//���캯���������ж�������
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
	~Graph() {}	//��������
	int v_count() { return V; }	//��ȡͼ�Ķ�����
	int e_count() { return E; }	//��ȡͼ�ı���
	void addedge(int v, int w, int wei)	//���һ����
	{
		lll[v].foo.push_back({ w, wei });
		lll[w].foo.push_back({ v, wei });
		E++;	//������һ
	}
	Graph PrimMST();	//��С������������
	std::ostream &print(std::ostream &os)	//���һ��ͼ
	{
		os << V << std::endl;	//���������������
		os << E << std::endl;	//�������������
		for (int i = 0; i < V; i++)
			for (int j = 0; j < lll[i].foo.size(); j++)
				if (i < lll[i].foo[j].name)	//��ǰС���������
					os << i << '\t' << lll[i].foo[j].name << '\t' << lll[i].foo[j].weight << std::endl;
		return os;
	}
};