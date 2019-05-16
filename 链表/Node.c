#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Node.h"
//����ĳ�ʼ��
void SListInit(SList *p)	
{
	assert(p);
	p = NULL;
}

//�������
Node *CreatListNode(DataType data)
{
	Node *newnode = (Node*)malloc(sizeof(Node));
	if (newnode==NULL)
	{
		printf("�½�㴴��ʧ�ܣ�");
		return NULL;
	}
	newnode->data = data;
	newnode->next = NULL;
	return newnode;
}

//��������β��ֵΪdata�Ľ��
void SListPushBack(SList *p, DataType data)
{
	assert(p);
	if (p == NULL)
	{
		p = CreatListNode(data);
	}
	else
	{
		Node *p2 = p;
		while (p2->next!=NULL)
		{
			p2 = p2->next;
		}
		p2->next = CreatListNode(data);
	}
}

//ɾ���������һ�����
void SListPopBack(SList *p)
{
	assert(p);
	if (p == NULL)
	{
		return;
	}
	else if (p->head->next==NULL)
	{
		free(p);
		p = NULL;
	}
	else
	{
		Node *p2 = p;
		while (p2->next->next)
		{
			p2 = p2->next;
			free(p2->next);
			p2->next = NULL;
		}
	}
}

//������ĵ�һ��Ԫ��ǰ����ֵΪdata�Ľ��
void SListPushFront(SList *p, DataType data)
{
	Node *newp = CreatListNode(data);
	assert(p);
	newp->next = p;
	p = newp;
}

//ɾ�������е�һ�����
void SListPopFront(SList *p, DataType data)
{
	
}

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
int main()
{
	system("pause");
	return 0;
}