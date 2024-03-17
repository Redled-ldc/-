#include"LinkTree.h"
//初始化二叉树
void InitBiTree(PBiTNode T)
{
	if (T == NULL)return;
	T = NULL;
}
//二叉树的新结点创建
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
//二叉树结点的插入，成功-》1，失败-》0
int InsertBitree(PBiTNode& T, Elemtype& x)//修改T指针本身
{
	if (NULL == T)//空树查找失败，插入结点，递归边界
	{
		T = NewNode(x);
		return 1;
	}
	if (T->data > x)//往做左子树搜索
	{
		InsertBitree(T->Lchild, x);
	}
	else
	{
		InsertBitree(T->Rchild, x);
	}
	return 1;
}
//返回二叉树的高度递归
int HightRecu(PBiTNode T)
{
	int left = 0, right = 0;
	if (NULL == T)//递归边界，空树
	{
		return 0;
	}
	left = HightRecu(T->Lchild);//求左子树高度
	right = HightRecu(T->Rchild);//求右子树高度
	if (left >= right)
		return left + 1;
	else
		return right + 1;

}
//二叉树的创建
BiTNode* Creat(int n, int arr[])
{
	BiTNode* root = NULL;
	for (int i = 0; i < n; i++)
	{
		InsertBitree(root, arr[i]);
	}
	return root;//返回根结点
}
//返回二叉树的高度借助队列
/*1. 将根结点入队，当前队列中第一层的结点数(count)为1；
2. 进行当前层结点数(count)次出队，判断每个结点的左右子树是否为空，如果不为空，则入队，下一层结点数(nextCount)++；
3. 将下一层结点数变为当前层结点数，进行下一次循环，深度 + 1；
4. 直到队列为空时退出循环，得到最大深度
————————————————*/
int HighBitree(PBiTNode T);
//二叉树结点的结点删除,值存入e中，成功-》1，失败-》0
//int Del_Bitree(PBiTNode T, int flag, Elemtype& e)
//结点访问函数
void VisitBitree(PBiTNode T)
{
	if (T == NULL)return;
	printf("结点的值为：%d", T->data);
}
//前序
void PreOrder(PBiTNode T)
{
	if (T == NULL)return;
	PreOrder(T->Lchild);
	VisitBitree(T);
	PreOrder(T->Rchild);
}

//中序
void InOrder(PBiTNode T)
{
	if (T == NULL)return;
	VisitBitree(T);
	PreOrder(T->Lchild);
	PreOrder(T->Rchild);
}
//后序
void PostOrder(PBiTNode T)
{
	if (T == NULL)return;
	PreOrder(T->Lchild);
	PreOrder(T->Rchild);
	VisitBitree(T);
}

//查找子树中键值为x的结点并返回其地址
void SearchBitree(PBiTNode T, Elemtype* x,int data)//修改T指向的内容
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
//二叉树的遍历，层次遍历
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

//二叉树的非递归遍历，前中后
void No_re_PreOrder(PBiTNode T)//前序：根左右
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