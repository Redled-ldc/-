#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
#define MAXSIZE 50
typedef struct
{
	char* ch;
	long long length;
}HString,*PHString;
//���ĳ�ʼ��
void InitSting(HString& S);

//2.���Ӷ�̬����ĳ���,���Ӵ��ĳ���
void IncreaseSize(HString& S,  int len);

//��ֵ����,��t��ֵ��ֵ��s
bool StringAssgin(HString& S,char*T);

//StrCopy(&T,S)�����Ʋ������ɴ�S���Ƶõ���T,
bool StringCopy(HString* T, HString& S);

//�пղ��� StrEmpty(S)���пղ�������SΪ�մ����򷵻�TRUE�����򷵻�FALSE��
bool StringEmpty(const HString& T);

//��ӡ����
void PrintString(HString& S);

//������,Concat(&T, S1, S2)�������ӡ���T������S1��S2���Ӷ��ɵ��´�
int StringConnect(HString& T, char* S1, char* S2);

//����ģʽƥ��BF
// ����BF�㷨��������Ŀ�괮sstr��ģʽ��tstr���ֵ�λ�ã��ַ�������ʼλ�ô�0��ʼ��
// ֻҪ��Ŀ�괮sstr���ҵ��˵�һ��ģʽ��tstr�������ͷ��ء�
// �ɹ�����ģʽ��tstr��Ŀ�괮sstr�е�һ�γ��ֵ������±꣬ʧ�ܷ���-1��
int IndexBf(HString& SS1, HString& TS2);

//next���鱩�����
void get_next_arr(char* t, int* next);
// ����kmp�㷨��������Ŀ�괮sstr��ģʽ��tstr���ֵ�λ�ã��ַ�������ʼλ�ô�0��ʼ��
// ֻҪ��Ŀ�괮sstr���ҵ��˵�һ��ģʽ��tstr�������ͷ��ء�
// �ɹ�����ģʽ��tstr��Ŀ�괮sstr�е�һ�γ��ֵ������±꣬ʧ�ܷ���-1��
// int index_kmp(char *sstr,char *tstr)
int IndexKmp(HString& SS1, HString& TS2);