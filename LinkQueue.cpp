#include"LinkQueue.h"
//队列初始化
int InitLinkQueue(LinkQueue& Q)
{
	LinkNode* Phead = (LinkNode*)malloc(sizeof(LinkNode));//建立头结点
	if (Phead == NULL) return 0;  // 内存不足，返回失败。
	Phead->next = NULL;//next指针置为空
	Phead->data = 0;
	Q.front = Phead;
	Q.rear = Phead;
	return 1;
}
//销毁队列
void DestroyLinkQueue(LinkQueue& Q)
{
	if (&Q == NULL)return;
	LinkNode* tmp = Q.front, * tempnext = NULL;
	while (tmp!=NULL)
	{
		tempnext = tmp->next;
		free(tmp);
		tmp = tempnext;
	}
	Q.front = Q.rear = NULL;
}
//清空队列
void ClearLinkQueue(LinkQueue& Q)
{
	if (&Q == NULL) return;//判断队列是否存在

	// 清空队列QQ是指释放链表全部的数据结点，但保留头结点。
	LinkNode* tmp =Q.front->next, * tmpnext=NULL;
	while (tmp!=NULL)
	{
		tmpnext = tmp->next;
		free(tmp);
		tmp = tmpnext;
	}
	Q.rear = Q.front;//尾指针指向头结点
	Q.front->next = NULL;
}
//队列入队
int EnLinkQueue(LinkQueue& Q, const ElemType& x)
{
	if (Q.front == NULL) { printf("队列Q未初始化。\n"); return 0; } // 队列未初始化。
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));//创建新结点插入队尾；
	if (p == NULL || (&Q == NULL)||x==NULL) { printf("队列为空或结点分配失败"); return 0; }
	memcpy(&p->data, &x, sizeof(ElemType));
	//p->data = x;
	Q.rear->next = p;
	Q.rear = p;
	p->next = NULL;//队尾置空
	return 1;
}
//出队
int DeLinkQueue(LinkQueue& Q, ElemType& x)
{
	if ((&Q == NULL) || (x == NULL)) return 0;   // 检查空指针。
	if (Q.front == NULL) { printf("队列QQ未初始化。\n"); return 0; } // 队列未初始化。
	if (1 == IsEmpty(Q))printf("队列为空"); return 0;
	LinkNode* p = Q.front->next;
	memcpy(&x, &p->data, sizeof(ElemType));
	//x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return 1;
}
//打印队列中的元素
void PrintLinkQueue(LinkQueue& Q)
{
	if (&Q == NULL) return;   // 检查空指针。

	if (Q.front == NULL) { printf("队列QQ未初始化。\n"); return; } // 队列未初始化。

	LinkNode* pp = Q.front->next;  // 从第1个数据结点开始。

	while (pp != NULL)
	{
		printf("%c", pp->data);  // 如果元素ee为结构体，这行代码要修改。
		pp = pp->next;
	}
	printf("\n");
}
// 判断队列是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(LinkQueue& Q)
{

	if (&Q == NULL) return 0;  // 检查空指针。

	if (Q.front == NULL) { printf("队列QQ未初始化。\n"); return 0; } // 队列未初始化。

	if (Q.front->next == NULL)
		return 1;
	return 0;
	
}