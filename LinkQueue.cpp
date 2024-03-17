#include"LinkQueue.h"
//���г�ʼ��
int InitLinkQueue(LinkQueue& Q)
{
	LinkNode* Phead = (LinkNode*)malloc(sizeof(LinkNode));//����ͷ���
	if (Phead == NULL) return 0;  // �ڴ治�㣬����ʧ�ܡ�
	Phead->next = NULL;//nextָ����Ϊ��
	Phead->data = 0;
	Q.front = Phead;
	Q.rear = Phead;
	return 1;
}
//���ٶ���
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
//��ն���
void ClearLinkQueue(LinkQueue& Q)
{
	if (&Q == NULL) return;//�ж϶����Ƿ����

	// ��ն���QQ��ָ�ͷ�����ȫ�������ݽ�㣬������ͷ��㡣
	LinkNode* tmp =Q.front->next, * tmpnext=NULL;
	while (tmp!=NULL)
	{
		tmpnext = tmp->next;
		free(tmp);
		tmp = tmpnext;
	}
	Q.rear = Q.front;//βָ��ָ��ͷ���
	Q.front->next = NULL;
}
//�������
int EnLinkQueue(LinkQueue& Q, const ElemType& x)
{
	if (Q.front == NULL) { printf("����Qδ��ʼ����\n"); return 0; } // ����δ��ʼ����
	LinkNode* p = (LinkNode*)malloc(sizeof(LinkNode));//�����½������β��
	if (p == NULL || (&Q == NULL)||x==NULL) { printf("����Ϊ�ջ������ʧ��"); return 0; }
	memcpy(&p->data, &x, sizeof(ElemType));
	//p->data = x;
	Q.rear->next = p;
	Q.rear = p;
	p->next = NULL;//��β�ÿ�
	return 1;
}
//����
int DeLinkQueue(LinkQueue& Q, ElemType& x)
{
	if ((&Q == NULL) || (x == NULL)) return 0;   // ����ָ�롣
	if (Q.front == NULL) { printf("����QQδ��ʼ����\n"); return 0; } // ����δ��ʼ����
	if (1 == IsEmpty(Q))printf("����Ϊ��"); return 0;
	LinkNode* p = Q.front->next;
	memcpy(&x, &p->data, sizeof(ElemType));
	//x = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	return 1;
}
//��ӡ�����е�Ԫ��
void PrintLinkQueue(LinkQueue& Q)
{
	if (&Q == NULL) return;   // ����ָ�롣

	if (Q.front == NULL) { printf("����QQδ��ʼ����\n"); return; } // ����δ��ʼ����

	LinkNode* pp = Q.front->next;  // �ӵ�1�����ݽ�㿪ʼ��

	while (pp != NULL)
	{
		printf("%c", pp->data);  // ���Ԫ��eeΪ�ṹ�壬���д���Ҫ�޸ġ�
		pp = pp->next;
	}
	printf("\n");
}
// �ж϶����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(LinkQueue& Q)
{

	if (&Q == NULL) return 0;  // ����ָ�롣

	if (Q.front == NULL) { printf("����QQδ��ʼ����\n"); return 0; } // ����δ��ʼ����

	if (Q.front->next == NULL)
		return 1;
	return 0;
	
}