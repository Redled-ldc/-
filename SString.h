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
//串的初始化
void InitSting(HString& S);

//2.增加动态数组的长度,增加串的长度
void IncreaseSize(HString& S,  int len);

//赋值操作,将t的值赋值给s
bool StringAssgin(HString& S,char*T);

//StrCopy(&T,S)：复制操作。由串S复制得到串T,
bool StringCopy(HString* T, HString& S);

//判空操作 StrEmpty(S)：判空操作。若S为空串，则返回TRUE，否则返回FALSE。
bool StringEmpty(const HString& T);

//打印操作
void PrintString(HString& S);

//串连接,Concat(&T, S1, S2)：串联接。用T返回由S1和S2联接而成的新串
int StringConnect(HString& T, char* S1, char* S2);

//串的模式匹配BF
// 采用BF算法，查找在目标串sstr中模式串tstr出现的位置，字符串的起始位置从0开始。
// 只要在目标串sstr中找到了第一个模式串tstr，函数就返回。
// 成功返回模式串tstr在目标串sstr中第一次出现的数组下标，失败返回-1。
int IndexBf(HString& SS1, HString& TS2);

//next数组暴力求解
void get_next_arr(char* t, int* next);
// 采用kmp算法，查找在目标串sstr中模式串tstr出现的位置，字符串的起始位置从0开始。
// 只要在目标串sstr中找到了第一个模式串tstr，函数就返回。
// 成功返回模式串tstr在目标串sstr中第一次出现的数组下标，失败返回-1。
// int index_kmp(char *sstr,char *tstr)
int IndexKmp(HString& SS1, HString& TS2);