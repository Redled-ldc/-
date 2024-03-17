#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
typedef struct
{
	int  no;        // ��Ů��š�
	char name[31];  // ��Ů������
}ElemType;
typedef struct LNode
{
	ElemType data;//��������
	struct LNode *next;//ָ����
}LNode,*LinkList; 

//�ڵ������ii��λ�ò�����
int listInsert(LinkList &LL,unsigned int ii,ElemType *ee);
// ��ʼ������LL������ֵ��ʧ�ܷ���NULL���ɹ�����ͷ���ĵ�ַ��
LNode* InitList1();
// ��ʼ������LL
int InitList3(LinkList& LL);
// ��������LL��
// �����õĵ�ַ�ķ�����
void DestroyList2(LinkList& LL);
// �������
void ClearList(LinkList LL);
// ��ӡ������ȫ����Ԫ�ء�
void PrintList(LinkList LL);
// ������LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushFront(LinkList LL, ElemType* ee);
// ������LL��β������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int PushBack(LinkList LL, ElemType* ee);
//ɾ������LL�еĵ�ii����㣬����ֵ��0 - λ��ii���Ϸ���1 - �ɹ���
int  DeleteNode(LinkList LL, unsigned int ii);
// ɾ������LL�����һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ���
int PopBack(LinkList LL);
// ������ĳ��ȣ�����ֵ��>=0-��LL���ĸ�����
int  LengthList(LinkList LL);
// �ж������Ƿ�Ϊ�գ�����ֵ��0-�ǿջ�ʧ�ܣ�1-�ա�
int IsEmpty(LinkList LL);
// ��ȡ�����е�ii����㣬�ɹ����ؽ��ĵ�ַ��ʧ�ܷ��ؿա�
// ע�⣬ii����ȡֵΪ0����ʾͷ��㡣
LNode* LocateNode(LinkList LL, unsigned int ii);
// ��ָ�����pp֮�����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertNextNode(LNode* pp, ElemType* ee);
// ��ָ�����pp֮ǰ����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertPriorNode(LNode* pp, ElemType* ee);
