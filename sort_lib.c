/***************************************************************************
 * @file: sort_lib.c
 *
 * Description: Chapter 3: sorting
 *
 * $Revision: #1 $
 * $Data: 2020/07/04 $
 * $Author: Kevin Yang
 *
 ***************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include "sort_lib.h"

SqList gSqList;

/**
 * @brief swap data
 *
 * @param[in] L list point
 * @param[in] i index
 * @param[in] j index
 */
void swapData(SqList *L, int i, int j)
{
	int tempData = L->value[i];
	L->value[i] = L->value[j];
	L->value[j] = tempData;
}

void CreateList(void)
{
	int dataCnt = 0;
	printf("1. Please enter List length(MAX is 10): \n");
	scanf("%d\n", gSqList.length);
	while (gSqList.length > MAX_LIST_SIZE)
	{
		printf("Error input length, reEnter:\n");
		scanf("%d\n", gSqList.length);
	}

	printf("2. Please enter List %d number data: \n", gSqList.length);
	while (dataCnt++ < gSqList.length)
	{
		scanf("%d\n", gSqList.value[dataCnt]);
	}
	printf("End data input processing\n");
	printf("Unsorted list is \n");
	dataCnt = 0;
	while (dataCnt++ < gSqList.length)
	{
		printf("%d\n", gSqList.value[dataCnt]);
	}
}

/**
 * @brief bubble sorting 0
 *
 * @param[in] L list point
 */
void bubbleSort0(SqList* L)
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->value[j] < L->value[i])
			{
				swapData(L, i, j);
			}
		}
	}
}

/**
 * @brief bubble sorting 1
 *
 * @param[in] L list point
 */
void bubbleSort1(SqList *L)
{
	int i, j;
	for (i = 1; i < L->length; i++)
	{
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->value[j + 1] < L->value[j])
			{
				swapData(L, j, j + 1);
			}
		}
	}
}

/**
 * @brief bubble sorting 2
 *
 * @param[in] L list point
 */
void bubbleSort2(SqList* L)
{
	int i, j;
	bool isSorted = true;
	for (i = 1; i < L->length; i++)
	{
		isSorted = true;
		for (j = L->length - 1; j >= i; j--)
		{
			if (L->value[j + 1] < L->value[j])
			{
				swapData(L, j, j + 1);
				isSorted = false;
			}
		}
		if (isSorted)
		{
			break;
		}
	}
}

/**
 * @brief select sorting
 *
 * @param[in] L list point
 */
void selectSort(SqList* L)
{
	int i, j, minIndex;
	for (i = 1; i < L->length; i++)
	{
		minIndex = i;
		for (j = i + 1; j <= L->length; j++)
		{
			if (L->value[j] < L->value[minIndex])
			{
				minIndex = j;
			}
		}
		if (i != minIndex)
		{
			swapData(L, i, minIndex);
		}
	}
}

/**
 * @brief insert sorting
 *
 * @param[in] L list point
 */
void insertSort(SqList* L)
{
	int i, j;
	for (i = 2; i < L->length; i++)
	{
		if (L->value[i] < L->value[i - 1])
		{
			L->value[0] = L->value[i];
			for (j = i - 1; L->value[j] < L->value[0]; j--)
			{
				L->value[j + 1] = L->value[j];
			}
			L->value[j + 1] = L->value[0];
		}
	}
}

/**
 * @brief shell sorting
 *
 * @param[in] L list point
 */
void shellSort(SqList* L)
{
	int i, j;
	int increment = L->length;
	do 
	{
		increment = increment / 3 + 1;   /* increment list */
		for (i = increment + 1; i <= L->length; i++)
		{
			L->value[0] = L->value[i];
			if (L->value[0] < L->value[i - increment])
			{
				for (j = i - increment; L->value[0] > L->value[j] ; j -= increment)
				{
					L->value[j + increment] = L->value[j];
				}
				L->value[j + increment] = L->value[0];
			}
		}
	} while (increment > 1);
}

/**
 * @brief make list from index s to index m to big heap
 *
 * @param[in] L list point
 * @param[in] s start index
 * @param[in] m end index
 */
void heapAdjust(SqList* L, int s, int m)
{
	int j, temp;
	temp = L->value[s];
	for (j = 2*s; j <= m; j*=2)
	{
		if (j < m && L->value[j] < L->value[j+1])
		{
			++j;
		}
		if (temp >= L->value[j])
		{
			break;
		}
		L->value[s] = L->value[j];
		s = j;
	}
	L->value[s] = temp;
}

/**
 * @brief heap sorting
 *
 * @param[in] L list point
 */
void headSort(SqList* L)
{
	int i;
	for (i = L->length/2; i > 0; i--)
	{
		heapAdjust(L, i, L->length);
	}
	for (i = L->length; i > 1; i--)
	{
		swapData(L, 1, i);
		heapAdjust(L, 1, i - 1);
	}
}

/**
 * @brief merge to list SR[i..m] and SR[m+1..n] to SR[i..n]
 *
 * @param[in] SR[] source list
 * @param[in] TR[] destination list
 * @param[in] i start index
 * @param[in] m middle index
 * @param[in] n end list
 */
void merge(int SR[], int TR[], int i, int m, int n)
{
	int j, k, l;
	for (j = m+1, k = i; i <= m && j <= n; k++)
	{
		if (SR[i] < SR[j])
		{
			TR[k] = SR[i++];
		}
		else
		{
			TR[k] = SR[j++];
		}
	}

	if (i <= m)
	{
		for (l = 0; l <= m-i; l++)
		{
			TR[k + l] = SR[i + l];
		}
	}
	
	if (j <= n)
	{
		for (l = 0; l <= n-j; l++)
		{
			TR[k + l] = SR[j + l];
		}
	}
}

/**
 * @brief merge sorting for original SR[s..t] to TR1[s..t]
 *
 * @param[in] SR[] source list
 * @param[in] TR1[] destination list
 * @param[in] s start index
 * @param[in] t end list
 */
void mSort(int SR[], int TR1[], int s, int t)
{
	int m;
	int TR2[MAX_LIST_SIZE];
	if (s == t)
	{
		TR1[s] = SR[s];
	}
	else
	{
		m = (s + t) / 2;
		mSort(SR, TR2, s, m);
		mSort(SR, TR2, m + 1, t);
		merge(TR2, TR1, s, m, t);
	}
}

void mergeSort(SqList *L)
{
	mSort(L->value, L->value, 1, L->length);
}

/*
 * @brief Partition sequence list to two parts
 *
 * @param[in] L sequence list point
 * @param[in] low low index of waiting for partition list
 * @param[in] high high index of waiting for partition list
 *
 * @return pivot index
 */
int partition(SqList* L, int low, int high)
{
	int pivotkey;
	pivotkey = L->value[0];

	while (low < high)
	{
		while (low < high && L->value[high] >= pivotkey)
		{
			high--;
		}
		swapData(L, low, high);
		while (low < high && L->value[low] <= pivotkey)
		{
			low--;
		}
		swapData(L, low, high);
	}
	return low;
}

/**
 * @brief quick sort
 *
 * @param[in] L sequence list point
 * @param[in] low low index of waiting for sorting
 * @param[in] high high index of waiting for sorting
 */
void qSort(SqList* L, int low , int high)
{
	int povit;
	if (low < high)
	{
		povit = partition(L, low, high);
		qSort(L, 1, povit - 1);
		qSort(L, povit + 1, high);
	}
}
