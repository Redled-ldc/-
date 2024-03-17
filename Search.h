#pragma once
//查找算法，顺序，分块，折半，树形（二叉搜索树，平衡二叉树，红黑树）
//B树，B+树，散列（Hash）表
#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef int ElemType;
//一、顺序查找
typedef struct//查找表的数据结构
{
	ElemType* Pelem;//指向查找表的初始空间
	int len;//查找表的长度
}STable;
//一、顺序查找
int Search_Seq(STable st, ElemType key);
//二、折半查找
int Binary_Search(STable st, ElemType key);
