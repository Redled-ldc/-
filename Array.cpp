#include"Array.h"

// 顺序表LL的初始化操作。
void InitList(PSeqList  LL)
{
	ClearList(LL);
}
// 求顺序表的长度，返回值：>=0-表LL元素的个数。
int  LengthList(PSeqList LL)
{
	if (LL == nullptr)
		return 0;
	return LL->length;
}
// 销毁顺序表LL。
void DestroyList(PSeqList LL)
{
	return;
}
 //在顺序表LL的第ii个位置插入元素ee，返回值：0-失败；1-成功。
int  InsertList(PSeqList LL, unsigned int ii, ElemType *ee)
{
	if (LL == nullptr || ee ==nullptr) return 0;
	if (LL->length >= MAXSIZE)
	{
		std::cout << "顺序表已满，插入失败";
			return 0;
	}
	if (ii < 1 || ii>LL->length+1)
	{
		std::cout << "插入位置不合法";
		return 0;
	}
	for (unsigned int j = LL->length; j >=ii; j--)
	{
		LL->data[j] = LL->data[j-1];
	}
	LL->data[ii-1] = *ee;//将元素插入到第ii个位置；
	LL->length = LL->length + 1;
	return 1;
	
}
 
//int InsertList1(PSeqList LL, unsigned int ii, ElemType* ee)
//{
//	if ((LL == NULL) || (ee == NULL)) return 0;   // 检查空指针。
//
//	if (LL->length >= MAXSIZE)
//	{
//		printf("顺序表已满，不能插入。\n"); return 0;
//	}
//
//	// 判断插入位置是否合法
//	if ((ii < 1) || (ii > LL->length + 1))
//	{
//		printf("插入位置（%d）不合法，应该在（%d-%d）之间。\n", ii, 1, LL->length + 1); return 0;
//	}
//
//	// 注意，元素后移只能用循环，不能用以下注释掉的方法，当元素是结构体时，以下方法不稳定。
//	// if ( ii < LL->length+1)
//	//    memcpy(LL->data+ii,LL->data+ii-1,(LL->length-ii+1)*sizeof(ElemType));
//
//	// 把ii和ii之后的元素后移。
//	 unsigned int kk;
//	for (kk = LL->length; kk >= ii; kk--)
//	{
//		// memcpy(LL->data+kk,LL->data+kk-1,sizeof(ElemType));  // 采用memcpy是为了支持ee为结构体的情况。
//		memcpy(&LL->data[kk], &LL->data[kk - 1], sizeof(ElemType));  // 用数组的形式也可以。
//	}
//
//	//memcpy(LL->data+ii-1,ee,sizeof(ElemType));  // 采用memcpy是为了支持ee为结构体的情况。
//	memcpy(&LL->data[ii - 1], ee, sizeof(ElemType));  // 用数组的形式也可以。
//	LL->length++;       // 表的长度加1。
//
//	return 1;
//}
// 清空顺序表。
void ClearList(PSeqList LL)
{
	if (LL == NULL) return;  // 检查空指针。
	LL->length = 0;  // 表长置为0。
	memset(LL->data, 0, sizeof(ElemType) * MAXSIZE);  // 数组元素清0。
}
// 获取顺序表中第ii个元素的值，存放在ee中，返回值：0-失败；1-成功。
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee)
{
	if (LL == nullptr || ee ==nullptr)return 0;//检查空指针
	if (ii<1 || ii>LL->length - 1) return 0;//检查位置合法性
	//memcpy(ee, LL->data+ii-1, sizeof(ElemType) * MAXSIZE);
	//std::cout << "调用了GetElem函数";
	memcpy(ee, &LL->data[ii-1] - 1, sizeof(ElemType) * MAXSIZE);
	return 1;
}

// 判断顺序表是否为空，返回值：1-空，0-非空或失败。
int  IsEmpty(PSeqList LL)
{
	if (LL->length == 0) return 1;
	return 0;
}
// 打印顺序表中全部的元素。
void PrintList(PSeqList LL)
{
	if (LL == nullptr||LL->length==0)return;

	/*for (int ii = 0, len = LL->length; ii < len / 2; ii++)   // 如何确定循环的边界？用笨方法举例验证，需要耐心。
	{
		// 交换数组中两个元素的值。str[ii]、str[len-1-ii]
		int Temp = LL->data[ii];
		LL->data[ii] = LL->data[len - 1 - ii];
		LL->data[len - 1 - ii] =Temp;
	}
	*/
	for (unsigned int  i = 0; i < LL->length; i++)
	{   

		std::cout << LL->data[i]<<"  ";
	}

}



// 查找ee在顺序表LL中的位置，返回值：0-元素ee在表LL中不存在，>0元素ee在表LL中的位置。
int  LocateElem(PSeqList LL, ElemType* ee)
{
	if (LL == nullptr || ee == nullptr)return 0;
	for (unsigned int i = 0; i < LL->length; i++)
	{
		if (LL->data[i] == (*ee))
			return i + 1;
	}
}

// 删除顺序表LL中的第ii个元素，返回值：0-位置ii不合法；1-成功。
int  DeleteElem(PSeqList LL, unsigned int ii)
{	
	if (LL == nullptr) return 0;
	if (ii<0 || ii>LL->length)
	{
		std::cout << "位置不合法";
		return 0;
	}
	for (size_t j = ii; j < LL->length; j++)
	{
		LL->data[j - 1] = LL->data[j];
	}
	LL->length = LL->length - 1;
	// 把ii之后的元素前移。
	//int k;
	//for (k = ii; k <= LL->length; k++)
	//{
	//	// memcpy(LL->data+k-1,LL->data+k,sizeof(ElemType));  // 采用memcpy是为了支持ee为结构体的情况。
	//	memcpy(&LL->data[k - 1], &LL->data[k], sizeof(ElemType));   // 用数组的形式也可以。
	//}
	return 1;

}
// 删除顺序表LL中头元素，返回值：0-位置ii不合法；1-成功。
int PopFront(PSeqList LL)
{
	return  DeleteElem(LL,1);
}
// 删除顺序表LL中尾元素，返回值：0-位置ii不合法；1-成功。
int PopBack(PSeqList LL)
{
	return  DeleteElem(LL, LL->length);
}

// 在顺序表LL的头结点插入元素ee，返回值：0-失败；1-成功。
int  PushFront(PSeqList LL, ElemType* ee)
{
	return InsertList(LL, 1, ee);
}

// 在顺序表LL的尾结点插入元素ee，返回值：0-失败；1-成功。
int  PushBack(PSeqList LL, ElemType* ee)
{
	return InsertList(LL, LL->length+1, ee);
}

// 采用归并的方法，将两个升序的顺序表La和Lb，合并成一个升序的顺序表Lc。
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc)
{
	if (La == nullptr || Lb == nullptr || Lc == nullptr)
	{
		std::cout << "表La，Lb，Lc至少有一个不存在\n";
		return 0;
	}
	if (MAXSIZE < La->length + Lb->length)
	{
		std::cout << "表Lc的长度不够、\n";
		return -1;
	}
	unsigned int istartla = 0, istartlb = 0, istartlc = 0;//表第一个元素的位置；
	while (istartla<La->length&&istartlb<Lb->length)//同时满足la,lb都还有元素
	{
		if (La->data[istartla] < Lb->data[istartlb ])
		{
			Lc->data[istartlc++] = La->data[istartla++];
		}
		else
		{
			Lc->data[istartlc++] = Lb->data[istartlb++];
		}
	}
	// 把La其它的元素追加到Lc中。
	while (istartla < La->length)
	{
		Lc->data[istartlc++] = La->data[istartla++];//lb已经空
	}
		

	// 把Lb其它的元素追加到Lc中。
	while (istartlb < Lb->length)
	{
		Lc->data[istartlc++] = Lb->data[istartlb++];//la已经空
	}
	Lc->length = La->length + Lb->length;

	return 1;
}
/*数据结构例题*/
//查找最小值元素的位置，并用最后一位元素填补
bool Del_Main(SeqList& L, ElemType& Value)
{
	if (L.length == 0)
	{
		std::cout << "线性表为空" << std::endl;
		return false;
	}
	unsigned int pos = 0;//记录最小值的位置
	Value = L.data[0];//假定第一个元素为最小值
	//遍历整个线性表找到最小值元素的位置
	for (unsigned int i = 0; i < L.length; i++)
	{
		if (L.data[i] < Value)
		{
			Value = L.data[i];//若判断成立则表明，存在比假定第一个元素小的值，更新Value
			pos = i;//更新此时最小值所在的位置
		}
	}
	L.data[pos] = L.data[L.length - 1];//将最后一个元素覆盖掉最小元素
	L.length = L.length - 1;//表长度减1
	return true;//若未找到则由最后一个元素覆盖第一个元素，此时Value则为最小值
}
//元素逆置 
void Reverse(SeqList& L)
{
	ElemType Temp = 0;
	for (unsigned int i = 0; i < L.length / 2; i++)
	{
		Temp = L.data[i];
		L.data[i] = L.data[L.length - 1 - i];
		L.data[L.length - 1 - i] = Temp;
	}
}
//删除表中所有值为X的元素
void Del_X01(SeqList& L, ElemType X)
{
	ElemType k = 0, i = 0;
	for (i; i < L.length; i++)
	{
		if (L.data[i] != X)//不等于X的元素进入if判段,假设此时为第三个表示为不等于x的元素、此时i=4，k=0
		{
			L.data[k] = L.data[i];
				k++;//不等于X的长度+1更新K值的位置为下一次覆盖准备同时也为结尾修改L长度
		}
	}
	L.length = k;
}
//删除表中所有值为X的元素
void Del_X02(SeqList& L, ElemType X)
{
	ElemType k = 0, i = 0;//K记录等于X的元素个数
	for (i; i < L.length; i++)
	{
		if (L.data[i] == X)
			k++; 
		else
			L.data[i - k] = L.data[i];//前移K个位置
	}
	L.length = L.length - k;
}
//从有序表中删除其值在给定值之间的元素（s<t）
bool Del_range(int s, int t, SeqList& L)
{
	
	int i, j;
	if (s >= t || L.length == 0)//不合法
	{
		return false;
	}	
	for (i = 0; i < L.length && L.data[i] < s; i++)//寻找第一个大于s元素
	{
		;
	}
	if (i >= L.length)//表中没有大于s的元素
		return false;
	for (j = i; j < L.length && L.data[j] <= t; j++)//第一个大于t的元素
	{
		;
	}
	for (; j < L.length; i++, j++)
	{
		L.data[i] = L.data[j];//前移填补元素缺失位置
	}
			
	L.length = i;
	return true;
	

}
//从有序表中删除其值在给定值之间的元素（s<t）
bool Del_s_t(int s, int t, SeqList& L)
{
	int i = 0, k = 0;//k记录表中不在s-t之间的元素个数
	for (i; i < L.length; i++)
	{
		if (L.data[i] >= s && L.data[i] <= t)//查找表中处于s-t之间的元素
		{
			k++;
		}
		else
		{
			L.data[i - k] = L.data[i];//将不在s-t之间的元素前移k个位置，覆盖其在s-t之间的位置
		}
	}//for
	L.length -= k;
	return true;
}

//从有序表中删除所有值重复的元素，使其值各不相同
bool Del_same(SeqList& L)
{
	if (L.length)
		return false;
	int i = 0, j = 1;
	for (i, j; i < L.length; j++)
		if (L.data[i] != L.data[j])
			L.data[++i] = L.data[j];
	L.length = i + 1;
	return true;
}

