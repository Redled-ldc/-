//�ڽӾ���,����ͼ
#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define  INFINITY MAX_val//���ֵ
#define MAX_VERTEX_NUM 100//������Ŀ�����ֵ
typedef char VertexType;//�������������
typedef int EdgeType;//��Ȩͼ�б���Ȩֵ����������
//�������Ϣ
typedef struct Arctype
{
	int vex1, vex2;//�����Ǳ���������������
	int Arcval;//�߻��ǻ�Ȩֵ����Ϣ
}Arctype;//�߻��ǻ��Ľṹ����
typedef struct
{
	int vexnum, arcnum;//������Ŀ������Ŀ
	VertexType vex[MAX_VERTEX_NUM];//�����
	EdgeType Edge[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�߱�
}MGraph;//�ڽӾ���ͼ�Ľṹ
typedef struct
{
	int vexnum;//������Ŀ
	VexNode AdjList[MAX_VERTEX_NUM];
 }ALGraph;//����ͼ�ṹ