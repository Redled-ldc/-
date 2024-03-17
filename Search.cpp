#include"Search.h"
//一、顺序查找
int Search_Seq(STable st, ElemType key)
{
	st.Pelem[0]=key;//引入哨兵的目的使循环内不必判断数组是否会越界，避免了不必要的判断语句从而提高程序允许的效率
	int i=0;
	for (int i = st.len - 1; st.Pelem[i] != key; i--)
	return i;
}
//二、折半查找
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
	return -1;//查找失败
}