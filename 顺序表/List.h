//˳���
typedef int DataType;
typedef struct 
{
	DataType *array;//����˳�������ЧԪ�ظ���
	int capacity;//�ռ��ܴ�С
	int size;//��ЧԪ�ظ���
}PSeqList;
//��ʼ��
void SeqListInit(PSeqList *ps);
//���
void SeqListDestroy(PSeqList *ps);

//β��
void SeqListPushBack(PSeqList *ps,DataType data);
//βɾ
void SeqListPopBack(PSeqList *ps);

//ͷ��
void SeqListPushFront(PSeqList *ps, DataType data);
//ͷɾ
void SeqListPopFront(PSeqList *ps);

// ����λ�ò��� 
void SeqListInsert(PSeqList *ps, int pos, DataType data);

// ����λ��ɾ�� 
void SeqListErase(PSeqList *ps, int pos);

// ���data�Ƿ���˳����� 
int SeqListFind(PSeqList *ps, DataType data);

// �Ƴ�˳����е�һ��ֵΪdata��Ԫ�� 
void SeqListRemove(PSeqList *ps, DataType data);

// �Ƴ�˳���������ֵΪdata��Ԫ�� 
void SeqListRemoveAll(PSeqList *ps, DataType data);

// ��ȡ˳�����ЧԪ�ظ��� 
int SeqListSize(PSeqList *ps);

// ��ȡ˳�������� 
int SeqListCapacity(PSeqList *ps);

// ���˳����Ƿ�Ϊ�� 
int SeqListEmpty(PSeqList *ps);

// ��ȡ˳����е�һ��Ԫ�� 
DataType SeqListFront(PSeqList *ps);

// ��ȡ˳��������һ��Ԫ�� 
DataType SeqListBack(PSeqList *ps);