#ifndef _Llk_H_
#define _Llk_H_

typedef struct _node
{
	int index;
	int value;
	struct _node *prior;
	struct _node *next;
} Node;

typedef struct _list
{
	Node* head;
	Node* pos;
} List;

typedef enum Status
{
	success,fail,fatal,range_error
} Status;

typedef int xType;

#endif

Status Llist_Create(List* pList);

Status Llist_Add(List* pList,const xType elem); 

Status Llist_Index(List *pList);

Status Llist_Print(List *pList,const int a,const int b); 

Status Llist_Print_All(List *pList);

Status Llist_Print_Index(List *pList,const int a,const int b);

Status Llist_Print_Alindex(List *pList);

int Llist_Len(List *pList);

Status Llist_Locate_Pos(List *pList,int pos,List *p);

Status Llist_Insert_Front(List *pList,const xType elem,int pos);

Status Llist_Insert_Behind(List *pList,const xType elem,int pos);

Status Llist_Findbypos(List *pList,int pos,xType *p);

Status Llist_Findbyvlu(List *pList,const xType p,int *pos);

Status Llist_Seek_All(List *pList,const xType elem); 

Status Llist_Sfind(List *pList,const xType elem);

Status Llist_Deletebypos(List *pList,const int pos);

Status Llist_Deletebyvlu(List *pList,const xType elem); 

Status Llist_Delete_Allvlu(List *pList,const xType elem);

Status Llist_Erase(List *pList); 

Status Llist_Destroy(List *pList);
