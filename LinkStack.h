#include<cstdio>
#include<cstring>
#include<iostream>
typedef int ElemType;
typedef struct SNode
{
	ElemType data;//ջ��Ԫ��
	struct SNode* next;//ָ����һ������ָ��
}SNode,*LinkStack;
// ��ջSS�ĳ�ʼ������������ͷ��㣬����ͷ���ĵ�ַ��
SNode* InitStack();

// ������ջSS��
void DestroyStack(LinkStack SS);

// Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Push(LinkStack SS, ElemType* ee);

// Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Pop(LinkStack SS, ElemType* ee);

// ����ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ�����
int  Length(LinkStack SS);

// �����ջ��
void Clear(LinkStack SS);

// �ж���ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(LinkStack SS);

// ��ӡ��ջ��ȫ����Ԫ�ء�
void PrintStack(LinkStack SS);

// ��ȡջ��Ԫ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
int GetTop(LinkStack SS, ElemType* ee);
