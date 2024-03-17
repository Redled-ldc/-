#include"SeqQueue.h"

// ��ʼ��һ���ն���
void InitSeqQueue(PSeqQueue QQ)
{
	Clear(QQ);
}

// ����ѭ������QQ��
void DestroyQueue(PSeqQueue QQ)
{
	Clear(QQ);
	return;
}
// ���ѭ�����С�
void Clear(PSeqQueue QQ)
{
	if (QQ == NULL)return;//����ָ��

	QQ->front = QQ->rear=0;
	memset(QQ->data,0,sizeof(ElemType) * MaxSize);//����Ԫ������
}
//�ж϶����Ƿ�Ϊ�գ���-True���ǿ�-False
bool SeqQueueEmpty(PSeqQueue QQ)
{
	if (QQ == NULL)return false;
	if (QQ->front == QQ->rear)return true;
	else return false;
}

// Ԫ����ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int InQueue(PSeqQueue QQ, ElemType* ee)
{
	if (QQ == NULL || ee == NULL)return 0;
	if ((QQ->rear + 1) % MaxSize == QQ->front)
	{
		printf("��������"); return 0;
	}
	QQ->data[QQ->rear] = *ee;
	//memcpy(&QQ->data[QQ->rear], ee, sizeof(ElemType));
	QQ->rear = (QQ->rear + 1) % MaxSize;//rearָ��������+1��
	return 1;
}

// Ԫ�س��ӣ�����ֵ��0-ʧ�ܣ�1-�ɹ���
int OutQueue(PSeqQueue QQ, ElemType* ee)
{
	if (QQ == NULL || ee == NULL)return 0;
	if (SeqQueueEmpty(QQ) == true)return 0;
	*ee = QQ->data[QQ->front];
	//memcpy(ee, &QQ->data[QQ->front], sizeof(ElemType));
	return 1;
}

// ��ѭ�����еĳ��ȣ�����ֵ��>=0-����QQԪ�صĸ�����
int  Length(PSeqQueue QQ)
{
	if (QQ == NULL) return 0;  // ����ָ�롣

  return (QQ->rear-QQ->front+MaxSize)%MaxSize;
}


// �ж�ѭ�������Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqQueue QQ)
{
	
  if (QQ == NULL) return 0;   // ����ָ�롣

  if ( ((QQ->rear+1)%MaxSize) == QQ->front) return 1;

  return 0;
}

// ��ӡѭ��������ȫ����Ԫ�ء�
void PrintQueue(PSeqQueue QQ)
{
	if (QQ == NULL) return;   // ����ָ�롣

  if (SeqQueueEmpty(QQ) == true) { printf("����Ϊ�ա�\n"); return; }

  int kk,qlen=Length(QQ);
  for (kk = 0; kk < qlen; kk++)
  {
    // ��������±���ʡ�
    printf("data[%d],value=%c\n",(QQ->front+kk)%MaxSize,QQ->data[(QQ->front+kk)%MaxSize]);     
   
    // ����ָ������Ҳ���ԡ�
    // printf("data[%d],value=%d\n",(QQ->front+kk)%MAXSIZE,*(QQ->data+(QQ->front+kk)%MAXSIZE));
  }

}

// ��ȡ��ͷԪ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴��ͷԪ�ص�ֵ��Ԫ�ز����ӡ�
int GetHead(PSeqQueue QQ, ElemType* ee)
{
	if ( (QQ == NULL) || (ee == NULL) ) return 0;   // ����ָ�롣

  if (SeqQueueEmpty(QQ) == true) { printf("����Ϊ�ա�\n"); return 0; }

  memcpy(ee,&QQ->data[QQ->front],sizeof(ElemType));  // ��������±���ʡ�
  // memcpy(ee,QQ->data+QQ->front,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

  return 1;
}