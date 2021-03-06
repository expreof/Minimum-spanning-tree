#include <iostream>
#include <fstream>
#include <ctime>
#include <Windows.h>
#include "Graph.h"
using namespace std;

int main(int argc, char *argv[])
{
	auto start = clock();
	ifstream input;
	if (argc == 1)
		input.open("1.txt");
	else
		input.open(argv[1]);	//将input与"1.txt"关联
	ofstream output("2.txt");	//将output与"2.txt"关联
	Graph G(input);				//从1.txt读取数据并建立图
	Graph sb = G.PrimMST();		//sb是G的最小生成树
	sb.print(output);			//输出sb到2.txt
	input.close();		//关闭文件
	output.close();
	auto end = clock();
	auto cost = end - start;
	cout << cost << endl;
	system("pause");
	return 0;
}

