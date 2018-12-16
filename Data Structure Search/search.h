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
//顺序查找(顺序)
int Search_Seq(SSTable ST, ElemType key)
{
	for (int i = ST.lenth;; i--) {
		if (ST.R[i] == key)
			return i;
	}
	return 0;
}
//顺序查找（链式）
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
//对分查找
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

/******************二叉排序树**********************/
typedef struct BSTNode
{
	ElemType data;
	BSTNode *lchild, *rchild;
}BSTNode, *BSTree;
//二叉排序树的查找
BSTree Search_BST(BSTree T, ElemType key)
{
	if (T->data == key) return T;
	else if (T->data < key) return Search_BST(T->lchild, key);
	else return Search_BST(T->rchild, key);
}
//二叉排序树的插入
void InsertBST(BSTree &T, ElemType key)
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
//创建一个二叉排序树
void CreatBST(BSTree &T)
{
	T = NULL;
	ElemType ch;
	cin >> ch;
	while (ch != 101) {
		InsertBST(T, ch);
		cin >> ch;
	}
}
//输出二叉排序树
void Traver_BS(BSTree T)
{
	if (T) {
		Traver_BS(T->lchild);
		cout << T->data << " ";
		Traver_BS(T->rchild);
	}
}
/*******************哈希表********************/
#define m 20
#define KeyType int
#define nullkey 0
typedef struct
{
	KeyType key;
	//infoType otherinfo;
}HashTable[m];
//除留余数法
int Hash(KeyType key)
{
	return key % 11;
}
//创建散列表
int CreatHash(HashTable ht, KeyType key)
{
	int h0 = Hash(key);
	if (ht[h0].key == nullkey) ht[h0].key = key;
	else {
		for (int i = 1; i < m; i++) {
			h0 = (h0 + i) % m;
			if (ht[h0].key == nullkey) {
				ht[h0].key = key;
				return 0;
			}
			if (i == m)
				return -1;
		}
	}
}
//查找散列表
int SearchHash(HashTable ht, KeyType key)
{
	int h0 = Hash(key);
	if (ht[h0].key == nullkey) return -1;
	else if (ht[h0].key == key) return h0;
	else {
		for (int i = 1; i < m; i++) {
			h0 = (h0 + i) % m;
			if (ht[h0].key == key) return h0;
			else if (ht[h0].key == nullkey) return -1;
		}
		return -1;
	}

}


#endif // ! SEARCH_H_INCLUDE
