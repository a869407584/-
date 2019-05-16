#pragma once
typedef int DataType;
typedef struct  ListNode
{
	DataType data;//数据域
	struct ListNode *next;//指针域
}Node;
typedef struct Node* LinkList;
typedef struct SList
{
	Node *head;
}SList;

//链表的初始化
void SListInit(SList *p);

//创建结点
Node *CreatListNode(DataType d);

//在链表中尾插值为data的结点
void SListPushBack(SList *p, DataType data);

//删除链表最后一个结点
void SListPopBack(SList *p);

//在链表的第一个元素前插入值为data的结点
void SListPushFront(SList *p, DataType data);

//删除链表中第一个结点
void SListPopFront(SList *p, DataType data);

//在链表pos位置后插入值为data的结点
void SListInsertAfter(Node *pos, DataType data);

//删除链表中值为data的结点
void SListErase(SList *p, DataType data);

//在链表中查找值为data的结点，找到返回该结点的地址，否则返回空
Node *SListFind(SList *p, DataType data);

//销毁链表
void SListDestroy(SList *p);

//获取链表中有效结点的个数
int SListSize(SList *p);

//检测链表是否为空
int SListFront(SList *p);

//获取链表的第一个结点
Node *SListFront(SList *p);

//获取链表的第二个结点
Node *SListBack(SList *p);

//删除链表中第一个值为data的结点
void SListRemove(SList *p, DataType data);

//删除链表中所有值为data的结点
void SListRemoveAll(SList *p, DataType data);