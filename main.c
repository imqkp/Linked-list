#include <stdio.h>
#include <stdlib.h>
#include "Linked-List.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	List list,t;
	int number,k;
	List p;
	Node q;
    Llist_Create(&list);
	do{
		printf("please enter number:");
		scanf("%d",&number);
		if(number!=-1)
		{
		    Llist_Add(&list,number);
		}
	} while(number!=-1);
	Llist_Print_All(&list);
	printf("len=%d\n",Llist_Len(&list));
	printf("please enter a seek num:");
	scanf("%d",&number);
	Llist_Seek_All(&list,number);
	printf("please enter a pos:");
	scanf("%d",&number);
	Llist_Locate_Pos(&list,number,&p);
	printf("index/position=%d,value=%d\n",(p.pos)->index,(p.pos)->value);
	if(Llist_Locate_Pos(&list,number,&t)==success)
	{
		printf("index/position=%d,value=%d\n",number,(t.pos)->value);
	    (t.pos)->value=989;
    }
	Llist_Print_All(&list);
	delet(&list,number);
	printf("please find by pos:");
	scanf("%d",&number);
	Llist_Findbypos(&list,number,&k);
	printf("the num is %d\n",k);
	printf("please find by value:");
	scanf("%d",&number);
	Llist_Findbyvlu(&list,number,&k);
	printf("the pos is %d\n",k);
    printf("please enter a pos:");
	scanf("%d",&number);
	printf("please enter an elem:");
	scanf("%d",&k);
	Llist_Insert_Behind(&list,k,number);
	printf("please enter an pos:");
	scanf("%d",&k);
	Llist_Deletebypos(&list,k);
	Llist_Index(&list);
	Llist_Print_Index(&list,4,2);
	Llist_Erase(&list);
	Llist_Print_All(&list);
	return 0;
}