#include"SString.h"
//���ĳ�ʼ��
void InitSting(HString& S)
{
	S.ch = (char*)malloc(sizeof(char)*MAXSIZE);
	S.length = 0;
}

//2.���Ӷ�̬����ĳ���,���Ӵ��ĳ���
void IncreaseSize(HString* S, int len)
{
	char* p = S->ch;
	S->ch = (char*)malloc(sizeof(char) * (MAXSIZE+len));
	if (S->ch != NULL)
	{
		for (int i = 0; i < S->length; i++)
		{
			S->ch[i] = p[i];
		}
		S->length += len;
		free(p);
	}
	
}

//��ֵ����,��t��ֵ��ֵ��s
bool StringAssgin(HString& S, char* T)
{
	int len = strlen((const char*)T);
	if (&S == NULL || len == 0)return false;
	for (int i = 0; i < len; i++)
	{
		S.ch[i] = T[i];
	}
	S.length = len;
	return true;
}

//StrCopy(&T,S)�����Ʋ������ɴ�S���Ƶõ���T,
bool StringCopy(HString& T, HString& S)
{
	if (&T == NULL || (&S == NULL))return false;
	T.ch = S.ch;
	T.length = S.length;
	return true;
}

//�пղ��� StrEmpty(S)���пղ�������SΪ�մ����򷵻�TRUE�����򷵻�FALSE��
bool StringEmpty(const HString& T)
{
	if (T.length == 0)return true;
	else return false;
}

//��ӡ����
void PrintString(HString& S)
{
	if (StringEmpty)return;
	else
	{
		printf("S=%s", S.ch);
	}
}

//������,Concat(&T, S1, S2)�������ӡ���T������S1��S2���Ӷ��ɵ��´�
int StringConnect(HString& T, char* S1, char* S2)
{
	if (&T == NULL || S1 == NULL || S2 == NULL)return 0;
	long long s1_len = strlen(S1);
	long long s2_len = strlen(S2);
	int i = 0, j = 0;
	for (i; i < s1_len; i++)
	{
		T.ch[i] = S1[i];
	}
	for (j=0; j < s2_len;j++)
	{
		T.ch[j + i] = S2[j];
	}
	T.length = s1_len + s2_len;
	return 1;
}

//����ģʽƥ��BF
// ����BF�㷨��������Ŀ�괮sstr��ģʽ��tstr���ֵ�λ�ã��ַ�������ʼλ�ô�0��ʼ��
// ֻҪ��Ŀ�괮sstr���ҵ��˵�һ��ģʽ��tstr�������ͷ��ء�
// �ɹ�����ģʽ��tstr��Ŀ�괮sstr�е�һ�γ��ֵ������±꣬ʧ�ܷ���-1��
int IndexBf(HString& SS1, HString& TS2)
{
	int i = 1, j = 1;
	while (i<SS1.length||j<TS2.length)
	{
		if (SS1.ch[i] == TS2.ch[j])
		{
			++i; ++j;
		}
		else
		{
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > TS2.length)
	{
		return i - TS2.length;
	}
	else
	{
		return 0;
	}
}

//next���鱩�����
void get_next_arr(char* t, int* next)
{
	// next[i]����ⷽ���ǣ��ҵ���t[0]~t[i-1]�Ĺ����ƥ��ǰ׺�ͺ�׺�ĳ���
	next[0] = -1;  // next[0]����Ϊ-1
	next[1] = 0;	 // next[1]�϶���0
	// ֻҪ��ƥ�䴮��û���ף���Ҫ����Ӧλ��next[i]ֵ
	for (int i = 2; t[i] != '\0'; i++)
	{
		int max_len = i - 1;		// �����Ϊi-1
		int len, j;
		for (len = max_len; len >= 1; len--)  // ����������ʼ����
		{
			for (j = 0; j < len; j++)
			{
				if (t[j] != t[j + i - len])  // ֻҪ���κ�һλ����Ӧ��ȣ���ô��ǰlen�Ͳ���������̽��һ��len 
					break;
			}
			// �����һ��ѭ���������˳���������Ӧ����ˣ��ǾͰѵ�ǰ��len����next[i],������������̽��
			if (j == len)
			{
				next[i] = len;
				break;
			}
		}
	   if (len < 1)  // ���len=1�����������������next[i]�϶���0��
		{
			next[i] = 0;
		}

	}
}
//next�ݹ����
void get_next(char* T, int next[])
{
	int i = 1, j = 0;
	next[1] = 0;
	while (i<strlen(T))
	{
		if (j == 0 || T[i] == T[j])
		{
			++i; ++j;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}


// ����ģʽ��tstr��next�������nextval���飬�ַ�������ʼλ�ô�0��ʼ��
// void getnextval(char *tstr,int *next,int *nextval)
void getnextval(char tstr[], int next[], int nextval[])
{
	if ((tstr == 0) || (next == 0) || (nextval == 0)) return;  // �жϿ�ָ�롣

	int tlen = strlen(tstr);  // ģʽ���ĳ��ȡ�

	nextval[0] = -1;   // λ��0ֱ������-1��

	int ii;

	// �ӵ�1��λ�ÿ�ʼɨ�衣
	for (ii = 1; ii < tlen; ii++)
	{
		if (tstr[ii] == tstr[next[ii]])
			nextval[ii] = nextval[next[ii]];
		else
			nextval[ii] = next[ii];
	}
}

// ����kmp�㷨��������Ŀ�괮sstr��ģʽ��tstr���ֵ�λ�ã��ַ�������ʼλ�ô�0��ʼ��
// ֻҪ��Ŀ�괮sstr���ҵ��˵�һ��ģʽ��tstr�������ͷ��ء�
// �ɹ�����ģʽ��tstr��Ŀ�괮sstr�е�һ�γ��ֵ������±꣬ʧ�ܷ���-1��
// int index_kmp(char *sstr,char *tstr)
int IndexKmp(char* SS1, char* TS2,int next[])
{
	int i = 1, j = 1;
	int len_s1 = strlen(SS1);
	int len_s2 = strlen(TS2);
	while (i <len_s1 && j < len_s2)
	{
		if (j==0||SS1[i] == TS2[j])
		{
			++i; ++j;
		}
		else
		{
			j =next[j];
		}
	}
	if (j > len_s2)
	{
		return i - len_s2;
	}
	else
	{
		return 0;
	}
}