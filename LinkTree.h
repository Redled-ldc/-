/*�������Ĳ�α���������������Լ����������򣬺���ݹ����*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
typedef  int Elemtype;
typedef struct BiTNode
{
	Elemtype data;//�����������
	struct BiTNode* Lchild;//����ָ��
	struct BiTNode* Rchild;//�Һ���ָ��
}BiTNode,*PBiTNode;
//��ʼ��������
void InitBiTree(PBiTNode T);
//���������½�㴴��
BiTNode* NewNode(Elemtype& x);
//���������Ĳ��룬�ɹ�-��1��ʧ��-��0
int InsertBitree(PBiTNode& T,Elemtype& x);

//�������Ĵ���
BiTNode* Creat(int n, int arr[]);
//��������������ɾ��,ֵ����e�У��ɹ�-��1��ʧ��-��0��flag=0,���ӣ�1�Һ���
//int Del_Bitree(PBiTNode T,int flag, Elemtype& e);

//���������м�ֵΪx�Ľ�㲢�������ַ
void SearchBitree(PBiTNode T, Elemtype* x,int data);

//���ض������ĸ߶Ƚ��ö���
int HighBitree(PBiTNode T);

//���ض������ĸ߶ȵݹ�
int HightRecu(PBiTNode T);

//�����ʺ���
void VisitBitree(PBiTNode T); 

//ǰ��
void PreOrder(PBiTNode T);

//����
void InOrder(PBiTNode T);

//����
void PostOrder(PBiTNode T);

 //�������ı�������α���

void LevelOrder(PBiTNode T);
//�������ķǵݹ������ǰ�к�
void No_re_PreOrder(PBiTNode T);
void No_re_InOrder(PBiTNode T);
void No_re_PostOrder(PBiTNode T); 
