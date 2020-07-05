/***************************************************************************
 * @file: sort_lib.h
 *
 * Description: Chapter 3: sorting
 *
 * $Revision: #1 $
 * $Data: 2020/07/04 $
 * $Author: Kevin Yang
 *
 ***************************************************************************/

#include <stdio.h>
#include "systemConfig.h"

typedef struct
{
	int value[MAX_LIST_SIZE + 1];
	int length;
}SqList;

void CreateList(int length);