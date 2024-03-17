/*二叉树的层次遍历借助队列完成以及，先序，中序，后序递归完成*/
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
typedef  int Elemtype;
typedef struct BiTNode
{
	Elemtype data;//树结点数据域
	struct BiTNode* Lchild;//左孩子指针
	struct BiTNode* Rchild;//右孩子指针
}BiTNode,*PBiTNode;
//初始化二叉树
void InitBiTree(PBiTNode T);
//二叉树的新结点创建
BiTNode* NewNode(Elemtype& x);
//二叉树结点的插入，成功-》1，失败-》0
int InsertBitree(PBiTNode& T,Elemtype& x);

//二叉树的创建
BiTNode* Creat(int n, int arr[]);
//二叉树结点的左结点删除,值存入e中，成功-》1，失败-》0，flag=0,左孩子，1右孩子
//int Del_Bitree(PBiTNode T,int flag, Elemtype& e);

//查找子树中键值为x的结点并返回其地址
void SearchBitree(PBiTNode T, Elemtype* x,int data);

//返回二叉树的高度借用队列
int HighBitree(PBiTNode T);

//返回二叉树的高度递归
int HightRecu(PBiTNode T);

//结点访问函数
void VisitBitree(PBiTNode T); 

//前序
void PreOrder(PBiTNode T);

//中序
void InOrder(PBiTNode T);

//后序
void PostOrder(PBiTNode T);

 //二叉树的遍历，层次遍历

void LevelOrder(PBiTNode T);
//二叉树的非递归遍历，前中后
void No_re_PreOrder(PBiTNode T);
void No_re_InOrder(PBiTNode T);
void No_re_PostOrder(PBiTNode T); 
