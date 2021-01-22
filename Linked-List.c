#include <stdio.h>
#include <stdlib.h>
#include "Linked-List.h"

/*
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
*/

Status Llist_Create(List* pList)
{
	Status st=fatal;
	Node *p=(Node*)malloc(sizeof(Node));
	if(p==NULL)
	{
		printf("no enough memory!\n");
		//exit(1);
    }
	else
	{
		p->index=0;
		p->value=999;
		p->prior=NULL;
		p->next=NULL;
		pList->head=p;
		st=success;
	}
	return st;
}

Status Llist_Add(List* pList,const xType elem) 
{
	Status st=fatal;
	Node *p=(Node*)malloc(sizeof(Node));
	if(p==NULL)
	{
		printf("no enough memory!\n");
		exit(1);
	}
	else
	{
    	p->value=elem;
	    p->next=NULL;
	    Node *last=pList->head;
    	while(last->next)
   		{
	   		last=last->next;
   		}
   		last->next=p;
   		p->prior=last;
        st=success;
    }
    return st;
}

Status Llist_Index(List *pList)
{
	Status st=success;
	Node *p;
	int i;
	if(pList->head==NULL)
	{
		st=fatal;
		//exit(1);
	}
	else
	{
		for(i=0,p=pList->head;p;p=p->next,i++)
		{
			p->index=i;
		}
	}
	return st;
}

Status Llist_Print(List *pList,const int a,const int b)
{
	Status st=success;
	Node *p;
	int t;
	if(((a<b)?a:b)<0 || ((a>b)?a:b)>Llist_Len(pList))
	{
		printf("out of range!\n");
		st=range_error;
		//exit(1);
	}
	for(t=0,p=pList->head->next;p && t<Llist_Len(pList);p=p->next,t++)
	{
		if(t>=((a<b)?a:b)-1 && t<=((a>b)?a:b)-1)
		{
			printf("%d\t",p->value);
	    }
	}
	if(pList->head==NULL)
	{
		st=fatal;
		//exit(1);
	}
	printf("\n");
	return st;
}

Status Llist_Print_All(List *pList)
{
	Status st=success;
	Node *p;
	for(p=pList->head->next;p;p=p->next)
	{
		printf("%d\t",p->value);
	}
	if(p==NULL)
	{
		st=fatal;
		//exit(1);
	}
	printf("\n");
	return st;
}

Status Llist_Print_Index(List *pList,const int a,const int b)
{
	Status st=success;
	Node *p;
	int t;
	if(((a<b)?a:b)<0 || ((a>b)?a:b)>Llist_Len(pList))
	{
		printf("out of range!\n");
		st=range_error;
		//exit(1);
	}
	for(t=0,p=pList->head->next;p && t<Llist_Len(pList);p=p->next,t++)
	{
		if(t>=((a<b)?a:b)-1 && t<=((a>b)?a:b)-1)
		{
			printf("%d\t",p->value);
	    }
	}
	printf("\n");
	for(t=0,p=pList->head->next;p && t<Llist_Len(pList);p=p->next,t++)
	{
		if(t>=((a<b)?a:b)-1 && t<=((a>b)?a:b)-1)
		{
			printf("%d\t",p->index);
	    }
	}
	if(pList->head==NULL)
	{
		st=fatal;
		//exit(1);
	}
	printf("\n");
	return st;
}

Status Llist_Print_Alindex(List *pList) 
{
	Status st=success;
	Node *p;
	for(p=pList->head->next;p;p=p->next)
	{
		printf("%d\t",p->value);
	}
	printf("\n");
	for(p=pList->head->next;p;p=p->next)
	{
		printf("%d\t",p->index);
	}
	if(p==NULL)
	{
		st=fatal;
		//exit(1);
	}
	printf("\n");
	return st;
}

int Llist_Len(List *pList)
{
	int len=0;
	Node *p;
	for(p=pList->head->next;p;p=p->next)
	{
		len++;
	}
	return len;
}

Status Llist_Locate_Pos(List *pList,int pos,List *p)
{
	Status st=fatal;
	int i=0;
	if(pList->head && pos<=Llist_Len(pList) && pos>0)
	{
		for(p->pos=pList->head;p->pos;p->pos=p->pos->next,i++)
		{
			if(i==pos)
			{
				st=success;
				break;
			}
		}
	}
	else if(pos>Llist_Len(pList) || pos<1)
	{
		printf("out of range!\n");
		st=range_error;
		//exit(1);
	}
	return st;
}

Status Llist_Insert_Front(List *pList,const xType elem,int pos)
{
	Status st=fatal;
	List p;
	Node *q;
	if(pos>Llist_Len(pList) || pos<1)
	{
		printf("pos error!\n");
		st=range_error;
	}
	else
	{
		Llist_Locate_Pos(pList,pos,&p);
		q=(Node*)malloc(sizeof(Node));
		if(q)
		{
			q->value=elem;
			q->prior=(p.pos)->prior;
			q->next=p.pos;
			(p.pos)->prior->next=q;
			(p.pos)->prior=q;
			st=success;
		}
		else
		{
			printf("no enough memory!\n");
			//exit(1);
		}
	}
	return st;
}

Status Llist_Insert_Behind(List *pList,const xType elem,int pos)
{
	Status st=fatal;
	List p;
	Node *q;
	if(pos>Llist_Len(pList) || pos<1)
	{
		printf("pos error!\n");
		st=range_error;
		//exit(1);
	}
	else
	{
		Llist_Locate_Pos(pList,pos,&p);
		q=(Node*)malloc(sizeof(Node));
		if(q)
		{
			q->value=elem;
			q->next=(p.pos)->next;
			q->prior=p.pos;
			(p.pos)->next->prior=q;
			(p.pos)->next=q;
			st=success;
		}
		else
		{
			printf("no enough memory!\n");
			//exit(1);
		}
	}
	return st;
}

Status Llist_Findbypos(List *pList,int pos,xType *p)
{
	List q;
	Status st=Llist_Locate_Pos(pList,pos,&q);
	if(st==success)
	{
		*p=(q.pos)->value;
	}
	return st;
}

Status Llist_Findbyvlu(List *pList,const xType p,int *pos)
{
	Status st=fail;
	Node *q;
	int i=0;
	for(q=pList->head->next;q;q=q->next,i++)
	{
		if(q->value==p)
		{
			*pos=i;
			st=success;
			break;
		}
	}
	if(st==fail)
	{
		printf("cannot find this value!\n");
	}
	return st;
}

Status Llist_Seek_All(List *pList,const xType elem)  //can find all
{
	Status st=success;
	Node *p;
	int flag=0;
	for(p=pList->head->next;p;p=p->next)
	{
		if(p->value==elem)
		{
			if(!flag++)
			{
				printf("Have found!\n");
			}
			printf("The elem %d is at %d\n",elem,p->index);
		}
	}
	if(!flag)
	{
		printf("Not found!\n");
	}
	if(p==NULL)
	{
		st=fatal;
		//exit(1);
	}
	return st;
}

Status Llist_Sfind(List *pList,const xType elem)
{
	Status st=fail;
	Node *p;
	if(pList->head==NULL)
	{
		st=fatal;
		//exit(1);
	}
	else
	{
		for(p=pList->head;p;p=p->next)
		{
			if(p->value==elem)
			{
				st=success;
			}
		}
	}
    return st;
}

Status Llist_Deletebypos(List *pList,const int pos)
{
	List p;
	Status st=Llist_Locate_Pos(pList,pos,&p);
	switch (st)
	{
		case success:
			(p.pos)->prior->next=(p.pos)->next;
			if((p.pos)->next)
			{
				(p.pos)->next->prior=(p.pos)->prior;
		    }
			free(p.pos);
			break;
		case range_error:
			printf("out of range!\n");
			//exit(1);
			break;
	}
	return st;
}

Status Llist_Deletebyvlu(List *pList,const xType elem)
{
	Status st=fail;
	Node *p;
	if(pList->head==NULL)
	{
		st=fatal;
		//exit(1);
	}
	else
	{
		for(p=pList->head->next;p;p=p->next)
		{
			if(p->value==elem)
			{
				p->prior->next=p->next;
				p->next->prior=p->prior;
				free(p);
				st=success;
				break;
			}
		}
		if(st==fail)
		{
			printf("cannot find this elem!\n");
			exit(1);
		}
    }
    return st;
}

Status Llist_Delete_Allvlu(List *pList,const xType elem)
{
	Status st=fail;
	if(Llist_Sfind(pList,elem)==success)
	{
		Llist_Deletebyvlu(pList,elem);
		st=success;
	}
	return st;
}

Status Llist_Erase(List *pList)
{
	Status st=success;
	int i=Llist_Len(pList);
	for(i;i>0;i--)
	{
		Llist_Deletebypos(pList,i);
	}
	if(pList->head==NULL)
	{
		st=fatal;
	}
	return st;
}

Status Llist_Destroy(List *pList) 
{
	Status st=success;
	Node *p,*q;
	for(p=pList->head;p;p=q)
	{
		q=p->next;
		free(p);
	}
    return st;
}