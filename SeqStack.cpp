#include"SeqStack.h"
// ˳��ջSS�ĳ�ʼ��������
void InitStack(PSeqStack SS)
{
	if (SS == NULL)return;//����ָ��
	SS->Top = -1;//Topָ��ָ��-1
	memset(SS->data, 0, sizeof(ElemType)*MaxSize);//ջԪ������
}
// Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Push(PSeqStack SS, ElemType* ee)
{
	if (SS == NULL||ee==NULL)//����ָ��
	{
		printf("ָ��Ϊ�գ�ջ��ʼ��ʧ�� \n");
		return 0;
	}
	if (SS->Top == MaxSize - 1)//ջ��
	{
		printf("ջ��������ջʧ�� \n");
		return 0;
	}
	SS->data[++(SS->Top)] = *ee;//Top=Top+1;SS->data[top]=*ee
	return 1;
}
// Ԫ�س�ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Pop(PSeqStack SS, ElemType* ee) 
{
	if (SS == NULL || ee == NULL)//����ָ��
	{
		printf("ָ��Ϊ�գ�ջ��ʼ��ʧ�� \n");
		return 0;
	}
	if (SS->Top == -1)
	{
		printf("ջ�գ���������ջʧ�� \n");
		return 0;
	}
	*ee = SS->data[(SS->Top)--]; //*ee=SS->data[top];Top=Top-1
	return 1;
}
// ��˳��ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ�����
int Length(PSeqStack SS)
{
	if (SS == NULL) return 0;
	return (SS->Top) + 1;
}
// �ж�˳��ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int IsEmpty(PSeqStack SS)
{
	if (SS == NULL)return 0;
	if (SS->Top == -1) return 1;
	return 0;
}
// �ж�˳��ջ�Ƿ�����������ֵ��1-������0-δ����ʧ�ܡ�
int IsFull(PSeqStack SS)
{
	if (SS == NULL)return 0;
	if (SS->Top == MaxSize - 1)return 1;
	return 0;
}
// ��ӡ˳��ջ��ȫ����Ԫ�ء�
void PrintStack(PSeqStack SS)
{
	if (SS == NULL) return;  // ����ָ�롣

	if (SS->Top == -1) { printf("ջΪ�ա�\n"); return; }

	int kk;
	for (kk = 0; kk <= SS->Top; kk++)
	{
		printf("SS[%d],value=%c\n", kk, SS->data[kk]);     // ��������±���ʡ�
		// printf("SS[%d],value=%d\n",kk,*(SS->data+kk));   // ����ָ������Ҳ���ԡ�
	}
}

//��ȡջ��Ԫ�أ�����ֵ��0 - ʧ�ܣ�1 - �ɹ���
// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
int GetTop(PSeqStack SS, ElemType* ee)
{
	if ((SS == NULL) || (ee == NULL)) return 0;  // ����ָ�롣

	if (IsEmpty(SS) == 1) { printf("ջΪ�ա�\n"); return 0; }

	memcpy(ee, &SS->data[SS->Top], sizeof(ElemType));  // ��������±���ʡ�
	// memcpy(ee,SS->data+SS->top,sizeof(ElemType));    // ����ָ������Ҳ���ԡ�

	return 1;
}