#pragma once
//�����㷨��˳�򣬷ֿ飬�۰룬���Σ�������������ƽ����������������
//B����B+����ɢ�У�Hash����
#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
typedef int ElemType;
//һ��˳�����
typedef struct//���ұ�����ݽṹ
{
	ElemType* Pelem;//ָ����ұ�ĳ�ʼ�ռ�
	int len;//���ұ�ĳ���
}STable;
//һ��˳�����
int Search_Seq(STable st, ElemType key);
//�����۰����
int Binary_Search(STable st, ElemType key);
