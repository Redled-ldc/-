#include"LinkList.h"
// 初始化链表LL
int InitList3(LinkList& LL)
{
	if (LL != NULL) { printf("链表L已存在，在初始化之前请先释放它。\n"); return 0; }

	LNode* head = (LNode*)malloc(sizeof(LNode));  // 分配头结点。

	if (head == NULL) return 0;  // 内存不足，返回失败。

	head->next = NULL;  // 头结点的下一结点暂时不存在，置空。

	LL = head;

	return 1;
}
// 初始化链表LL，返回值：失败返回NULL，成功返回头结点的地址。
LNode* InitList1()
{
	LNode* Head =(LNode*)malloc(sizeof(LNode));
	if (Head == nullptr)
	{
		std::cout << "内测分配失败" << std::endl;
		return nullptr;
	}
	Head->next = nullptr;
	return Head;
}
// 销毁链表LL。
// 传入指针的地址的方法。
void DestroyList2(LinkList& LL)
{	// 销毁链表LL是指释放链表全部的结点，包括头结点
	LNode* Temp;
	while (LL!=nullptr)
	{
		Temp = LL->next;// tmp保存下一结点的地址。
		free(LL);// 释放当前结点。
		LL = Temp;// LL指针移动到下一结点。
	}
	LL = nullptr;// 把链表的指针置为空，表示链表不存在了
	return;
}
// 清空链表。
void ClearList(LinkList LL)// 清空链表LL是指释放链表全部的结点，但不包括头结点。
{
	if (LL == nullptr)
	{
		std::cout << "链表不存在";
		return;
	}
	LNode* Temp1, * Temp2;
	Temp2 = LL->next;
	while (Temp2!= nullptr)
	{
		Temp1 = Temp2->next;
		free(Temp2);
		Temp2 = Temp1;
	}
	LL->next = nullptr;//清空头结点的指针域防止野指针
}
//在单链表第ii个位置插入结点
 int listInsert(LinkList& LL, unsigned int ii, ElemType* ee)
{
	if (LL == nullptr || ee == nullptr)//判断元素是否存在
	{
		std::cout << "单链表为空或者元素ee为空";
		return 0;
	}
	if(ii<1)// 判断插入位置是否合法
	{
		std::cout << "插入元素不合法";
		return 0;
	}
	// 要在位序ii插入结点，必须找到ii-1结点
	LNode* pp = LL;  // 指针pp指向头结点，逐步往后移动，如果为空，表示后面没结点了。
	unsigned int kk = 0;     // kk指向的是第几个结点，从头结点0开始，pp每向后移动一次，kk就加1。
	while ((pp!=nullptr) && (kk <ii-1))
	{
		pp=pp->next; 
		kk++;//找到第ii-1个结点
		// printf("pp=%p,kk=%d\n",pp,kk);
	}
	if (pp == nullptr)
	{
		std::cout << "插入" << ii << "位置不合法超过表长了";
		return 0;
	}
	LNode* Temp = (LNode*)malloc(sizeof(LNode));  // 分配一个结点。
	if (Temp == nullptr)
	{
		return 0;  // 内存不足，返回失败。
	}
	memcpy(&Temp->data, ee, sizeof(ElemType));
	Temp->next = pp->next;
	pp->next = Temp;
	return 1;
}
 // 打印链表中全部的元素。
 void PrintList(LinkList LL)
 {
	 if (LL == NULL) { printf("链表LL不存在。\n"); return; } // 判断链表是否存在。

	 LNode* pp = LL->next;  // 从第1个结点开始。
	 while (pp!=nullptr)
	 {
		 printf("编号是no=%d  姓名是name=%s \n", pp->data.no, pp->data.name);
		 pp = pp->next;
	 }
 }

 // 在链表LL的头部插入元素ee，返回值：0-失败；1-成功。
 int  PushFront(LinkList LL, ElemType* ee)
 {
		 return listInsert(LL, 1, ee);
 }
 // 在链表LL的尾部插入元素ee，返回值：0-失败；1-成功。
 int PushBack(LinkList LL, ElemType* ee)
 {
	 //判断插入是否合法
	 if (LL == NULL || ee == NULL)
	 {
		 printf("链表为空或插入的元素为空");
		 return 0;
	 }
	 //从头结点开始
	 LNode* pp = LL;
	 //找到最后一个结点
	 while (pp->next!=NULL)
	 {
		 pp = pp->next;
	 }
	 LNode* Temp = (LNode*)malloc(sizeof(ElemType));//申请一个新结点
	 if (Temp == NULL) return 0;//内存分配失败
	 memcpy(&Temp->data, ee, sizeof(ElemType));
	 pp->next = Temp;
	 Temp->next = NULL;
	 return 1;
 }
 //删除链表LL中的第ii个结点，返回值：0 - 位置ii不合法；1 - 成功。
 int  DeleteNode(LinkList LL, unsigned int ii)
 {
	 if (LL == NULL)
	 {
		 printf("链表L不存在。\n");
		 return 0;  // 判断链表是否存在。
	 }
	 //位置判断
	 if (ii < 1)
	 {
		 printf("删除位置不合法 \n");
		 return 0;
	 }
	 //从头结点开始
	 LNode* pp = LL->next;
	 unsigned int kk = 0;
	 //找到第II-1个结点
	 while ((pp != NULL) && (kk < ii - 1))
	 {
		 pp = pp->next;
		 kk++;
	 }
	 if (pp->next!= NULL)
	 {
		 LNode* Temp = NULL;
		 Temp = pp->next;
		 pp->next = pp->next->next;
		 free(Temp);
	 }
	 return 1;
 }
 
 // 删除链表LL中最后一个结点，返回值：0-位置不合法；1-成功。
 int PopBack(LinkList LL)
 {
	 if (LL == NULL)
	 {
		 printf("链表LL为空 \n");
		 return 0;
	 }
	 // 必须加上这个判断，否则下面的循环pp->next->next不成立。
	 if (LL->next == NULL) { printf("链表LL为空，没有尾结点。\n"); return 0; } // 判断表是否为空。
	 //从头结点开始
	 LNode* pp = LL;
	 LNode* Temp = NULL;
	 while (pp->next->next != NULL)
	 {
		 pp = pp->next;
	 }
	 Temp = pp->next;
	 pp->next = NULL;
	 free(Temp);
	 return 0;
 }
 // 求链表的长度，返回值：>=0-表LL结点的个数。
 int  LengthList(LinkList LL)
 {
	 if (LL->next==NULL)
	 {
		 return 0; 
	 }
	 LNode* pp = LL->next;//从头结点开始遍历
	 int kk = 0;//计数链表长度
	 while (pp!= NULL)
	 {
		 pp = pp->next;
		 kk++;
	 }
	 return kk;
	 // 不使用临时变量，如何计算链表（包括头结点）的长度？
  // if (LL==NULL) return 0;
  // return LengthList(LL->next)+1;
 }
 // 判断链表是否为空，返回值：0 - 非空或失败，1 - 空。
 int IsEmpty(LinkList LL)
 {
	 if (LL == NULL) return 0;

	 if (LL->next == NULL) return 1;

	 return 0;
 }
 // 获取链表中第ii个结点，成功返回结点的地址，失败返回空。
// 注意，ii可以取值为0，表示头结点。
LNode *LocateNode(LinkList LL, unsigned int ii)
{
  if ( LL == NULL ) { printf("链表LL不存在。\n"); return NULL; } // 判断表和元素是否存在。
  
  LNode *pp=LL;  // 指针pp指向头结点，逐步往后移动，如果为空，表示后面没结点了。
  unsigned int kk=0;      // kk指向的是第几个结点，从头结点0开始，pp每向后移动一次，kk就加1。

  while ( (pp != NULL) && (kk < ii) )
  { 
    pp=pp->next; kk++; 
  }

  if ( pp==NULL ) { printf("位置（%d）不合法，超过了表长。\n",ii); return NULL; }

  return pp;
}
// 在指定结点pp之后插入元素ee，返回值：0-失败；1-成功。
int InsertNextNode(LNode *pp, ElemType *ee)
{
  if (pp == NULL)
  { printf("结点pp不存在。\n"); 
    return 0;
  }
  LNode *tmp = (LNode *)malloc(sizeof(LNode));
  if (tmp == NULL)
  {
	  return 0;
  }
  if (NULL==tmp->next)//最后一个结点
  {
	  memcpy(&tmp->data, ee, sizeof(ElemType));
	  pp->next = tmp;
	  tmp->next = NULL;
  }
  else
  {
	  memcpy(&tmp->data, ee, sizeof(ElemType));
	  tmp->next = pp->next;
	  pp->next = tmp;
  }
  return 1;
}
// 在指定结点pp之前插入元素ee，返回值：0-失败；1-成功。
int InsertPriorNode(LNode* pp, ElemType* ee)
{
	// 在指定结点pp之前插入元素ee，返回值：0-失败；1-成功。
		if (pp == NULL) { printf("结点pp不存在。\n"); return 0; }

		// 在指定结点pp之前插入采用偷梁换柱的方法：
		// 1、分配一个新的结点；
		// 2、把pp结点的数据和指针复制到新结点中。
		// 3、把待插入元素的数据存入pp结点中。

		LNode* tmp = (LNode*)malloc(sizeof(LNode));
		if (tmp == NULL) return 0;

		// 把pp结点的数据和指针复制到tmp中。
		memcpy(&tmp->data, &pp->data, sizeof(ElemType));
		tmp->next = pp->next;
		// 把待插入的元素存入pp中。
		memcpy(&pp->data, ee, sizeof(ElemType));
		pp->next = tmp;
		return 1;
}