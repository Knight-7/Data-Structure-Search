#pragma once
#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED

#include<stdio.h>
#include<malloc.h>
#define NULL 0
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;
//����һ��������(ǰ�巨)
/*
void CreatList_L(LinkList L,int n)
{
	int i;
	LinkList p,q;
	q=L;
	for(i=1;i<=n;i++){
		p=(LinkList)malloc(sizeof(LNode));
		printf("�������Ա�ĵ�%d��Ԫ�أ�",i);
		scanf("%d",&p->data);
		p->next=q->next;
		q->next=p;
	}
}*/
//����һ��������(β�巨)
void CreatList_L(LinkList L, int n)
{
	int i;
	LinkList p, q;
	q = L;
	for (i = 1; i <= n; i++) {
		p = (LinkList)malloc(sizeof(LNode));
		printf("�������Ա�ĵ�%d��Ԫ�أ�", i);
		scanf("%d", &p->data);
		p->next = q->next;
		q->next = p;
		q = q->next;//q=p;
	}
}
/*
//������Ա�(�ݹ���ǵݹ�)(ǰ�巨��)
void TraverList_L(LinkList head)
{
	if(head==NULL)
		return;
	else{
		TraverList_L(head->next);
		printf("%5d\n",head->data);
		}
}
*/
//������Ա�(�ݹ���ǵݹ�)(β�巨��)
void TraverList_L(LinkList head)
{

	LinkList p;
	printf("��headΪͷָ��ĵ������Ԫ��Ϊ��");
	p = head->next;
	while (p != NULL) {
		printf("%5d", p->data);
		p = p->next;
	}
	/*
	if(head==NULL)
		return;
	else{
		printf("%5d",head->data);
		TraverList_L(head->next);
	}
	*/
}
//max����
int max_L(int a, int b)
{
	return a > b ? a : b;
}

//����������ֵ
int LinkList_Max(LinkList L)
{
	LinkList q;
	q = L->next;
	if (q) {
		return max_L(q->data, LinkList_Max(q));
	}
}
//������Ľڵ����
int LinkList_Countnode(LinkList L)
{
	if (L->next)
		return LinkList_Countnode(L->next) + 1;
}
//���������������
int LinkList_Sum(LinkList L)
{
	LinkList q;
	q = L->next;
	if (q)
		return q->data + LinkList_Sum(q);
}

#endif // LINKLIST_H_INCLUDED
