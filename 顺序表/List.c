#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "List.h"
//��ʼ��
void SeqListInit(PSeqList *ps)
{
	assert(ps!= NULL);
	ps->capacity = 20;
	ps->array = (int *)malloc(sizeof(DataType)*ps->capacity);
	ps->size = 0;
}
//���
void SeqListDestroy(PSeqList *ps)
{
	assert(ps);
	assert(ps->array);
	free(ps->array);
	ps->array = NULL;
	ps->capacity = 0;
	ps->size = 0;
}

//β��
void SeqListPushBack(PSeqList *ps, DataType data)
{
	ps->array[ps->size] = data;
	ps->size++;
}
//βɾ
void SeqListPopBack(PSeqList *ps)
{
	assert(ps->size > 0);
	ps->size--;
}

//ͷ��
void SeqListPushFront(PSeqList *ps, DataType data)
{
	for (int i=ps->size;i>=1;i--)
	{
		ps->array[i] = ps->array[i - 1];
	}
	ps->array[0] = data;
	ps->size++;
}
//ͷɾ
void SeqListPopFront(PSeqList *ps)
{
	assert(ps->size > 0);
	for (int i=0;i<ps->size-1;i++)
	{
		ps->array[i] = ps->array[i + 1];
	}
	ps->size--;
}

// ����λ�ò��� 
void SeqListInsert(PSeqList *ps, int pos, DataType data)
{
	for (int i=ps->size-1;i>=pos;i--)
	{
		ps->array[i + 1] = ps->array[i];
	}
	ps->array[pos] = data;
	ps->size++;
}

// ����λ��ɾ�� 
void SeqListErase(PSeqList *ps, int pos)
{
	assert(ps->size > 0);
	for (int i = pos + 1; i < ps->size; i++)
	{
		ps->array[i - 1] = ps->array[i];
	}
	ps->size--;
}

// ���data�Ƿ���˳����� 
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

// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
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

// �Ƴ�˳���������ֵΪdata��Ԫ�� 
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

// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(PSeqList *ps)
{
	return ps->size;
}

// ��ȡ˳�������� 
int SeqListCapacity(PSeqList *ps)
{
	return ps->capacity;
}

// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList *ps)
{
	if (ps->size==0)
	{
		return 0;
	}
	return ps->size;
}

// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(PSeqList *ps)
{
	return ps->array[0];
}

// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(PSeqList *ps)
{
	return ps->array[ps->size - 1];
}
int main()
{
	system("pause");
	return 0;
}