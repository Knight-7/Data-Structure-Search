#include<bits/stdc++.h>
#include"search.h"
using namespace std;

int main()
{
	SSTable st;
	cin >> st.lenth;
	InitSSTable(st);
	for (int i = 1; i <= st.lenth; i++) {
		cin >> st.R[i];
	}
	//顺序查找
	cout << "请输入要查找的数：";
	int a;
	cin >> a;
	cout << Search_Seq(st, a) << endl;
	//对分查找
	cout << Search_Bin(st, a) << endl;
	//二叉排序树
	BSTree t;
	CreatBST(t);
	Traver_BS(t);
	cout << endl;
	//哈希表的建立和查找
	HashTable ht;
	for (int i = 1; i < st.lenth; i++) {
		CreatHash(ht, st.R[i]);
	}
	cout << "哈希表" << endl;
	cout << SearchHash(ht, a) << endl;

	return 0;
}