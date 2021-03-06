//
// HG_Way.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <string>
#include "SparseGraph.h"
#include "ShortestPath.h"
#include "ReadGraph.h"
#include <math.h>

using namespace std;

// 测试深度优先遍历和广度优先遍历的寻路算法
int main() {

	string filename = "TextG.txt";
	SparseGraph g = SparseGraph(14, false);
	ReadGraph<SparseGraph> readGraph(g, filename);
	g.show();
	cout << endl;

	// 路线
	
	int iValue, oValue;
	cout << "输入起始站 ：";
	cin >> iValue;
	cout << "输入终点站 ：";
	cin >> oValue;
	ShortestPath<SparseGraph> bfs(g, iValue);
	cout <<  "乘车路线 : " << endl;
	//bfs.showPath(oValue);

	// show path
	vector<int> vec;
	bfs.path(oValue, vec);
	// 
	for (int i = 0; i < vec.size(); i++) {
		cout << vec[i];
		if (i == vec.size() - 1)
			cout << endl;
		else if (abs(vec[i + 1] - vec[i]) > 1)
			cout << "（中转站）" << endl;
		else
			cout << " -> ";
	}
	

	system("pause");
	return 0;
}