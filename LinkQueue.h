//c语言的链式实现
#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
typedef int ElemType;    // 自定义队列的数据元素为整数。
typedef struct LinkNode//链式队列的结点域
{
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct LinkQueue//链式队列
{
	struct LinkNode* front, * rear;//队头和队尾指针
}*PLinkQueue,LinkQueue;
//队列初始化
int InitLinkQueue(LinkQueue& Q);
//销毁队列
void DestroyLinkQueue(LinkQueue& Q);
//清空队列
void ClearLinkQueue(LinkQueue& Q);
//队列入队
int EnLinkQueue(LinkQueue& Q, const ElemType& x);
//出队
int DeLinkQueue(LinkQueue& Q, const ElemType& x);
//打印队列中的元素
void PrintLinkQueue(LinkQueue& Q);
// 判断队列是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(LinkQueue& Q);
