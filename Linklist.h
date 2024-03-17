#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
typedef struct
{
	int  no;        // 超女编号。
	char name[31];  // 超女姓名。
}ElemType;
typedef struct LNode
{
	ElemType data;//数据域名
	struct LNode *next;//指针域
}LNode,*LinkList; 

//在单链表第ii个位置插入结点
int listInsert(LinkList &LL,unsigned int ii,ElemType *ee);
// 初始化链表LL，返回值：失败返回NULL，成功返回头结点的地址。
LNode* InitList1();
// 初始化链表LL
int InitList3(LinkList& LL);
// 销毁链表LL。
// 传引用的地址的方法。
void DestroyList2(LinkList& LL);
// 清空链表。
void ClearList(LinkList LL);
// 打印链表中全部的元素。
void PrintList(LinkList LL);
// 在链表LL的头部插入元素ee，返回值：0-失败；1-成功。
int  PushFront(LinkList LL, ElemType* ee);
// 在链表LL的尾部插入元素ee，返回值：0-失败；1-成功。
int PushBack(LinkList LL, ElemType* ee);
//删除链表LL中的第ii个结点，返回值：0 - 位置ii不合法；1 - 成功。
int  DeleteNode(LinkList LL, unsigned int ii);
// 删除链表LL中最后一个结点，返回值：0-位置不合法；1-成功。
int PopBack(LinkList LL);
// 求链表的长度，返回值：>=0-表LL结点的个数。
int  LengthList(LinkList LL);
// 判断链表是否为空，返回值：0-非空或失败，1-空。
int IsEmpty(LinkList LL);
// 获取链表中第ii个结点，成功返回结点的地址，失败返回空。
// 注意，ii可以取值为0，表示头结点。
LNode* LocateNode(LinkList LL, unsigned int ii);
// 在指定结点pp之后插入元素ee，返回值：0-失败；1-成功。
int InsertNextNode(LNode* pp, ElemType* ee);
// 在指定结点pp之前插入元素ee，返回值：0-失败；1-成功。
int InsertPriorNode(LNode* pp, ElemType* ee);
