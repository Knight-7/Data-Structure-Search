#pragma once
#ifndef  SEARCH_H_INCLUDE
#define SEARCH_H_INCLUDE

#include<bits/stdc++.h>
using namespace std;

#define ElemType int
typedef struct {
	ElemType *R;
	int lenth;
}SSTable;
//顺序查找
int Search_Seq(SSTable ST, ElemType key)
{
	for (int i = ST.lenth;; i--) {
		if (ST.R[i] == key)
			return i;
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

#endif // ! SEARCH_H_INCLUDE
