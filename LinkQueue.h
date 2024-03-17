//c���Ե���ʽʵ��
#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
typedef int ElemType;    // �Զ�����е�����Ԫ��Ϊ������
typedef struct LinkNode//��ʽ���еĽ����
{
	ElemType data;
	struct LinkNode* next;
}LinkNode;
typedef struct LinkQueue//��ʽ����
{
	struct LinkNode* front, * rear;//��ͷ�Ͷ�βָ��
}*PLinkQueue,LinkQueue;
//���г�ʼ��
int InitLinkQueue(LinkQueue& Q);
//���ٶ���
void DestroyLinkQueue(LinkQueue& Q);
//��ն���
void ClearLinkQueue(LinkQueue& Q);
//�������
int EnLinkQueue(LinkQueue& Q, const ElemType& x);
//����
int DeLinkQueue(LinkQueue& Q, const ElemType& x);
//��ӡ�����е�Ԫ��
void PrintLinkQueue(LinkQueue& Q);
// �ж϶����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(LinkQueue& Q);
