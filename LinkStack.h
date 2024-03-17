#include<cstdio>
#include<cstring>
#include<iostream>
typedef int ElemType;
typedef struct SNode
{
	ElemType data;//栈中元素
	struct SNode* next;//指向下一个结点的指针
}SNode,*LinkStack;
// 链栈SS的初始化操作，分配头结点，返回头结点的地址。
SNode* InitStack();

// 销毁链栈SS。
void DestroyStack(LinkStack SS);

// 元素入栈，返回值：0-失败；1-成功。
int Push(LinkStack SS, ElemType* ee);

// 元素出栈，返回值：0-失败；1-成功。
int Pop(LinkStack SS, ElemType* ee);

// 求链栈的长度，返回值：栈SS中元素的个数。
int  Length(LinkStack SS);

// 清空链栈。
void Clear(LinkStack SS);

// 判断链栈是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(LinkStack SS);

// 打印链栈中全部的元素。
void PrintStack(LinkStack SS);

// 获取栈顶元素，返回值：0-失败；1-成功。
// 只查看栈顶元素的值，元素不出栈。
int GetTop(LinkStack SS, ElemType* ee);
