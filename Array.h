#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXSIZE 1000 //˳������󳤶�Ϊ100
typedef unsigned int ElemType;//�Զ���˳��������Ԫ������Ϊ����
typedef struct
{
	ElemType data[MAXSIZE];  // ������洢˳����е�Ԫ��
	unsigned int length;      // ˳�����Ԫ�صĸ���
}SeqList, * PSeqList;


// ˳���LL�ĳ�ʼ��������
void InitList(PSeqList LL);

// ����˳���LL��
void DestroyList(PSeqList LL);

// ��˳���LL�ĵ�ii��λ�ò���Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  InsertList(PSeqList LL, unsigned int ii, ElemType *ee);

// ��˳���LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushFront(PSeqList LL, ElemType* ee);

// ��˳���LL��β������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushBack(PSeqList LL, ElemType* ee);

// ��˳���ĳ��ȣ�����ֵ��>=0-��LLԪ�صĸ�����
int  LengthList(PSeqList LL);

// ��ȡ˳����е�ii��Ԫ�ص�ֵ�������ee�У�����ֵ��0-ʧ�ܣ�1-�ɹ���
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee);

// ���˳���
void ClearList(PSeqList LL);

// �ж�˳����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(PSeqList LL);

// ��ӡ˳�����ȫ����Ԫ�ء�
void PrintList(PSeqList LL);

// ����ee��˳���LL�е�λ�ã�����ֵ��0-Ԫ��ee�ڱ�LL�в����ڣ�>0Ԫ��ee�ڱ�LL�е�λ�á�
int  LocateElem(PSeqList LL, ElemType* ee);

// ɾ��˳���LL�еĵ�ii��Ԫ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int  DeleteElem(PSeqList LL, unsigned int ii);

// ɾ��˳���LL��ͷԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int PopFront(PSeqList LL);

// ɾ��˳���LL��βԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int PopBack(PSeqList LL);

// ���ù鲢�ķ����������������˳���La��Lb���ϲ���һ�������˳���Lc��
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc);
/*���ݽṹ�������*/
//������СֵԪ�ص�λ�ã��������һλԪ���
bool Del_Main(SeqList& L, ElemType& Value);
//Ԫ������
void Reverse(SeqList& L);
//ɾ����������ֵΪX��Ԫ��
void Del_X01(SeqList& L,ElemType X);
//ɾ����������ֵΪX��Ԫ��
void Del_X02(SeqList& L, ElemType X);
//���������ɾ����ֵ�ڸ���ֵ֮���Ԫ�أ�s<t��
bool Del_range(int s, int t, SeqList& L);
//���������ɾ����ֵ�ڸ���ֵ֮���Ԫ�أ�s<t��
bool Del_s_t(int s, int t, SeqList& L);
//���������ɾ������ֵ�ظ���Ԫ�أ�ʹ��ֵ������ͬ
bool Del_same(SeqList& L);