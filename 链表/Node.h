#pragma once
typedef int DataType;
typedef struct  ListNode
{
	DataType data;//������
	struct ListNode *next;//ָ����
}Node;
typedef struct Node* LinkList;
typedef struct SList
{
	Node *head;
}SList;

//����ĳ�ʼ��
void SListInit(SList *p);

//�������
Node *CreatListNode(DataType d);

//��������β��ֵΪdata�Ľ��
void SListPushBack(SList *p, DataType data);

//ɾ���������һ�����
void SListPopBack(SList *p);

//������ĵ�һ��Ԫ��ǰ����ֵΪdata�Ľ��
void SListPushFront(SList *p, DataType data);

//ɾ�������е�һ�����
void SListPopFront(SList *p, DataType data);

//������posλ�ú����ֵΪdata�Ľ��
void SListInsertAfter(Node *pos, DataType data);

//ɾ��������ֵΪdata�Ľ��
void SListErase(SList *p, DataType data);

//�������в���ֵΪdata�Ľ�㣬�ҵ����ظý��ĵ�ַ�����򷵻ؿ�
Node *SListFind(SList *p, DataType data);

//��������
void SListDestroy(SList *p);

//��ȡ��������Ч���ĸ���
int SListSize(SList *p);

//��������Ƿ�Ϊ��
int SListFront(SList *p);

//��ȡ����ĵ�һ�����
Node *SListFront(SList *p);

//��ȡ����ĵڶ������
Node *SListBack(SList *p);

//ɾ�������е�һ��ֵΪdata�Ľ��
void SListRemove(SList *p, DataType data);

//ɾ������������ֵΪdata�Ľ��
void SListRemoveAll(SList *p, DataType data);