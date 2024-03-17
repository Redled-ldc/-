#include"LinkStack.h"
#include<Stack>
// ��ջSS�ĳ�ʼ������������ͷ��㣬����ͷ���ĵ�ַ��
SNode* InitStack()
{
	SNode* Head = (SNode*)malloc(sizeof(SNode));//����ͷ���
	if (Head == NULL)//�������ڴ�
	{
		printf("�ڴ����ʧ�ܣ�ջ�ĳ�ʼ��ʧ��");
		return NULL;
	}
	Head->next = NULL;//��ͷ������һ�����Ϊ�գ���ʱ�����ڣ�
	return Head;//���ط����ͷ���
}
// ������ջSS��
void DestroyStack(LinkStack SS)
{
	SNode* Temp = NULL;
	//����ͷŽ�㲢��ָ����Ϊ��
	while (SS!=NULL)
	{
		Temp = SS->next;//Temp����SS����һ�����
		free(SS);//�ͷŵ�ǰ���
		SS = Temp;//�������ƶ�
	}
	SS = NULL;
	return;
}
//�����ջSS
void Clear(LinkStack SS)
{
	//�ͷų���ͷ���֮��Ľ��
	SNode* Temp1 = NULL, * Temp2 = SS->next;//Temp2ָ��ͷ����ĵ�һ����� 
	while (Temp2!=NULL)
	{
		Temp1 = Temp2->next;
		free(Temp2);
		Temp2 = Temp1;
	}
	SS->next = NULL;
	return;
}
// Ԫ����ջ������ֵ��0-ʧ�ܣ�1-�ɹ���
int Push(LinkStack SS, ElemType* ee)
{
	if (SS == NULL || ee == NULL)return 0;
	SNode* StackNode = (SNode*)malloc(sizeof(SNode));
	if (StackNode == NULL)
	{
		printf("�ڴ�������ջʧ��");
		return 0;
	}
	memcpy(&StackNode->data, ee, sizeof(ElemType));
	StackNode->next = SS->next;//ͷ�巨
	SS->next = StackNode;
	return 1;
}
//Ԫ�س�ջ������ֵ��0 - ʧ�ܣ�1 - �ɹ���
int Pop(LinkStack SS, ElemType* ee)
{
	if ((SS == NULL) || (ee == NULL)) return 0;  // ����ָ�롣
	if (SS->next == NULL) { printf("ջΪ�ա�\n"); return 0; }
	SNode* Temp = SS->next;
	memcpy(ee, &Temp->data, sizeof(ElemType));
	SS->next = Temp->next;//ɾ����һ�����
	Temp = NULL;
	free(Temp);
	return 1;
}
// ����ջ�ĳ��ȣ�����ֵ��ջSS��Ԫ�صĸ�����
int  Length(LinkStack SS)
{
	
	if (SS == NULL) return 0; // ����ָ�롣

	SNode* pp = SS->next;  // ͷ��㲻�㣬�ӵ�1����㿪ʼ��

	int length = 0;

	while (pp != NULL) { pp = pp->next; length++; }

	return length;
}
// �ж���ջ�Ƿ�Ϊ�գ�����ֵ��1-�գ�0-�ǿջ�ʧ�ܡ�
int  IsEmpty(LinkStack SS)
{
	if (SS == NULL) return 0;   // ����ָ�롣
	if (SS->next == NULL) return 1;
	return 0;
}
//��ӡ��ջ��ȫ����Ԫ�ء�
void PrintStack(LinkStack SS)
{
	if (IsEmpty(SS) == 1) return;
	int kk = 0;
	SNode* pp = SS->next;  // �ӵ�1����㿪ʼ��

	while (pp != NULL)
	{
		printf("SS[%d],value=%c\n", kk++, pp->data);
		pp = pp->next;
	}
	return;
}
// ��ȡջ��Ԫ�أ�����ֵ��0-ʧ�ܣ�1-�ɹ���
// ֻ�鿴ջ��Ԫ�ص�ֵ��Ԫ�ز���ջ��
int GetTop(LinkStack SS, ElemType* ee)
{
	if ((SS == NULL) || (ee == NULL)) return 0;  // ����ָ�롣

	if (SS->next == NULL) { printf("ջΪ�ա�\n"); return 0; }

	memcpy(ee, &SS->next->data, sizeof(ElemType));

	return 1;
}
//����ƥ��
int Match_Brackets()
{
	char ch, x;
	std::stack<char> S;  
	scanf("%c",&ch);
	while (ch!=13)//���򵽻س�����
	{
		if ((ch == '(') || (ch == '[')) S.push(ch);
		else if(ch==']')
		{
			x = S.top();
			S.pop();
			if (x != '[')
			{
				std::cout << "ƥ��ʧ��";
				return false;
			}
		}
		else if (ch == ')')
		{
			x = S.top();
			S.pop();
			if (x != '(')
			{
				std::cout << "ƥ��ʧ��";
				return false;
			}
		}
	}//while
	if (!S.empty())
	{
		std::cout << "����������ƥ��";
		return false;
	}
	else return true;
}
//����ת��
int conversation(int n,int d)
{
	std::stack<int> S;
	int k;
	while (n>0)
	{
		k = n % d;
		S.push(k);
		n = n / d;
	}
	while (!S.empty())
	{
		std::cout << S.top();
		S.pop();
	}
}