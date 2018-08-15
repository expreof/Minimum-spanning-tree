#include "Graph.h"
#include <algorithm>

Graph Graph::PrimMST()
{
	Graph res(V);	//V�����ޱߵ�ͼ��������С������
	std::vector<bool> intree(V, false);	//true��ʾ�õ��ڼ���U�У��������е�MST
	intree[0] = true;	//0�Ŷ����ʼ��MST��
	for (int i = 0; i < V - 1; i++)	//ÿ��ѭ��U��һ����
	{
		Edge minv = { 0,0,99999 };	//�����ҳ���СȨ�ر�
		std::vector<Edge> mina;		//�洢ÿ��������С�ĺ��б�
		for (int s=0;s<V;s++)		//��ÿ��������С�ĺ��б�
		{
			if (!intree[s])			//ֻ��U�еĵ�
				continue;
			for (int x = 0; x < lll[s].foo.size(); x++)
			{
				if (intree[lll[s].foo[x].name])	//����ߵ������㶼��U��������
					continue;
				if (lll[s].foo[x].weight < minv.qz)	//�ҳ���СȨ�ر�
				{
					minv.qz = lll[s].foo[x].weight;
					minv.gg = s;
					minv.vv = lll[s].foo[x].name;
				}
			}
			mina.push_back(minv);
		}
		/*ʹ��C++�����㷨���е�min_element�����ҳ�U����СȨ�غ��бߣ�����ʹ��lambda���ʽ�Ƚϱ�*/
		auto ls = std::min_element(mina.begin(), mina.end(), [](Edge &a, Edge &b) {return a.qz < b.qz; });
		res.addedge(ls->gg, ls->vv, ls->qz);	//��res���һ����
		intree[ls->gg] = true;	//���¶������U
		intree[ls->vv] = true;
	}
	return res;
}
