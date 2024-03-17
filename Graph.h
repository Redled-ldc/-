//邻接矩阵法,稠密图
#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define  INFINITY MAX_val//最大值
#define MAX_VERTEX_NUM 100//顶点数目的最大值
typedef char VertexType;//顶点的数据类型
typedef int EdgeType;//带权图中边上权值的数据类型
//定义边信息
typedef struct Arctype
{
	int vex1, vex2;//弧或是边依附的两个顶点
	int Arcval;//边或是弧权值的信息
}Arctype;//边或是弧的结构定义
typedef struct
{
	int vexnum, arcnum;//顶点数目，边数目
	VertexType vex[MAX_VERTEX_NUM];//顶点表
	EdgeType Edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//边表
}MGraph;//邻接矩阵，图的结构
typedef struct
{
	int vexnum;//顶点数目
	VexNode AdjList[MAX_VERTEX_NUM];
 }ALGraph;//定义图结构