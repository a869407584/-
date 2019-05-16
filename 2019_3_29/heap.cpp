#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//���
int Greater(DataType left, DataType right)
{
	assert(left);
	assert(right);
	return left > right;
}


//С��
int Less(DataType left, DataType right)
{
	assert(left);
	assert(right);
	return left < right;
}


//����
void Swap(DataType* left, DataType* right)
{
	DataType temp = 0;
	temp = *left;
	*left = *right;
	*right = temp;
}

//���µ���
void AdjustDown(Heap* hp, int parent)
{
	int child = 2 * parent + 1;
	assert(hp);
	while (child < hp->_size)
	{
		if (Greater(hp->_array[child], hp->_array[child + 1]) && (child + 1) < hp->_size)
		{
			child = child + 1;
		}
		if (Greater(hp->_array[parent], hp->_array[child]))
		{
			Swap(&hp->_array[parent],&hp->_array[child]);
			parent = child;
			child = 2 * parent + 1;
		}
		else
			return;
	}
}


//���ϵ���
void AdjustUp(Heap* hp, int child)
{
	int parent = (child - 1) / 2;
	assert(hp);
	while (child!=0)
	{
		if (Greater(hp->_array[parent], hp->_array[child]))
		{
			Swap(&hp->_array[parent], &hp->_array[child]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			return;
	}
}

//������
void CreatHeap(Heap* hp, DataType* array, int size,Compare com)
{
	int i = 0;
	int root = (size - 2) / 2;
	assert(hp);
	hp->_array = (DataType*)malloc(sizeof(DataType)*size);
	if (NULL==hp->_array)
	{
		assert(hp);
		return;
	}
	hp->_capacity = size;
	hp->_size = size;
	hp->com = com;
	for (i=0;i<size;i++)
	{
		hp->_array[i] = array[i];
	}
	for (;root>=0;root--)
	{
		AdjustDown(hp, root);
	}
}


//����
void _CheckCapacity(Heap* hp)
{
	int i = 0;
	assert(hp);
	if (hp->_capacity == hp->_size)
	{
		;
		hp->_array = (DataType*)malloc(sizeof(DataType)*(hp->_capacity) * 2);
		if (NULL == hp->_array)
		{
			return;
		}
		hp->_capacity = 2 * hp->_capacity;
	}
}


// ����в���ֵΪdata��Ԫ�� 
void InsertHeap(Heap* hp, DataType data)
{
	int i = 0;
	assert(hp);
	_CheckCapacity(hp);
	hp->_array[hp->_size++] = data;
	AdjustUp(hp, hp->_size - 1);
}


// ɾ���Ѷ�Ԫ�� 
void EraseHeap(Heap* hp)
{
	assert(hp);
	if (EmptyHeap(hp))
		return;
	Swap(&(hp->_array[0]), &(hp->_array[hp->_size - 1]));
	hp->_size--;
	AdjustDown(hp, 0);
}



// ��ȡ������ЧԪ�ظ��� 
int SizeHeap(Heap* hp)
{
	assert(hp);
	return hp->_size;
}



// �����Ƿ�Ϊ�� 
int EmptyHeap(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
		return 1;
	return 0;
}



// ��ȡ�Ѷ�Ԫ�� 
DataType TopHeap(Heap* hp)
{
	assert(hp);
	if (hp->_size == 0)
	{
		return 0;
	}
	return hp->_array[0];
}



// ���ٶ� 
void DestroyHeap(Heap* hp)
{
	assert(hp);
	hp->_size = 0;
	hp->_capacity = 0;
	free(hp->_array);
	hp->_array = NULL;
	return;
}


//��ӡ��
void printfHeap(Heap* hp)
{
	int i = 0;
	for (i = 0; i < hp->_size; i++)
	{
		printf("%d ", hp->_array[i]);
	}
}


//������
//����ǽ���Ļ��� ��һ��С��
//Ȼ���Ƚ�С�ѵĶѶ���ֵ��ѵ׵�ֵ������������Сֵ�͵��˶ѵף�Ȼ�������Ԫ�ظ���-1�����·�����������Ķ�
//�����õĶ���Сֵ���ڶѶ���Ȼ���ٴ�������Ԫ�ؽ�����ֱ��Ԫ�ظ���Ϊ0ʱֹͣ
void HeapSort(Heap *hp)
{
	int i = hp->_size;
	assert(hp);
	i = hp->_size;
	while (i)
	{
		Swap(&hp->_array[i - 1], &hp->_array[0]);//�����ӵͺͶѶ���Ԫ��
		--i;//����Сֵ�ŵ��ѵ�֮��Ԫ�ظ���-1
		AdjustDown(hp, 0);//���µ���ʣ�µļ���Ԫ�صĶ�
	}
}


//���������е�topk����
void Topk(Heap* hp, int k)
{
	int i = 0;
	int j = 0;
	assert(hp);
	hp->_array = (DataType*)malloc(sizeof(DataType)*k);
	if (hp->_array == NULL)
	{
		assert(0);
		return;
	}
	for (i=0;i<k;i++)
	{
		int temp = rand() % 10000;
		hp->_array[i] = temp;
	}
	hp->_size = k;
	for (i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(hp, i);
	}
	for (j = k; j < 10000; j++)
	{
		int temp = rand() % 10000;
		if (temp > hp->_array[0])
		{
			Swap(&temp, &hp->_array[0]);
			AdjustDown(hp, 0);
		}
	}
	printfHeap(hp);
}
int main()
{
	system("pause");
	return 0;
}