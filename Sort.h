#pragma once
#include"Array.h"
#include"Linklist.h"
//直接插入排序_顺序存储实现
void InsertSort(SeqList& arr);

//直接插入排序_链表存储实现
void Insertsort(LinkList& LL);

//折半插入存储—只能顺序存储
void Binary_InsertSort(SeqList& arr);

//希尔排序——部分有序逼近到全局有序
void Shellsort(SeqList& arr);
//冒泡排序
void Bubblesort(SeqList& arr);
//快速排序
void Quicksort(SeqList& arr,int low,int high);
//简单选择排序
void Selectsort(SeqList& arr);
//堆排序
void Heapsort(SeqList& arr);
//归并排序
void Mergesort(SeqList& arr, int low,int high);
//基数排序
void Radixsort(SeqList& arr);