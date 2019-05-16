#pragma once
typedef int DataType;
typedef int(*Compare)(DataType left, DataType right);//接受两个指针类型的参数，返回一个整形的函数指针
typedef struct Heap
{
	DataType* _array;
	int _capacity;
	int _size;
	Compare com;
}Heap;
//大于比较
int Greater(DataType left, DataType right);
//小于比较
int Less(DataType left, DataType right);
//交换
void Swap(int* left, int* right);
//向下调整
void AdjustDown(Heap* hp, int parent);
//向上调整
void AdjustUp(Heap* hp, int child);
//创建堆
void CreatHeap(Heap* hp, int* array, int size);
//扩容
void _CheckCapacity(Heap* hp);
// 向堆中插入值为data的元素 
void InsertHeap(Heap* hp, DataType data);
// 删除堆顶元素 
void EraseHeap(Heap* hp);
// 获取堆中有效元素个数 
int SizeHeap(Heap* hp);
// 检测堆是否为空 
int EmptyHeap(Heap* hp);
// 获取堆顶元素 
DataType TopHeap(Heap* hp);
// 销毁堆 
void DestroyHeap(Heap* hp);
//打印堆
void PrintHeap(Heap hp);
//堆排序
void HeapSort(Heap *q);
//海量数据中的topk问题
void Topk(Heap* q, int k);