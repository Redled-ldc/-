#pragma once
#include"Array.h"
#include"Linklist.h"
//ֱ�Ӳ�������_˳��洢ʵ��
void InsertSort(SeqList& arr);

//ֱ�Ӳ�������_����洢ʵ��
void Insertsort(LinkList& LL);

//�۰����洢��ֻ��˳��洢
void Binary_InsertSort(SeqList& arr);

//ϣ�����򡪡���������ƽ���ȫ������
void Shellsort(SeqList& arr);
//ð������
void Bubblesort(SeqList& arr);
//��������
void Quicksort(SeqList& arr,int low,int high);
//��ѡ������
void Selectsort(SeqList& arr);
//������
void Heapsort(SeqList& arr);
//�鲢����
void Mergesort(SeqList& arr, int low,int high);
//��������
void Radixsort(SeqList& arr);