#include"Sort.h"
//直接插入排序_顺序存储
void InsertSort(SeqList& arr)
{
	int i, j,temp;
	for (i = 1; i < arr.length; i++)	//依次将data[1]~data[n]插入到前面的已排序列
	{
		if (arr.data[i-1] < arr.data[i])//若a【i】关键字小于前驱
		{
			temp = arr.data[i];			//将a【i】关键字赋值给temp
			for (j=i-1;j>=0&&arr.data[j]>temp; j--)//从后往前查咋待插入位置
			{
				arr.data[j + 1] = arr.data[j];//向后挪出待插入位置
			}
			arr.data[j+1] = temp;//复制到插入位置
		}
	}
} 

//直接插入排序_链表存储实现
void Insertsort (LinkList& LL)
{
	LinkList back,ordermove,disordermove;//order指向已排序链表，disordermove指向未排序链表
										//back当disdordermove指的结点需要移动时，保证不断链
	LinkList front;	//将移动结点的前一个的地址保存
	ordermove = LL;
	disordermove = LL->next->next;
	front = LL->next;
	while (disordermove!=NULL)
	{
		while (ordermove->next!=disordermove)
		{
			if ((disordermove->data.no) < (ordermove->next->data.no))
			{
				back = disordermove->next;//back当disordermove指的结点需要移动时，保证不断链
				disordermove->next = ordermove->next->next;//将disordermove插入到ordermove之后
				ordermove->next = disordermove;
				front->next= back;//将断开的表继续连接起来
				disordermove = front;
				break;
			}
			ordermove = ordermove->next;
		}
		front = disordermove;
		disordermove = disordermove->next;//disordermove一直移动到链表尾部
		ordermove = LL;//每次都将ordermove重置到表头
	}
}
//折半插入排序
void Binary_InsertSort(SeqList& arr)
{
	int i, j,temp,low,high,mid;
	for (i = 1; i < arr.length; i++)//依次将data[1]~data[n]插入到前面的已排序列
	{
		temp = arr.data[i];//将data[i]暂存到temp；
		low = 0, high = i - 1;//从前面0~i-1的已排序序列采用折半查找其插入位置
		while (low <= high)
		{
			mid = (low+high)/2;
			if (arr.data[mid] > temp)
			{
				high = mid - 1;//继续在左半子表查找
			}
			else
			{
				low = mid + 1;//继续在右半子表查找,保证算法的稳定性
			}
		}
		for (j = i - 1; (j>=0&&j >=high + 10); --j)//当low>high时停止查找，从而将[low,i-1]位置的元素全部右移，high+1=low
		{
			arr.data[j + 1] = arr.data[j];
		}
		arr.data[high + 1] = temp;
	}
}
//希尔排序——部分有序逼近到全局有序
/*先将待排序表分割成为若干形如L【i，i+d，i+2d，···，i+kd】的特殊子表，对各个子表分别进行插入排序，缩小增量d，重复上溯过程
直至d=1位置*/
void Shellsort(SeqList& arr)
{
	int d, i, j;
	for (d=arr.length/2;d>=1;d=d/2)
		for (i = d + 1; i < arr.length; ++i)//开始时i=d+1，表示指向第一个子表中的第二个元素
		{
			if (arr.data[i] < arr.data[i - d])//比较当前元素和它之前的一个元素的大小
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
//冒泡排序
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
		bool flag = false;//表示本趟冒泡是否发生交换的标志
		for (int j = arr.length - 1; j > i; j++)//一趟冒泡过程
		{
			if (arr.data[j]<arr.data[j-1])//若为逆序则交换,<保证算法稳定
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

//快速排序
/*在待排序的表L【1···n】中选取一个元素pivot作为枢轴通过一趟排序将待排序的表划分为两个独立的部分L【1···K-1】和L【k+1···n】两个部分
使得L【1···K-1】中的所有元素小于pivot，而L【k+1···n】中的元素全部大于等于pivot，pivot放在最终位置L【k】位置上，这个过程称之为一趟
快速排序或是一次划分，然后分别递归的对两个子表重复上述过程，直至每部分内部只有一个元素或空为止*/
int Partition(SeqList& arr, int low, int high)
{
	int pivot = arr.data[0];//将第一个元素作为枢纽，对表进行划分
	while (low<high)
	{
		while (low < high && arr.data[high] >= pivot)//直到找到一个比枢轴元素小的元素
			--high;
		arr.data[low] = arr.data[high];//比pivot小的元素都移动到左端
		while (low < high && arr.data[low] <= pivot)//直到找到一个比枢轴元素大的元素
			++low;
		arr.data[high] = arr.data[low];//比pivot大的元素都移动到右端
	}
	arr.data[low] = pivot;//枢纽元素放置最终位置
	return low;//返回数轴存放位置
}
void Quicksort(SeqList& arr,int low,int high)
{
	if (low < high)
	{
		int pivotpos = Partition(arr, low, high);//划分子表
		Quicksort(arr, low, pivotpos - 1);//划分左子表
		Quicksort(arr, pivotpos + 1, high);//划分右子表
	}
}
//简单选择排序
/*第i趟从L【i···n】中选取关键字最小的元素于L【i】交换，每一趟可以确认一个元素的位置，经过n-1趟表即可有序*/
void Selectsort(SeqList& arr)
{
	for (int i = 0; i < arr.length - 1; i++)//n-1趟
	{
		//记录最小元素的位置
		int min = i;
		//在【i，n-1】中选出最小的元素与min替换
		for (int j = i + 1; j < arr.length; j++)
		{
			//替换最小元素的位置
			if (arr.data[j] < arr.data[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			//将最小元素交换至arr【i】
			Swap(arr.data[i], arr.data[min]);
		}
	}
}
//堆排序
/*1.L[i]>=L[2i]&&L[i]>=L[2i+1]————————大根堆
  2.1.L[i]<=L[2i]&&L[i]<=L[2i+1]————————小根堆*/
void BuildMaxheap(SeqList& arr)//建立大根堆
{
	for (int i=arr.length/2;i>0;i--)//从后往前依次调整非终端结点
	{
		HeadAdjust(arr,i,arr.length);
	}
}
void HeadAdjust(SeqList& arr,int k,int len)//调整大根堆
{
	arr.data[0] = arr.data[k];
	//沿着Key较大的子结点向下筛选
	for (int i = 2 * k; i <= len; i *= 2)
	{
		//取key较大的子节点的下标，i<arr.length确保i这个结点存在右孩子
		if (i < len && arr.data[i] < arr.data[i + 1])
		{
			i++;//让指针指向更大的，即i的右孩子
		}
		//判断根结点的值是否比更大的右孩子的值更大
		if (arr.data[0] >= arr.data[i])
		{
			//筛选结束
			break;
		}
		else
		{
			//反之则将arr.data[i]的值调整到它双亲的位置
			arr.data[k] = arr.data[i];
			//修改k值，以便继续向下筛选
			k = i;
		}
	}
	//被筛选结点最终存储位置
	arr.data[k] = arr.data[0];
}
//每趟将堆顶元素加入到有序子序列中（与待排序的序列的最后一个元素交换）
void Heapsort(SeqList& arr)
{
	//建立初始堆
	BuildMaxheap(arr);
	//每次将堆顶元素和堆底元素进行交换
	for (int i = arr.length; i > 1; i--)
	{
		//交换
		Swap(arr.data[i], arr.data[1]);
		HeadAdjust(arr, 1, i - 1);
	}
}
//归并排序
/*两个以上的有序表合并为一个新的有序表*/
void Merge(SeqList& arr, int low, int mid, int high)
{
	//借助辅助数组B
	int* B = (int*)malloc(arr.length);
	//将arr的元素全部复制到B
	int i, j, k;
	for (int k = low; k < high; k++)
		B[k] = arr.data[k];
	//归并将小元素放置到arr中
	for (i = low, j = mid + 1, k = i; i < mid && j < high; k++)
	{
		if (B[i] <= B[j])
		{
			arr.data[k] = B[i];
			i++;//接着将i+1-mid子序列中元素和j-high中的比较
		}
		else
		{
			arr.data[k] = B[j];
			j++;
		}
	}//for
	//将剩余子序列放入arr
	while (i <= mid) arr.data[k] = B[i++];
	while (j<= high) arr.data[k] = B[j++];
}
void Mergesort(SeqList& arr,int low,int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		//对左半部分归并
		Mergesort(arr, low, mid);
		//对右半部分归并
		Mergesort(arr, mid + 1, high);
		//归并
		Merge(arr, low, mid, high);
	}
}
//基数排序
/*不基于比较和移动排序，基于关键字各位的大小进行排序，最高位优先法-MSD：按关键字位权重递减逐层划分成若干更小子序列，
进行排序最后形成一个有序序列。
最低位优先法-LS：按关键字位权重递增逐层划分成若干更小子序列，进行排序最后形成一个有序序列*/
void Radixsort(SeqList& arr)
{

}