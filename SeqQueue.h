#pragma once
#include<cstdio>
#include<cstring>
#include<iostream>
#define MaxSize 100
typedef int ElemType;
typedef struct Queue
{
	ElemType data[MaxSize];//存放队列中的元素
	int front, rear;//对头和队尾指针
}SeqQueue,*PSeqQueue;

//初始化一个空队列
void InitSeqQueue(PSeqQueue QQ);

// 销毁循环队列QQ。
void DestroyQueue(PSeqQueue QQ);

//判断队列是否为空，空-True，非空-False
bool SeqQueueEmpty(PSeqQueue QQ);

// 元素入队，返回值：0-失败；1-成功。
int InQueue(PSeqQueue QQ, ElemType* ee);

// 元素出队，返回值：0-失败；1-成功。
int OutQueue(PSeqQueue QQ, ElemType* ee);

// 求循环队列的长度，返回值：>=0-队列QQ元素的个数。
int  Length(PSeqQueue QQ);

// 清空循环队列。
void Clear(PSeqQueue QQ);

// 判断循环队列是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(PSeqQueue QQ);

// 判断循环队列是否已满，返回值：1-已满，0-未满或失败。
int IsFull(PSeqQueue QQ);

// 打印循环队列中全部的元素。
void PrintQueue(PSeqQueue QQ);

// 获取队头元素，返回值：0-失败；1-成功。
// 只查看队头元素的值，元素不出队。
int GetHead(PSeqQueue QQ, ElemType* ee);