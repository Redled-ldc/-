#include"Sort.h"
//ֱ�Ӳ�������_˳��洢
void InsertSort(SeqList& arr)
{
	int i, j,temp;
	for (i = 1; i < arr.length; i++)	//���ν�data[1]~data[n]���뵽ǰ�����������
	{
		if (arr.data[i-1] < arr.data[i])//��a��i���ؼ���С��ǰ��
		{
			temp = arr.data[i];			//��a��i���ؼ��ָ�ֵ��temp
			for (j=i-1;j>=0&&arr.data[j]>temp; j--)//�Ӻ���ǰ��զ������λ��
			{
				arr.data[j + 1] = arr.data[j];//���Ų��������λ��
			}
			arr.data[j+1] = temp;//���Ƶ�����λ��
		}
	}
} 

//ֱ�Ӳ�������_����洢ʵ��
void Insertsort (LinkList& LL)
{
	LinkList back,ordermove,disordermove;//orderָ������������disordermoveָ��δ��������
										//back��disdordermoveָ�Ľ����Ҫ�ƶ�ʱ����֤������
	LinkList front;	//���ƶ�����ǰһ���ĵ�ַ����
	ordermove = LL;
	disordermove = LL->next->next;
	front = LL->next;
	while (disordermove!=NULL)
	{
		while (ordermove->next!=disordermove)
		{
			if ((disordermove->data.no) < (ordermove->next->data.no))
			{
				back = disordermove->next;//back��disordermoveָ�Ľ����Ҫ�ƶ�ʱ����֤������
				disordermove->next = ordermove->next->next;//��disordermove���뵽ordermove֮��
				ordermove->next = disordermove;
				front->next= back;//���Ͽ��ı������������
				disordermove = front;
				break;
			}
			ordermove = ordermove->next;
		}
		front = disordermove;
		disordermove = disordermove->next;//disordermoveһֱ�ƶ�������β��
		ordermove = LL;//ÿ�ζ���ordermove���õ���ͷ
	}
}
//�۰��������
void Binary_InsertSort(SeqList& arr)
{
	int i, j,temp,low,high,mid;
	for (i = 1; i < arr.length; i++)//���ν�data[1]~data[n]���뵽ǰ�����������
	{
		temp = arr.data[i];//��data[i]�ݴ浽temp��
		low = 0, high = i - 1;//��ǰ��0~i-1�����������в����۰���������λ��
		while (low <= high)
		{
			mid = (low+high)/2;
			if (arr.data[mid] > temp)
			{
				high = mid - 1;//����������ӱ����
			}
			else
			{
				low = mid + 1;//�������Ұ��ӱ����,��֤�㷨���ȶ���
			}
		}
		for (j = i - 1; (j>=0&&j >=high + 10); --j)//��low>highʱֹͣ���ң��Ӷ���[low,i-1]λ�õ�Ԫ��ȫ�����ƣ�high+1=low
		{
			arr.data[j + 1] = arr.data[j];
		}
		arr.data[high + 1] = temp;
	}
}
//ϣ�����򡪡���������ƽ���ȫ������
/*�Ƚ��������ָ��Ϊ��������L��i��i+d��i+2d����������i+kd���������ӱ��Ը����ӱ�ֱ���в���������С����d���ظ����ݹ���
ֱ��d=1λ��*/
void Shellsort(SeqList& arr)
{
	int d, i, j;
	for (d=arr.length/2;d>=1;d=d/2)
		for (i = d + 1; i < arr.length; ++i)//��ʼʱi=d+1����ʾָ���һ���ӱ��еĵڶ���Ԫ��
		{
			if (arr.data[i] < arr.data[i - d])//�Ƚϵ�ǰԪ�غ���֮ǰ��һ��Ԫ�صĴ�С
			{
				arr.data[0] = arr.data[i];
				for (j = i - d; j > 0 && arr.data[0] < arr.data[j]; j -= d)
				{
					arr.data[j + d] = arr.data[j];
				}
				arr.data[j + d] = arr.data[0];
			}
		}
}
//ð������
void Swap(unsigned int& a, unsigned int& b)
{
	unsigned temp = a;
	a = b;
	b = temp;
}
void Bubblesort(SeqList& arr)
{
	for (int i = 0; i < arr.length-1; i++)
	{
		bool flag = false;//��ʾ����ð���Ƿ��������ı�־
		for (int j = arr.length - 1; j > i; j++)//һ��ð�ݹ���
		{
			if (arr.data[j]<arr.data[j-1])//��Ϊ�����򽻻�,<��֤�㷨�ȶ�
			{
				Swap(arr.data[j - 1], arr.data[j]);
				flag = true;
			}
		}
		if (false == flag)
		{
			return;
		}
	} 
}

//��������
/*�ڴ�����ı�L��1������n����ѡȡһ��Ԫ��pivot��Ϊ����ͨ��һ�����򽫴�����ı���Ϊ���������Ĳ���L��1������K-1����L��k+1������n����������
ʹ��L��1������K-1���е�����Ԫ��С��pivot����L��k+1������n���е�Ԫ��ȫ�����ڵ���pivot��pivot��������λ��L��k��λ���ϣ�������̳�֮Ϊһ��
�����������һ�λ��֣�Ȼ��ֱ�ݹ�Ķ������ӱ��ظ��������̣�ֱ��ÿ�����ڲ�ֻ��һ��Ԫ�ػ��Ϊֹ*/
int Partition(SeqList& arr, int low, int high)
{
	int pivot = arr.data[0];//����һ��Ԫ����Ϊ��Ŧ���Ա���л���
	while (low<high)
	{
		while (low < high && arr.data[high] >= pivot)//ֱ���ҵ�һ��������Ԫ��С��Ԫ��
			--high;
		arr.data[low] = arr.data[high];//��pivotС��Ԫ�ض��ƶ������
		while (low < high && arr.data[low] <= pivot)//ֱ���ҵ�һ��������Ԫ�ش��Ԫ��
			++low;
		arr.data[high] = arr.data[low];//��pivot���Ԫ�ض��ƶ����Ҷ�
	}
	arr.data[low] = pivot;//��ŦԪ�ط�������λ��
	return low;//����������λ��
}
void Quicksort(SeqList& arr,int low,int high)
{
	if (low < high)
	{
		int pivotpos = Partition(arr, low, high);//�����ӱ�
		Quicksort(arr, low, pivotpos - 1);//�������ӱ�
		Quicksort(arr, pivotpos + 1, high);//�������ӱ�
	}
}
//��ѡ������
/*��i�˴�L��i������n����ѡȡ�ؼ�����С��Ԫ����L��i��������ÿһ�˿���ȷ��һ��Ԫ�ص�λ�ã�����n-1�˱�������*/
void Selectsort(SeqList& arr)
{
	for (int i = 0; i < arr.length - 1; i++)//n-1��
	{
		//��¼��СԪ�ص�λ��
		int min = i;
		//�ڡ�i��n-1����ѡ����С��Ԫ����min�滻
		for (int j = i + 1; j < arr.length; j++)
		{
			//�滻��СԪ�ص�λ��
			if (arr.data[j] < arr.data[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			//����СԪ�ؽ�����arr��i��
			Swap(arr.data[i], arr.data[min]);
		}
	}
}
//������
/*1.L[i]>=L[2i]&&L[i]>=L[2i+1]���������������������
  2.1.L[i]<=L[2i]&&L[i]<=L[2i+1]����������������С����*/
void BuildMaxheap(SeqList& arr)//���������
{
	for (int i=arr.length/2;i>0;i--)//�Ӻ���ǰ���ε������ն˽��
	{
		HeadAdjust(arr,i,arr.length);
	}
}
void HeadAdjust(SeqList& arr,int k,int len)//���������
{
	arr.data[0] = arr.data[k];
	//����Key�ϴ���ӽ������ɸѡ
	for (int i = 2 * k; i <= len; i *= 2)
	{
		//ȡkey�ϴ���ӽڵ���±꣬i<arr.lengthȷ��i����������Һ���
		if (i < len && arr.data[i] < arr.data[i + 1])
		{
			i++;//��ָ��ָ�����ģ���i���Һ���
		}
		//�жϸ�����ֵ�Ƿ�ȸ�����Һ��ӵ�ֵ����
		if (arr.data[0] >= arr.data[i])
		{
			//ɸѡ����
			break;
		}
		else
		{
			//��֮��arr.data[i]��ֵ��������˫�׵�λ��
			arr.data[k] = arr.data[i];
			//�޸�kֵ���Ա��������ɸѡ
			k = i;
		}
	}
	//��ɸѡ������մ洢λ��
	arr.data[k] = arr.data[0];
}
//ÿ�˽��Ѷ�Ԫ�ؼ��뵽�����������У������������е����һ��Ԫ�ؽ�����
void Heapsort(SeqList& arr)
{
	//������ʼ��
	BuildMaxheap(arr);
	//ÿ�ν��Ѷ�Ԫ�غͶѵ�Ԫ�ؽ��н���
	for (int i = arr.length; i > 1; i--)
	{
		//����
		Swap(arr.data[i], arr.data[1]);
		HeadAdjust(arr, 1, i - 1);
	}
}
//�鲢����
/*�������ϵ������ϲ�Ϊһ���µ������*/
void Merge(SeqList& arr, int low, int mid, int high)
{
	//������������B
	int* B = (int*)malloc(arr.length);
	//��arr��Ԫ��ȫ�����Ƶ�B
	int i, j, k;
	for (int k = low; k < high; k++)
		B[k] = arr.data[k];
	//�鲢��СԪ�ط��õ�arr��
	for (i = low, j = mid + 1, k = i; i < mid && j < high; k++)
	{
		if (B[i] <= B[j])
		{
			arr.data[k] = B[i];
			i++;//���Ž�i+1-mid��������Ԫ�غ�j-high�еıȽ�
		}
		else
		{
			arr.data[k] = B[j];
			j++;
		}
	}//for
	//��ʣ�������з���arr
	while (i <= mid) arr.data[k] = B[i++];
	while (j<= high) arr.data[k] = B[j++];
}
void Mergesort(SeqList& arr,int low,int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		//����벿�ֹ鲢
		Mergesort(arr, low, mid);
		//���Ұ벿�ֹ鲢
		Mergesort(arr, mid + 1, high);
		//�鲢
		Merge(arr, low, mid, high);
	}
}
//��������
/*�����ڱȽϺ��ƶ����򣬻��ڹؼ��ָ�λ�Ĵ�С�����������λ���ȷ�-MSD�����ؼ���λȨ�صݼ���㻮�ֳ����ɸ�С�����У�
������������γ�һ���������С�
���λ���ȷ�-LS�����ؼ���λȨ�ص�����㻮�ֳ����ɸ�С�����У�������������γ�һ����������*/
void Radixsort(SeqList& arr)
{

}