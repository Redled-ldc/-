#include"Search.h"
//һ��˳�����
int Search_Seq(STable st, ElemType key)
{
	st.Pelem[0]=key;//�����ڱ���Ŀ��ʹѭ���ڲ����ж������Ƿ��Խ�磬�����˲���Ҫ���ж����Ӷ���߳��������Ч��
	int i=0;
	for (int i = st.len - 1; st.Pelem[i] != key; i--)
	return i;
}
//�����۰����
int Binary_Search(STable st, ElemType key)
{
	int Low = 0, Hight = st.len - 1, mid = 0;
	while (Low<=Hight)
	{
		mid = (Low + Hight) / 2;
		if (st.Pelem[mid] == key)
			return mid;
		else if (st.Pelem[mid] < key)
			Low = mid + 1;
		else
			Hight = mid - 1;
	}
	return -1;//����ʧ��
}