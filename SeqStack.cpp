#include"SeqStack.h"
// 顺序栈SS的初始化操作。
void InitStack(PSeqStack SS)
{
	if (SS == NULL)return;//检查空指针
	SS->Top = -1;//Top指针指向-1
	memset(SS->data, 0, sizeof(ElemType)*MaxSize);//栈元素清零
}
// 元素入栈，返回值：0-失败；1-成功。
int Push(PSeqStack SS, ElemType* ee)
{
	if (SS == NULL||ee==NULL)//检查空指针
	{
		printf("指针为空，栈初始化失败 \n");
		return 0;
	}
	if (SS->Top == MaxSize - 1)//栈满
	{
		printf("栈已满，如栈失败 \n");
		return 0;
	}
	SS->data[++(SS->Top)] = *ee;//Top=Top+1;SS->data[top]=*ee
	return 1;
}
// 元素出栈，返回值：0-失败；1-成功。
int Pop(PSeqStack SS, ElemType* ee) 
{
	if (SS == NULL || ee == NULL)//检查空指针
	{
		printf("指针为空，栈初始化失败 \n");
		return 0;
	}
	if (SS->Top == -1)
	{
		printf("栈空！！！，出栈失败 \n");
		return 0;
	}
	*ee = SS->data[(SS->Top)--]; //*ee=SS->data[top];Top=Top-1
	return 1;
}
// 求顺序栈的长度，返回值：栈SS中元素的个数。
int Length(PSeqStack SS)
{
	if (SS == NULL) return 0;
	return (SS->Top) + 1;
}
// 判断顺序栈是否为空，返回值：1-空，0-非空或失败。
int IsEmpty(PSeqStack SS)
{
	if (SS == NULL)return 0;
	if (SS->Top == -1) return 1;
	return 0;
}
// 判断顺序栈是否已满，返回值：1-已满，0-未满或失败。
int IsFull(PSeqStack SS)
{
	if (SS == NULL)return 0;
	if (SS->Top == MaxSize - 1)return 1;
	return 0;
}
// 打印顺序栈中全部的元素。
void PrintStack(PSeqStack SS)
{
	if (SS == NULL) return;  // 检查空指针。

	if (SS->Top == -1) { printf("栈为空。\n"); return; }

	int kk;
	for (kk = 0; kk <= SS->Top; kk++)
	{
		printf("SS[%d],value=%c\n", kk, SS->data[kk]);     // 用数组的下标访问。
		// printf("SS[%d],value=%d\n",kk,*(SS->data+kk));   // 采用指针运算也可以。
	}
}

//获取栈顶元素，返回值：0 - 失败；1 - 成功。
// 只查看栈顶元素的值，元素不出栈。
int GetTop(PSeqStack SS, ElemType* ee)
{
	if ((SS == NULL) || (ee == NULL)) return 0;  // 检查空指针。

	if (IsEmpty(SS) == 1) { printf("栈为空。\n"); return 0; }

	memcpy(ee, &SS->data[SS->Top], sizeof(ElemType));  // 用数组的下标访问。
	// memcpy(ee,SS->data+SS->top,sizeof(ElemType));    // 采用指针运算也可以。

	return 1;
}