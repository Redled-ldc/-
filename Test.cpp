#include"Array.h"
#include<cstring>
int main()
{
	SeqList LL;
	InitList(&LL);
	ElemType arr[7] = { 1,3,6,8,9,10,19 };
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InsertList(&LL, i + 1, &arr[i]) == 0)
			printf("²åÈëÊ§°Ü");

	}
	PrintList(&LL);
	printf("~~~~~~~~~~~~~~~~~~~~\n");
	PrintList(&LL);
}

