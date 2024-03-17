#pragma once
//ջ��˳���ʵ��
#include <stdio.h>
#include <string.h>
#define MaxSize 1000
typedef int ElemType;
typedef struct Stack
{
	ElemType Top;//ջ��ָ�룬 ջ��ָ�룬��0��MAXSIZE-1��-1��ʾ��ջ��Ҳ���Դ�1��MAXSIZE��0��ʾ��ջ��
	ElemType data[MaxSize];//ջ��Ԫ��
}SeqStack,*PSeqStack;
// ˳��ջSS�ĳ�ʼ��������
void InitStack(PSeqStack SS);
// Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Push(PSeqStack SS, ElemType* ee);
// Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Pop(PSeqStack SS, ElemType* ee);
// ��˳��ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ�����
int Length(PSeqStack SS);
// �ж�˳��ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PSeqStack SS);
// �ж�˳��ջ�Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqStack SS);
// ��ӡ˳��ջ��ȫ����Ԫ�ء�
void PrintStack(PSeqStack SS);
// ��ȡջ��Ԫ�أ�����ֵ��0 - ʧ�ܣ�1 - �ɹ���
// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
int GetTop(PSeqStack SS, ElemType * ee);