#include"SString.h"
//串的初始化
void InitSting(HString& S)
{
	S.ch = (char*)malloc(sizeof(char)*MAXSIZE);
	S.length = 0;
}

//2.增加动态数组的长度,增加串的长度
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

//赋值操作,将t的值赋值给s
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

//StrCopy(&T,S)：复制操作。由串S复制得到串T,
bool StringCopy(HString& T, HString& S)
{
	if (&T == NULL || (&S == NULL))return false;
	T.ch = S.ch;
	T.length = S.length;
	return true;
}

//判空操作 StrEmpty(S)：判空操作。若S为空串，则返回TRUE，否则返回FALSE。
bool StringEmpty(const HString& T)
{
	if (T.length == 0)return true;
	else return false;
}

//打印操作
void PrintString(HString& S)
{
	if (StringEmpty)return;
	else
	{
		printf("S=%s", S.ch);
	}
}

//串连接,Concat(&T, S1, S2)：串联接。用T返回由S1和S2联接而成的新串
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

//串的模式匹配BF
// 采用BF算法，查找在目标串sstr中模式串tstr出现的位置，字符串的起始位置从0开始。
// 只要在目标串sstr中找到了第一个模式串tstr，函数就返回。
// 成功返回模式串tstr在目标串sstr中第一次出现的数组下标，失败返回-1。
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

//next数组暴力求解
void get_next_arr(char* t, int* next)
{
	// next[i]的求解方法是，找到从t[0]~t[i-1]的公共最长匹配前缀和后缀的长度
	next[0] = -1;  // next[0]定义为-1
	next[1] = 0;	 // next[1]肯定是0
	// 只要待匹配串还没到底，都要求相应位的next[i]值
	for (int i = 2; t[i] != '\0'; i++)
	{
		int max_len = i - 1;		// 最长长度为i-1
		int len, j;
		for (len = max_len; len >= 1; len--)  // 从最长的情况开始搜索
		{
			for (j = 0; j < len; j++)
			{
				if (t[j] != t[j + i - len])  // 只要有任何一位不对应相等，那么当前len就不成立，试探下一个len 
					break;
			}
			// 如果上一个循环是正常退出，即都对应相等了，那就把当前的len赋给next[i],并不再往下试探了
			if (j == len)
			{
				next[i] = len;
				break;
			}
		}
	   if (len < 1)  // 如果len=1的情况都不成立，那next[i]肯定是0了
		{
			next[i] = 0;
		}

	}
}
//next递归求解
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


// 根据模式串tstr和next数组计算nextval数组，字符串的起始位置从0开始。
// void getnextval(char *tstr,int *next,int *nextval)
void getnextval(char tstr[], int next[], int nextval[])
{
	if ((tstr == 0) || (next == 0) || (nextval == 0)) return;  // 判断空指针。

	int tlen = strlen(tstr);  // 模式串的长度。

	nextval[0] = -1;   // 位置0直接填入-1。

	int ii;

	// 从第1个位置开始扫描。
	for (ii = 1; ii < tlen; ii++)
	{
		if (tstr[ii] == tstr[next[ii]])
			nextval[ii] = nextval[next[ii]];
		else
			nextval[ii] = next[ii];
	}
}

// 采用kmp算法，查找在目标串sstr中模式串tstr出现的位置，字符串的起始位置从0开始。
// 只要在目标串sstr中找到了第一个模式串tstr，函数就返回。
// 成功返回模式串tstr在目标串sstr中第一次出现的数组下标，失败返回-1。
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