#include"LinkTree.h"
//��ʼ��������
void InitBiTree(PBiTNode T)
{
	if (T == NULL)return;
	T = NULL;
}
//���������½�㴴��
BiTNode* NewNode(Elemtype& x)
{
	BiTNode* node = (BiTNode*)malloc(sizeof(BiTNode));
	if (node != NULL)
	{
		node->data = x;
		node->Lchild = node->Rchild = NULL;
	}
	return node;
}
//���������Ĳ��룬�ɹ�-��1��ʧ��-��0
int InsertBitree(PBiTNode& T, Elemtype& x)//�޸�Tָ�뱾��
{
	if (NULL == T)//��������ʧ�ܣ������㣬�ݹ�߽�
	{
		T = NewNode(x);
		return 1;
	}
	if (T->data > x)//��������������
	{
		InsertBitree(T->Lchild, x);
	}
	else
	{
		InsertBitree(T->Rchild, x);
	}
	return 1;
}
//���ض������ĸ߶ȵݹ�
int HightRecu(PBiTNode T)
{
	int left = 0, right = 0;
	if (NULL == T)//�ݹ�߽磬����
	{
		return 0;
	}
	left = HightRecu(T->Lchild);//���������߶�
	right = HightRecu(T->Rchild);//���������߶�
	if (left >= right)
		return left + 1;
	else
		return right + 1;

}
//�������Ĵ���
BiTNode* Creat(int n, int arr[])
{
	BiTNode* root = NULL;
	for (int i = 0; i < n; i++)
	{
		InsertBitree(root, arr[i]);
	}
	return root;//���ظ����
}
//���ض������ĸ߶Ƚ�������
/*1. ���������ӣ���ǰ�����е�һ��Ľ����(count)Ϊ1��
2. ���е�ǰ������(count)�γ��ӣ��ж�ÿ���������������Ƿ�Ϊ�գ������Ϊ�գ�����ӣ���һ������(nextCount)++��
3. ����һ��������Ϊ��ǰ��������������һ��ѭ������� + 1��
4. ֱ������Ϊ��ʱ�˳�ѭ�����õ�������
��������������������������������*/
int HighBitree(PBiTNode T);
//���������Ľ��ɾ��,ֵ����e�У��ɹ�-��1��ʧ��-��0
//int Del_Bitree(PBiTNode T, int flag, Elemtype& e)
//�����ʺ���
void VisitBitree(PBiTNode T)
{
	if (T == NULL)return;
	printf("����ֵΪ��%d", T->data);
}
//ǰ��
void PreOrder(PBiTNode T)
{
	if (T == NULL)return;
	PreOrder(T->Lchild);
	VisitBitree(T);
	PreOrder(T->Rchild);
}

//����
void InOrder(PBiTNode T)
{
	if (T == NULL)return;
	VisitBitree(T);
	PreOrder(T->Lchild);
	PreOrder(T->Rchild);
}
//����
void PostOrder(PBiTNode T)
{
	if (T == NULL)return;
	PreOrder(T->Lchild);
	PreOrder(T->Rchild);
	VisitBitree(T);
}

//���������м�ֵΪx�Ľ�㲢�������ַ
void SearchBitree(PBiTNode T, Elemtype* x,int data)//�޸�Tָ�������
{
	while (T!=NULL)
	{
		if (*x == T->data)
			T->data = data;
		else if (*x < T->data)
			T = T->Lchild;
		else
			T = T->Rchild;
	}
}
//�������ı�������α���
void LevelOrder(PBiTNode T)
{
	std::queue<PBiTNode> Q;
	Q.push(T);
	while (!Q.empty())
	{
		PBiTNode temp = Q.front();
		//std::cout << temp->data << std::endl;
		VisitBitree(temp);
		Q.pop();
		if (temp->Lchild != NULL)
			Q.push(temp->Lchild);
		if (temp->Rchild != NULL)
			Q.push(temp->Rchild);
	}
}

//�������ķǵݹ������ǰ�к�
void No_re_PreOrder(PBiTNode T)//ǰ�򣺸�����
{
	std::stack<PBiTNode> S;
	while (!S.empty()||T!=nullptr)
	{
		if (T!=NULL)
		{
			VisitBitree(T);
			S.push(T);
			T = T->Lchild;
		}
		else
		{
			S.pop();
			T = T->Rchild;
		}
		
	}
}
void No_re_InOrder(PBiTNode T)
{
	std::stack<PBiTNode> S;
	while (!S.empty()||T!=NULL)
	{
		if (T) 
		{
			S.push(T);
			T = T->Lchild;
		}
		else
		{
			S.pop();
			VisitBitree(T);
			T = T->Rchild;
		}
	}
}
void No_re_PostOrder(PBiTNode T)
{

}