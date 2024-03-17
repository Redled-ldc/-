#include"Array.h"

// ˳���LL�ĳ�ʼ��������
void InitList(PSeqList  LL)
{
	ClearList(LL);
}
// ��˳���ĳ��ȣ�����ֵ��>=0-��LLԪ�صĸ�����
int  LengthList(PSeqList LL)
{
	if (LL == nullptr)
		return 0;
	return LL->length;
}
// ����˳���LL��
void DestroyList(PSeqList LL)
{
	return;
}
 //��˳���LL�ĵ�ii��λ�ò���Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  InsertList(PSeqList LL, unsigned int ii, ElemType *ee)
{
	if (LL == nullptr || ee ==nullptr) return 0;
	if (LL->length >= MAXSIZE)
	{
		std::cout << "˳�������������ʧ��";
			return 0;
	}
	if (ii < 1 || ii>LL->length+1)
	{
		std::cout << "����λ�ò��Ϸ�";
		return 0;
	}
	for (unsigned int j = LL->length; j >=ii; j--)
	{
		LL->data[j] = LL->data[j-1];
	}
	LL->data[ii-1] = *ee;//��Ԫ�ز��뵽��ii��λ�ã�
	LL->length = LL->length + 1;
	return 1;
	
}
 
//int InsertList1(PSeqList LL, unsigned int ii, ElemType* ee)
//{
//	if ((LL == NULL) || (ee == NULL)) return 0;   // ����ָ�롣
//
//	if (LL->length >= MAXSIZE)
//	{
//		printf("˳������������ܲ��롣\n"); return 0;
//	}
//
//	// �жϲ���λ���Ƿ�Ϸ�
//	if ((ii < 1) || (ii > LL->length + 1))
//	{
//		printf("����λ�ã�%d�����Ϸ���Ӧ���ڣ�%d-%d��֮�䡣\n", ii, 1, LL->length + 1); return 0;
//	}
//
//	// ע�⣬Ԫ�غ���ֻ����ѭ��������������ע�͵��ķ�������Ԫ���ǽṹ��ʱ�����·������ȶ���
//	// if ( ii < LL->length+1)
//	//    memcpy(LL->data+ii,LL->data+ii-1,(LL->length-ii+1)*sizeof(ElemType));
//
//	// ��ii��ii֮���Ԫ�غ��ơ�
//	 unsigned int kk;
//	for (kk = LL->length; kk >= ii; kk--)
//	{
//		// memcpy(LL->data+kk,LL->data+kk-1,sizeof(ElemType));  // ����memcpy��Ϊ��֧��eeΪ�ṹ��������
//		memcpy(&LL->data[kk], &LL->data[kk - 1], sizeof(ElemType));  // ���������ʽҲ���ԡ�
//	}
//
//	//memcpy(LL->data+ii-1,ee,sizeof(ElemType));  // ����memcpy��Ϊ��֧��eeΪ�ṹ��������
//	memcpy(&LL->data[ii - 1], ee, sizeof(ElemType));  // ���������ʽҲ���ԡ�
//	LL->length++;       // ��ĳ��ȼ�1��
//
//	return 1;
//}
// ���˳���
void ClearList(PSeqList LL)
{
	if (LL == NULL) return;  // ����ָ�롣
	LL->length = 0;  // ����Ϊ0��
	memset(LL->data, 0, sizeof(ElemType) * MAXSIZE);  // ����Ԫ����0��
}
// ��ȡ˳����е�ii��Ԫ�ص�ֵ�������ee�У�����ֵ��0-ʧ�ܣ�1-�ɹ���
int  GetElem(PSeqList LL, unsigned int ii, ElemType* ee)
{
	if (LL == nullptr || ee ==nullptr)return 0;//����ָ��
	if (ii<1 || ii>LL->length - 1) return 0;//���λ�úϷ���
	//memcpy(ee, LL->data+ii-1, sizeof(ElemType) * MAXSIZE);
	//std::cout << "������GetElem����";
	memcpy(ee, &LL->data[ii-1] - 1, sizeof(ElemType) * MAXSIZE);
	return 1;
}

// �ж�˳����Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(PSeqList LL)
{
	if (LL->length == 0) return 1;
	return 0;
}
// ��ӡ˳�����ȫ����Ԫ�ء�
void PrintList(PSeqList LL)
{
	if (LL == nullptr||LL->length==0)return;

	/*for (int ii = 0, len = LL->length; ii < len / 2; ii++)   // ���ȷ��ѭ���ı߽磿�ñ�����������֤����Ҫ���ġ�
	{
		// ��������������Ԫ�ص�ֵ��str[ii]��str[len-1-ii]
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



// ����ee��˳���LL�е�λ�ã�����ֵ��0-Ԫ��ee�ڱ�LL�в����ڣ�>0Ԫ��ee�ڱ�LL�е�λ�á�
int  LocateElem(PSeqList LL, ElemType* ee)
{
	if (LL == nullptr || ee == nullptr)return 0;
	for (unsigned int i = 0; i < LL->length; i++)
	{
		if (LL->data[i] == (*ee))
			return i + 1;
	}
}

// ɾ��˳���LL�еĵ�ii��Ԫ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int  DeleteElem(PSeqList LL, unsigned int ii)
{	
	if (LL == nullptr) return 0;
	if (ii<0 || ii>LL->length)
	{
		std::cout << "λ�ò��Ϸ�";
		return 0;
	}
	for (size_t j = ii; j < LL->length; j++)
	{
		LL->data[j - 1] = LL->data[j];
	}
	LL->length = LL->length - 1;
	// ��ii֮���Ԫ��ǰ�ơ�
	//int k;
	//for (k = ii; k <= LL->length; k++)
	//{
	//	// memcpy(LL->data+k-1,LL->data+k,sizeof(ElemType));  // ����memcpy��Ϊ��֧��eeΪ�ṹ��������
	//	memcpy(&LL->data[k - 1], &LL->data[k], sizeof(ElemType));   // ���������ʽҲ���ԡ�
	//}
	return 1;

}
// ɾ��˳���LL��ͷԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int PopFront(PSeqList LL)
{
	return  DeleteElem(LL,1);
}
// ɾ��˳���LL��βԪ�أ�����ֵ��0-λ��ii���Ϸ���1-�ɹ���
int PopBack(PSeqList LL)
{
	return  DeleteElem(LL, LL->length);
}

// ��˳���LL��ͷ������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushFront(PSeqList LL, ElemType* ee)
{
	return InsertList(LL, 1, ee);
}

// ��˳���LL��β������Ԫ��ee������ֵ��0-ʧ�ܣ�1-�ɹ���
int  PushBack(PSeqList LL, ElemType* ee)
{
	return InsertList(LL, LL->length+1, ee);
}

// ���ù鲢�ķ����������������˳���La��Lb���ϲ���һ�������˳���Lc��
int MergeList(PSeqList La, PSeqList Lb, PSeqList Lc)
{
	if (La == nullptr || Lb == nullptr || Lc == nullptr)
	{
		std::cout << "��La��Lb��Lc������һ��������\n";
		return 0;
	}
	if (MAXSIZE < La->length + Lb->length)
	{
		std::cout << "��Lc�ĳ��Ȳ�����\n";
		return -1;
	}
	unsigned int istartla = 0, istartlb = 0, istartlc = 0;//���һ��Ԫ�ص�λ�ã�
	while (istartla<La->length&&istartlb<Lb->length)//ͬʱ����la,lb������Ԫ��
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
	// ��La������Ԫ��׷�ӵ�Lc�С�
	while (istartla < La->length)
	{
		Lc->data[istartlc++] = La->data[istartla++];//lb�Ѿ���
	}
		

	// ��Lb������Ԫ��׷�ӵ�Lc�С�
	while (istartlb < Lb->length)
	{
		Lc->data[istartlc++] = Lb->data[istartlb++];//la�Ѿ���
	}
	Lc->length = La->length + Lb->length;

	return 1;
}
/*���ݽṹ����*/
//������СֵԪ�ص�λ�ã��������һλԪ���
bool Del_Main(SeqList& L, ElemType& Value)
{
	if (L.length == 0)
	{
		std::cout << "���Ա�Ϊ��" << std::endl;
		return false;
	}
	unsigned int pos = 0;//��¼��Сֵ��λ��
	Value = L.data[0];//�ٶ���һ��Ԫ��Ϊ��Сֵ
	//�����������Ա��ҵ���СֵԪ�ص�λ��
	for (unsigned int i = 0; i < L.length; i++)
	{
		if (L.data[i] < Value)
		{
			Value = L.data[i];//���жϳ�������������ڱȼٶ���һ��Ԫ��С��ֵ������Value
			pos = i;//���´�ʱ��Сֵ���ڵ�λ��
		}
	}
	L.data[pos] = L.data[L.length - 1];//�����һ��Ԫ�ظ��ǵ���СԪ��
	L.length = L.length - 1;//���ȼ�1
	return true;//��δ�ҵ��������һ��Ԫ�ظ��ǵ�һ��Ԫ�أ���ʱValue��Ϊ��Сֵ
}
//Ԫ������ 
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
//ɾ����������ֵΪX��Ԫ��
void Del_X01(SeqList& L, ElemType X)
{
	ElemType k = 0, i = 0;
	for (i; i < L.length; i++)
	{
		if (L.data[i] != X)//������X��Ԫ�ؽ���if�ж�,�����ʱΪ��������ʾΪ������x��Ԫ�ء���ʱi=4��k=0
		{
			L.data[k] = L.data[i];
				k++;//������X�ĳ���+1����Kֵ��λ��Ϊ��һ�θ���׼��ͬʱҲΪ��β�޸�L����
		}
	}
	L.length = k;
}
//ɾ����������ֵΪX��Ԫ��
void Del_X02(SeqList& L, ElemType X)
{
	ElemType k = 0, i = 0;//K��¼����X��Ԫ�ظ���
	for (i; i < L.length; i++)
	{
		if (L.data[i] == X)
			k++; 
		else
			L.data[i - k] = L.data[i];//ǰ��K��λ��
	}
	L.length = L.length - k;
}
//���������ɾ����ֵ�ڸ���ֵ֮���Ԫ�أ�s<t��
bool Del_range(int s, int t, SeqList& L)
{
	
	int i, j;
	if (s >= t || L.length == 0)//���Ϸ�
	{
		return false;
	}	
	for (i = 0; i < L.length && L.data[i] < s; i++)//Ѱ�ҵ�һ������sԪ��
	{
		;
	}
	if (i >= L.length)//����û�д���s��Ԫ��
		return false;
	for (j = i; j < L.length && L.data[j] <= t; j++)//��һ������t��Ԫ��
	{
		;
	}
	for (; j < L.length; i++, j++)
	{
		L.data[i] = L.data[j];//ǰ���Ԫ��ȱʧλ��
	}
			
	L.length = i;
	return true;
	

}
//���������ɾ����ֵ�ڸ���ֵ֮���Ԫ�أ�s<t��
bool Del_s_t(int s, int t, SeqList& L)
{
	int i = 0, k = 0;//k��¼���в���s-t֮���Ԫ�ظ���
	for (i; i < L.length; i++)
	{
		if (L.data[i] >= s && L.data[i] <= t)//���ұ��д���s-t֮���Ԫ��
		{
			k++;
		}
		else
		{
			L.data[i - k] = L.data[i];//������s-t֮���Ԫ��ǰ��k��λ�ã���������s-t֮���λ��
		}
	}//for
	L.length -= k;
	return true;
}

//���������ɾ������ֵ�ظ���Ԫ�أ�ʹ��ֵ������ͬ
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

