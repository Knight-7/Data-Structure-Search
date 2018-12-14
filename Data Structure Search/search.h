#pragma once
#ifndef  SEARCH_H_INCLUDE
#define SEARCH_H_INCLUDE

#include<bits/stdc++.h>
#include"LinkList.h"
using namespace std;

#define ElemType int
typedef struct {
	ElemType *R;
	int lenth;
}SSTable;
//˳�����(˳��)
int Search_Seq(SSTable ST, ElemType key)
{
	for (int i = ST.lenth;; i--) {
		if (ST.R[i] == key)
			return i;
	}
	return 0;
}
//˳����ң���ʽ��
int Search_Link(LinkList L,ElemType key)
{
	LinkList p = L->next;
	while (p) {
		if (L->data == key)
			return L->data;
		p = p->next;
	}
	return 0;
}
//�Էֲ���
int Search_Bin(SSTable ST, ElemType key)
{
	int l = 1, r = ST.lenth;
	while (l <= r) {
		int mid = (l + 1) >> 1;
		if (ST.R[mid] == key) return mid;
		else if (ST.R[mid] < key) l = mid + 1;
		else r = mid - 1;
	}
}

/******************����������**********************/
typedef struct BSTNode
{
	ElemType data;
	BSTNode *lchild, *rchild;
}BSTNode, *BSTree;
//�����������Ĳ���
BSTree Search_BST(BSTree T, ElemType key)
{
	if (T->data == key) return T;
	else if (T->data < key) return Search_BST(T->lchild, key);
	else return Search_BST(T->rchild, key);
}
//�����������Ĳ���
void InsertBST(BSTree T, ElemType key)
{
	if (!T) {
		BSTree S = new BSTNode;
		S->data = key;
		S->lchild = S->rchild = NULL;
		T = S;
	}
	else if (T->data < key) InsertBST(T->rchild, key);
	else InsertBST(T->lchild, key);
}
//����һ������������
void CreatBST(BSTree &T)
{
	T = NULL;
	ElemType ch;
	while (ch != 101) {
		InsertBST(T, ch);
		cin >> ch;
	}
}
/********************************************/

#endif // ! SEARCH_H_INCLUDE
