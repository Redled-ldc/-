#include"LinkList.h"
// ��ʼ������LL
int InitList3(LinkList& LL)
{
	if (LL != NULL) { printf("����L�Ѵ��ڣ��ڳ�ʼ��֮ǰ�����ͷ�����\n"); return 0; }

	LNode* head = (LNode*)malloc(sizeof(LNode));  // ����ͷ��㡣

	if (head == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�

	head->next = NULL;  // ͷ������һ�����ʱ�����ڣ��ÿա�

	LL = head;

	return 1;
}
// ��ʼ������LL������ֵ��ʧ�ܷ���NULL���ɹ�����ͷ���ĵ�ַ��
LNode* InitList1()
{
	LNode* Head =(LNode*)malloc(sizeof(LNode));
	if (Head == nullptr)
	{
		std::cout << "�ڲ����ʧ��" << std::endl;
		return nullptr;
	}
	Head->next = nullptr;
	return Head;
}
// ��������LL��
// ����ָ��ĵ�ַ�ķ�����
void DestroyList2(LinkList& LL)
{	// ��������LL��ָ�ͷ�����ȫ���Ľ�㣬����ͷ���
	LNode* Temp;
	while (LL!=nullptr)
	{
		Temp = LL->next;// tmp������һ���ĵ�ַ��
		free(LL);// �ͷŵ�ǰ��㡣
		LL = Temp;// LLָ���ƶ�����һ��㡣
	}
	LL = nullptr;// �������ָ����Ϊ�գ���ʾ����������
	return;
}
// �������
void ClearList(LinkList LL)// �������LL��ָ�ͷ�����ȫ���Ľ�㣬��������ͷ��㡣
{
	if (LL == nullptr)
	{
		std::cout << "��������";
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
	LL->next = nullptr;//���ͷ����ָ�����ֹҰָ��
}
//�ڵ������ii��λ�ò�����
 int listInsert(LinkList& LL, unsigned int ii, ElemType* ee)
{
	if (LL == nullptr || ee == nullptr)//�ж�Ԫ���Ƿ����
	{
		std::cout << "������Ϊ�ջ���Ԫ��eeΪ��";
		return 0;
	}
	if(ii<1)// �жϲ���λ���Ƿ�Ϸ�
	{
		std::cout << "����Ԫ�ز��Ϸ�";
		return 0;
	}
	// Ҫ��λ��ii�����㣬�����ҵ�ii-1���
	LNode* pp = LL;  // ָ��ppָ��ͷ��㣬�������ƶ������Ϊ�գ���ʾ����û����ˡ�
	unsigned int kk = 0;     // kkָ����ǵڼ�����㣬��ͷ���0��ʼ��ppÿ����ƶ�һ�Σ�kk�ͼ�1��
	while ((pp!=nullptr) && (kk <ii-1))
	{
		pp=pp->next; 
		kk++;//�ҵ���ii-1�����
		// printf("pp=%p,kk=%d\n",pp,kk);
	}
	if (pp == nullptr)
	{
		std::cout << "����" << ii << "λ�ò��Ϸ���������";
		return 0;
	}
	LNode* Temp = (LNode*)malloc(sizeof(LNode));  // ����һ����㡣
	if (Temp == nullptr)
	{
		return 0;  // �ڴ治�㣬����ʧ�ܡ�
	}
	memcpy(&Temp->data, ee, sizeof(ElemType));
	Temp->next = pp->next;
	pp->next = Temp;
	return 1;
}
 // ��ӡ������ȫ����Ԫ�ء�
 void PrintList(LinkList LL)
 {
	 if (LL == NULL) { printf("����LL�����ڡ�\n"); return; } // �ж������Ƿ���ڡ�

	 LNode* pp = LL->next;  // �ӵ�1����㿪ʼ��
	 while (pp!=nullptr)
	 {
		 printf("�����no=%d  ������name=%s \n", pp->data.no, pp->data.name);
		 pp = pp->next;
	 }
 }

 // ������LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
 int  PushFront(LinkList LL, ElemType* ee)
 {
		 return listInsert(LL, 1, ee);
 }
 // ������LL��β������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
 int PushBack(LinkList LL, ElemType* ee)
 {
	 //�жϲ����Ƿ�Ϸ�
	 if (LL == NULL || ee == NULL)
	 {
		 printf("����Ϊ�ջ�����Ԫ��Ϊ��");
		 return 0;
	 }
	 //��ͷ��㿪ʼ
	 LNode* pp = LL;
	 //�ҵ����һ�����
	 while (pp->next!=NULL)
	 {
		 pp = pp->next;
	 }
	 LNode* Temp = (LNode*)malloc(sizeof(ElemType));//����һ���½��
	 if (Temp == NULL) return 0;//�ڴ����ʧ��
	 memcpy(&Temp->data, ee, sizeof(ElemType));
	 pp->next = Temp;
	 Temp->next = NULL;
	 return 1;
 }
 //ɾ������LL�еĵ�ii����㣬����ֵ��0 - λ��ii���Ϸ���1 - �ɹ���
 int  DeleteNode(LinkList LL, unsigned int ii)
 {
	 if (LL == NULL)
	 {
		 printf("����L�����ڡ�\n");
		 return 0;  // �ж������Ƿ���ڡ�
	 }
	 //λ���ж�
	 if (ii < 1)
	 {
		 printf("ɾ��λ�ò��Ϸ� \n");
		 return 0;
	 }
	 //��ͷ��㿪ʼ
	 LNode* pp = LL->next;
	 unsigned int kk = 0;
	 //�ҵ���II-1�����
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
 
 // ɾ������LL�����һ����㣬����ֵ��0-λ�ò��Ϸ���1-�ɹ���
 int PopBack(LinkList LL)
 {
	 if (LL == NULL)
	 {
		 printf("����LLΪ�� \n");
		 return 0;
	 }
	 // �����������жϣ����������ѭ��pp->next->next��������
	 if (LL->next == NULL) { printf("����LLΪ�գ�û��β��㡣\n"); return 0; } // �жϱ��Ƿ�Ϊ�ա�
	 //��ͷ��㿪ʼ
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
 // ������ĳ��ȣ�����ֵ��>=0-��LL���ĸ�����
 int  LengthList(LinkList LL)
 {
	 if (LL->next==NULL)
	 {
		 return 0; 
	 }
	 LNode* pp = LL->next;//��ͷ��㿪ʼ����
	 int kk = 0;//����������
	 while (pp!= NULL)
	 {
		 pp = pp->next;
		 kk++;
	 }
	 return kk;
	 // ��ʹ����ʱ��������μ�����������ͷ��㣩�ĳ��ȣ�
  // if (LL==NULL) return 0;
  // return LengthList(LL->next)+1;
 }
 // �ж������Ƿ�Ϊ�գ�����ֵ��0 - �ǿջ�ʧ�ܣ�1 - �ա�
 int IsEmpty(LinkList LL)
 {
	 if (LL == NULL) return 0;

	 if (LL->next == NULL) return 1;

	 return 0;
 }
 // ��ȡ�����е�ii����㣬�ɹ����ؽ��ĵ�ַ��ʧ�ܷ��ؿա�
// ע�⣬ii����ȡֵΪ0����ʾͷ��㡣
LNode *LocateNode(LinkList LL, unsigned int ii)
{
  if ( LL == NULL ) { printf("����LL�����ڡ�\n"); return NULL; } // �жϱ��Ԫ���Ƿ���ڡ�
  
  LNode *pp=LL;  // ָ��ppָ��ͷ��㣬�������ƶ������Ϊ�գ���ʾ����û����ˡ�
  unsigned int kk=0;      // kkָ����ǵڼ�����㣬��ͷ���0��ʼ��ppÿ����ƶ�һ�Σ�kk�ͼ�1��

  while ( (pp != NULL) && (kk < ii) )
  { 
    pp=pp->next; kk++; 
  }

  if ( pp==NULL ) { printf("λ�ã�%d�����Ϸ��������˱���\n",ii); return NULL; }

  return pp;
}
// ��ָ�����pp֮�����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertNextNode(LNode *pp, ElemType *ee)
{
  if (pp == NULL)
  { printf("���pp�����ڡ�\n"); 
    return 0;
  }
  LNode *tmp = (LNode *)malloc(sizeof(LNode));
  if (tmp == NULL)
  {
	  return 0;
  }
  if (NULL==tmp->next)//���һ�����
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
// ��ָ�����pp֮ǰ����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int InsertPriorNode(LNode* pp, ElemType* ee)
{
	// ��ָ�����pp֮ǰ����Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
		if (pp == NULL) { printf("���pp�����ڡ�\n"); return 0; }

		// ��ָ�����pp֮ǰ�������͵�������ķ�����
		// 1������һ���µĽ�㣻
		// 2����pp�������ݺ�ָ�븴�Ƶ��½���С�
		// 3���Ѵ�����Ԫ�ص����ݴ���pp����С�

		LNode* tmp = (LNode*)malloc(sizeof(LNode));
		if (tmp == NULL) return 0;

		// ��pp�������ݺ�ָ�븴�Ƶ�tmp�С�
		memcpy(&tmp->data, &pp->data, sizeof(ElemType));
		tmp->next = pp->next;
		// �Ѵ������Ԫ�ش���pp�С�
		memcpy(&pp->data, ee, sizeof(ElemType));
		pp->next = tmp;
		return 1;
}