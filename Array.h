#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXSIZE 1000 //顺序表的最大长度为100
typedef unsigned int ElemType;//自定义顺序表的数据元素类型为整型
typedef struct
{
	ElemType data[MAXSIZE];  // 用数组存储顺序表中的元素
	unsigned int length;      // 顺序表中元素的个数
}SeqList, * PSeqList;


// 顺序表LL的初始化操作。
void InitList(PSeqList LL);

// 销毁顺序表LL。
void DestroyList(PSeqList LL);

// 在顺序表LL的第ii个位置插入元素ee，返回值：0-失败；1-成功。
int  InsertList(PSeqList LL, unsigned int ii, ElemType *ee);

// 在顺序表LL的头结点插入元素ee，返回值：0-失败；1-成功。
int  PushFront(PSeqList LL, ElemType* ee);

// 在顺序表LL的尾结点插入元素ee，返回值：0-失败；1-成功。
int  PushBack(PSeqList LL, ElemType* ee);

// 求顺序表的长度，返回值：>=0-表LL元素的个数。
int  LengthList(PSeqList LL);

// 获取顺序表中第ii个元素的值，存放在ee中，返回值：0-失败；1-成功。
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee);

// 清空顺序表。
void ClearList(PSeqList LL);

// 判断顺序表是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(PSeqList LL);

// 打印顺序表中全部的元素。
void PrintList(PSeqList LL);

// 查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置。
int  LocateElem(PSeqList LL, ElemType* ee);

// 删除顺序表LL中的第ii个元素，返回值：0-位置ii不合法；1-成功。
int  DeleteElem(PSeqList LL, unsigned int ii);

// 删除顺序表LL中头元素，返回值：0-位置ii不合法；1-成功。
int PopFront(PSeqList LL);

// 删除顺序表LL中尾元素，返回值：0-位置ii不合法；1-成功。
int PopBack(PSeqList LL);

// 采用归并的方法，将两个升序的顺序表La和Lb，合并成一个升序的顺序表Lc。
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc);
/*数据结构相关例题*/
//查找最小值元素的位置，并用最后一位元素填补
bool Del_Main(SeqList& L, ElemType& Value);
//元素逆置
void Reverse(SeqList& L);
//删除表中所有值为X的元素
void Del_X01(SeqList& L,ElemType X);
//删除表中所有值为X的元素
void Del_X02(SeqList& L, ElemType X);
//从有序表中删除其值在给定值之间的元素（s<t）
bool Del_range(int s, int t, SeqList& L);
//从有序表中删除其值在给定值之间的元素（s<t）
bool Del_s_t(int s, int t, SeqList& L);
//从有序表中删除所有值重复的元素，使其值各不相同
bool Del_same(SeqList& L);