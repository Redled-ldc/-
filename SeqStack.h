#pragma once
//栈的顺序表实现
#include <stdio.h>
#include <string.h>
#define MaxSize 1000
typedef int ElemType;
typedef struct Stack
{
	ElemType Top;//栈定指针， 栈顶指针，从0到MAXSIZE-1，-1表示空栈，也可以从1到MAXSIZE，0表示空栈。
	ElemType data[MaxSize];//栈内元素
}SeqStack,*PSeqStack;
// 顺序栈SS的初始化操作。
void InitStack(PSeqStack SS);
// 元素入栈，返回值：0-失败；1-成功。
int Push(PSeqStack SS, ElemType* ee);
// 元素出栈，返回值：0-失败；1-成功。
int Pop(PSeqStack SS, ElemType* ee);
// 求顺序栈的长度，返回值：栈SS中元素的个数。
int Length(PSeqStack SS);
// 判断顺序栈是否为空，返回值：1-空，0-非空或失败。
int IsEmpty(PSeqStack SS);
// 判断顺序栈是否已满，返回值：1-已满，0-未满或失败。
int IsFull(PSeqStack SS);
// 打印顺序栈中全部的元素。
void PrintStack(PSeqStack SS);
// 获取栈顶元素，返回值：0 - 失败；1 - 成功。
// 只查看栈顶元素的值，元素不出栈。
int GetTop(PSeqStack SS, ElemType * ee);