#include"SeqQueue.h"

// 初始化一个空队列
void InitSeqQueue(PSeqQueue QQ)
{
	Clear(QQ);
}

// 销毁循环队列QQ。
void DestroyQueue(PSeqQueue QQ)
{
	Clear(QQ);
	return;
}
// 清空循环队列。
void Clear(PSeqQueue QQ)
{
	if (QQ == NULL)return;//检查空指针

	QQ->front = QQ->rear=0;
	memset(QQ->data,0,sizeof(ElemType) * MaxSize);//数组元素清零
}
//判断队列是否为空，空-True，非空-False
bool SeqQueueEmpty(PSeqQueue QQ)
{
	if (QQ == NULL)return false;
	if (QQ->front == QQ->rear)return true;
	else return false;
}

// 元素入队，返回值：0-失败；1-成功。
int InQueue(PSeqQueue QQ, ElemType* ee)
{
	if (QQ == NULL || ee == NULL)return 0;
	if ((QQ->rear + 1) % MaxSize == QQ->front)
	{
		printf("队列已满"); return 0;
	}
	QQ->data[QQ->rear] = *ee;
	//memcpy(&QQ->data[QQ->rear], ee, sizeof(ElemType));
	QQ->rear = (QQ->rear + 1) % MaxSize;//rear指针往后移+1；
	return 1;
}

// 元素出队，返回值：0-失败；1-成功。
int OutQueue(PSeqQueue QQ, ElemType* ee)
{
	if (QQ == NULL || ee == NULL)return 0;
	if (SeqQueueEmpty(QQ) == true)return 0;
	*ee = QQ->data[QQ->front];
	//memcpy(ee, &QQ->data[QQ->front], sizeof(ElemType));
	return 1;
}

// 求循环队列的长度，返回值：>=0-队列QQ元素的个数。
int  Length(PSeqQueue QQ)
{
	if (QQ == NULL) return 0;  // 检查空指针。

  return (QQ->rear-QQ->front+MaxSize)%MaxSize;
}


// 判断循环队列是否已满，返回值：1-已满，0-未满或失败。
int IsFull(PSeqQueue QQ)
{
	
  if (QQ == NULL) return 0;   // 检查空指针。

  if ( ((QQ->rear+1)%MaxSize) == QQ->front) return 1;

  return 0;
}

// 打印循环队列中全部的元素。
void PrintQueue(PSeqQueue QQ)
{
	if (QQ == NULL) return;   // 检查空指针。

  if (SeqQueueEmpty(QQ) == true) { printf("队列为空。\n"); return; }

  int kk,qlen=Length(QQ);
  for (kk = 0; kk < qlen; kk++)
  {
    // 用数组的下标访问。
    printf("data[%d],value=%c\n",(QQ->front+kk)%MaxSize,QQ->data[(QQ->front+kk)%MaxSize]);     
   
    // 采用指针运算也可以。
    // printf("data[%d],value=%d\n",(QQ->front+kk)%MAXSIZE,*(QQ->data+(QQ->front+kk)%MAXSIZE));
  }

}

// 获取队头元素，返回值：0-失败；1-成功。
// 只查看队头元素的值，元素不出队。
int GetHead(PSeqQueue QQ, ElemType* ee)
{
	if ( (QQ == NULL) || (ee == NULL) ) return 0;   // 检查空指针。

  if (SeqQueueEmpty(QQ) == true) { printf("队列为空。\n"); return 0; }

  memcpy(ee,&QQ->data[QQ->front],sizeof(ElemType));  // 用数组的下标访问。
  // memcpy(ee,QQ->data+QQ->front,sizeof(ElemType));    // 采用指针运算也可以。

  return 1;
}