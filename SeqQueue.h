#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
#define MaxSize 100
typedef int ElemType;
typedef struct Queue
{
	ElemType data[MaxSize];//��Ŷ����е�Ԫ��
	int front, rear;//��ͷ�Ͷ�βָ��
}SeqQueue,*PSeqQueue;

//��ʼ��һ���ն���
void InitSeqQueue(PSeqQueue QQ);

// ����ѭ������QQ��
void DestroyQueue(PSeqQueue QQ);

//�ж϶����Ƿ�Ϊ�գ���-True���ǿ�-False
bool SeqQueueEmpty(PSeqQueue QQ);

// Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int InQueue(PSeqQueue QQ, ElemType* ee);

// Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int OutQueue(PSeqQueue QQ, ElemType* ee);

// ��ѭ�����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ�����
int  Length(PSeqQueue QQ);

// ���ѭ�����С�
void Clear(PSeqQueue QQ);

// �ж�ѭ�������Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(PSeqQueue QQ);

// �ж�ѭ�������Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqQueue QQ);

// ��ӡѭ��������ȫ����Ԫ�ء�
void PrintQueue(PSeqQueue QQ);

// ��ȡ��ͷԪ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز����ӡ�
int GetHead(PSeqQueue QQ, ElemType* ee);