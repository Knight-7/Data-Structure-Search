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
	//˳�����
	cout << "������Ҫ���ҵ�����";
	int a;
	cin >> a;
	cout << Search_Seq(st, a) << endl;
	//�Էֲ���
	cout << Search_Bin(st, a) << endl;
	//����������
	BSTree t;
	CreatBST(t);
	Traver_BS(t);
	cout << endl;
	//��ϣ��Ľ����Ͳ���
	HashTable ht;
	for (int i = 1; i < st.lenth; i++) {
		CreatHash(ht, st.R[i]);
	}
	cout << "��ϣ��" << endl;
	cout << SearchHash(ht, a) << endl;

	return 0;
}