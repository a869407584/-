#pragma once
typedef int DataType;
typedef int(*Compare)(DataType left, DataType right);//��������ָ�����͵Ĳ���������һ�����εĺ���ָ��
typedef struct Heap
{
	DataType* _array;
	int _capacity;
	int _size;
	Compare com;
}Heap;
//���ڱȽ�
int Greater(DataType left, DataType right);
//С�ڱȽ�
int Less(DataType left, DataType right);
//����
void Swap(int* left, int* right);
//���µ���
void AdjustDown(Heap* hp, int parent);
//���ϵ���
void AdjustUp(Heap* hp, int child);
//������
void CreatHeap(Heap* hp, int* array, int size);
//����
void _CheckCapacity(Heap* hp);
// ����в���ֵΪdata��Ԫ�� 
void InsertHeap(Heap* hp, DataType data);
// ɾ���Ѷ�Ԫ�� 
void EraseHeap(Heap* hp);
// ��ȡ������ЧԪ�ظ��� 
int SizeHeap(Heap* hp);
// �����Ƿ�Ϊ�� 
int EmptyHeap(Heap* hp);
// ��ȡ�Ѷ�Ԫ�� 
DataType TopHeap(Heap* hp);
// ���ٶ� 
void DestroyHeap(Heap* hp);
//��ӡ��
void PrintHeap(Heap hp);
//������
void HeapSort(Heap *q);
//���������е�topk����
void Topk(Heap* q, int k);