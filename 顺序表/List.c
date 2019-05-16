#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"
//初始化
void SeqListInit(PSeqList *ps)
{
	assert(ps!= NULL);
	ps->capacity = 20;
	ps->array = (int *)malloc(sizeof(DataType)*ps->capacity);
	ps->size = 0;
}
//清除
void SeqListDestroy(PSeqList *ps)
{
	assert(ps);
	assert(ps->array);
	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

//尾插
void SeqListPushBack(PSeqList *ps, DataType data)
{
	ps->array[ps->size] = data;
	ps->size++;
}
//尾删
void SeqListPopBack(PSeqList *ps)
{
	assert(ps->size > 0);
	ps->size--;
}

//头插
void SeqListPushFront(PSeqList *ps, DataType data)
{
	for (int i=ps->size;i>=1;i--)
	{
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[0] = data;
	ps->size++;
}
//头删
void SeqListPopFront(PSeqList *ps)
{
	assert(ps->size > 0);
	for (int i=0;i<ps->size-1;i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

// 任意位置插入 
void SeqListInsert(PSeqList *ps, int pos, DataType data)
{
	for (int i=ps->size-1;i>=pos;i--)
	{
		ps->array[i + 1] = ps->array[i];
	}
	ps->array[pos] = data;
	ps->size++;
}

// 任意位置删除 
void SeqListErase(PSeqList *ps, int pos)
{
	assert(ps->size > 0);
	for (int i = pos + 1; i < ps->size; i++)
	{
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

// 检测data是否在顺序表中 
int SeqListFind(PSeqList *ps, DataType data)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->array[i] == data)
		{
			return 1;
		}
	}
	return -1;
}

// 移除顺序表中第一个值为data的元素 
void SeqListRemove(PSeqList *ps, DataType data)
{
	for (int i=0; i < ps->size; i++)
	{
		if (ps->array[i]==data)
		{
			break; 
			for (int j = i + 1; j < ps->size; j++)
			{
				ps->array[j - 1] = ps->array[j];
			}
			ps->size--;
		}
	}
}

// 移除顺序表中所有值为data的元素 
void SeqListRemoveAll(PSeqList *ps, DataType data)
{
	for (int i = 0; i < ps->size; i++)
	{
		while (ps->array[i] == data)
		{
			for (int j = i + 1; j < ps->size; j++)
			{
				ps->array[j - 1] = ps->array[j];
			}
			ps->size--;
		}
	}
}

// 获取顺序表有效元素个数 
int SeqListSize(PSeqList *ps)
{
	return ps->size;
}

// 获取顺序表的容量 
int SeqListCapacity(PSeqList *ps)
{
	return ps->capacity;
}

// 检测顺序表是否为空 
int SeqListEmpty(PSeqList *ps)
{
	if (ps->size==0)
	{
		return 0;
	}
	return ps->size;
}

// 获取顺序表中第一个元素 
DataType SeqListFront(PSeqList *ps)
{
	return ps->array[0];
}

// 获取顺序表中最后一个元素 
DataType SeqListBack(PSeqList *ps)
{
	return ps->array[ps->size - 1];
}
int main()
{
	system("pause");
	return 0;
}