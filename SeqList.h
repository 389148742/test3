#include<stdio.h>
#ifndef  __MY_SEQLIST_H__ 
#define __MY_SEQLIST_H__

typedef void SeqList;
typedef void SeqListNode;
typedef struct _tag_SeqList
{
	int length;
	int capacity;
	unsigned int* node;


}TSeqList;


SeqList* SeqList_Create(int capacity)
{
	TSeqList*tmp = NULL;
	int ret = 0;
	tmp = (TSeqList*)malloc(sizeof(TSeqList));
	if (tmp == NULL)
	{
		printf(" seqlist_create error%d",ret);
		ret = -1;
		return NULL;

	}
	memset(tmp, 0, sizeof(TSeqList));
	tmp->node = (unsigned int*)malloc(sizeof(unsigned int*)*capacity);
	if (tmp->node == NULL)
	{
		printf("funs seqlist_create error:%d\n", ret);
		return NULL;
		ret = -2;

	}
	tmp->capacity = capacity;
	tmp->length = 0;
	return tmp;


	
}


void SeqList_Destroy(SeqList* list)
{
	TSeqList*tlist = NULL;
	if (list == NULL)
	{
		return -1;

	}
	tlist = (TSeqList*)list;
	if (tlist->node != NULL)
	{
		free(tlist);

	}

	return;
}

void SeqList_Clear(SeqList* list)
{
	TSeqList*tlist = NULL;
	if (list == NULL)
	{
		return;

	}
	tlist = (TSeqList*)list;
	tlist->length;
	return;
}

int SeqList_Length(SeqList* list)
{
	TSeqList*tlist = NULL;
	if (list == NULL)
	{
		return -1;

	}
	tlist = (TSeqList*)list;
	return tlist->length;
	

}

int SeqList_Capacity(SeqList* list)
{
	TSeqList*tlist = NULL;
	if (list == NULL)
	{
		return -1;

	}
	tlist = (TSeqList*)list;
	return tlist->capacity;
}

int SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
	int i = 0,
	ret = 0;
	TSeqList*tlist = NULL;
	if (list == NULL || node == NULL || pos < 0)
	{
		ret = -1;
		printf("funs seqlist_insert()error%d", ret);
			return -1;

	}
	
	
	tlist = (TSeqList*)list;
	if (tlist->length >= tlist->capacity)
	{
		ret = -2;
		printf("funs seqlist_insert error%d", ret);
		return ret;

	}
	if (pos >= tlist->length)
	{
		pos = tlist->length;
	}
	for (i = tlist->length; i > pos; i--)
	{
		tlist->node[i] = tlist->node[i - 1];

	}
	tlist->node[i] = (unsigned int)node;

	tlist->length++;
	return 0;


}

SeqListNode* SeqList_Get(SeqList* list, int pos)
{
	int i = 0;
	SeqListNode*ret = 0;
	TSeqList*tlist = NULL;
	tlist = (TSeqList*)list;
	if (tlist == NULL || pos < 0)
	{
		SeqListNode *ret = -1;
		printf("funs seqList_Get()error%d", ret);
		return NULL;

	}
	
	ret = (void*)tlist->node[pos];

	return ret;


}

SeqListNode* SeqList_Delete(SeqList* list, int pos)
{
	int i = 0;
	SeqListNode*ret = 0;
	TSeqList*tlist = NULL;
	if (list == NULL || pos < 0)
	{
		printf("funs seqlist_delete() error%d", ret);
		return NULL;

	}
	tlist = (TSeqList*)list;
	ret = (SeqListNode*)tlist->node[pos];
	for (i = pos + 1; i < tlist->length; i++)
	{
		tlist->node[i - 1] = tlist->node[i];

	}
	tlist->length--;


	return ret;
}


#endif  //__MY_SEQLIST_H__



