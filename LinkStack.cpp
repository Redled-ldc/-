#include"LinkStack.h"
#include<Stack>
// 链栈SS的初始化操作，分配头结点，返回头结点的地址。
SNode* InitStack()
{
	SNode* Head = (SNode*)malloc(sizeof(SNode));//分配头结点
	if (Head == NULL)//检查分配内存
	{
		printf("内存分配失败，栈的初始化失败");
		return NULL;
	}
	Head->next = NULL;//将头结点的下一结点置为空（暂时不存在）
	return Head;//返回分配的头结点
}
// 销毁链栈SS。
void DestroyStack(LinkStack SS)
{
	SNode* Temp = NULL;
	//逐个释放结点并将指针置为空
	while (SS!=NULL)
	{
		Temp = SS->next;//Temp保存SS的下一个结点
		free(SS);//释放当前结点
		SS = Temp;//逐渐往后移动
	}
	SS = NULL;
	return;
}
//清空链栈SS
void Clear(LinkStack SS)
{
	//释放除了头结点之外的结点
	SNode* Temp1 = NULL, * Temp2 = SS->next;//Temp2指向头结点后的第一个结点 
	while (Temp2!=NULL)
	{
		Temp1 = Temp2->next;
		free(Temp2);
		Temp2 = Temp1;
	}
	SS->next = NULL;
	return;
}
// 元素入栈，返回值：0-失败；1-成功。
int Push(LinkStack SS, ElemType* ee)
{
	if (SS == NULL || ee == NULL)return 0;
	SNode* StackNode = (SNode*)malloc(sizeof(SNode));
	if (StackNode == NULL)
	{
		printf("内存已满入栈失败");
		return 0;
	}
	memcpy(&StackNode->data, ee, sizeof(ElemType));
	StackNode->next = SS->next;//头插法
	SS->next = StackNode;
	return 1;
}
//元素出栈，返回值：0 - 失败；1 - 成功。
int Pop(LinkStack SS, ElemType* ee)
{
	if ((SS == NULL) || (ee == NULL)) return 0;  // 检查空指针。
	if (SS->next == NULL) { printf("栈为空。\n"); return 0; }
	SNode* Temp = SS->next;
	memcpy(ee, &Temp->data, sizeof(ElemType));
	SS->next = Temp->next;//删除第一个结点
	Temp = NULL;
	free(Temp);
	return 1;
}
// 求链栈的长度，返回值：栈SS中元素的个数。
int  Length(LinkStack SS)
{
	
	if (SS == NULL) return 0; // 检查空指针。

	SNode* pp = SS->next;  // 头结点不算，从第1个结点开始。

	int length = 0;

	while (pp != NULL) { pp = pp->next; length++; }

	return length;
}
// 判断链栈是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(LinkStack SS)
{
	if (SS == NULL) return 0;   // 检查空指针。
	if (SS->next == NULL) return 1;
	return 0;
}
//打印链栈中全部的元素。
void PrintStack(LinkStack SS)
{
	if (IsEmpty(SS) == 1) return;
	int kk = 0;
	SNode* pp = SS->next;  // 从第1个结点开始。

	while (pp != NULL)
	{
		printf("SS[%d],value=%c\n", kk++, pp->data);
		pp = pp->next;
	}
	return;
}
// 获取栈顶元素，返回值：0-失败；1-成功。
// 只查看栈顶元素的值，元素不出栈。
int GetTop(LinkStack SS, ElemType* ee)
{
	if ((SS == NULL) || (ee == NULL)) return 0;  // 检查空指针。

	if (SS->next == NULL) { printf("栈为空。\n"); return 0; }

	memcpy(ee, &SS->next->data, sizeof(ElemType));

	return 1;
}
//括号匹配
int Match_Brackets()
{
	char ch, x;
	std::stack<char> S;  
	scanf("%c",&ch);
	while (ch!=13)//程序到回车结束
	{
		if ((ch == '(') || (ch == '[')) S.push(ch);
		else if(ch==']')
		{
			x = S.top();
			S.pop();
			if (x != '[')
			{
				std::cout << "匹配失败";
				return false;
			}
		}
		else if (ch == ')')
		{
			x = S.top();
			S.pop();
			if (x != '(')
			{
				std::cout << "匹配失败";
				return false;
			}
		}
	}//while
	if (!S.empty())
	{
		std::cout << "括号数量不匹配";
		return false;
	}
	else return true;
}
//进制转换
int conversation(int n,int d)
{
	std::stack<int> S;
	int k;
	while (n>0)
	{
		k = n % d;
		S.push(k);
		n = n / d;
	}
	while (!S.empty())
	{
		std::cout << S.top();
		S.pop();
	}
}