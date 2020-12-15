/*WAP Implement doubly link list with primitive operations
a)  	Create a doubly linked list.
b)  	Insert a new node to the left of the node.
c)  	Delete the node based on a specific value
d)  	Display the contents of the list*/



#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head;
void ins_left()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL)
    {
        head=newnode;
    }
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
}
void ins_end()
{
	struct node *newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the number: ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		 temp=head;
		 while(temp->next!=NULL)
		 temp=temp->next;
		 temp->next=newnode;
		 newnode->prev=temp;

	}

}
void ins_ran()
{
	int ele;
	struct node *newnode,*temp;
	printf("Enter the element in the list: ");
	scanf("%d",&ele);
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter the new node data: ");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	newnode->prev=NULL;
    if(head==NULL)
    {
        printf("List is Empty/n");
        return;
    }
	temp=head;
	while(temp->data!=ele)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			printf("Element is  not in the list\n");
			return;
		}
	}
	newnode->next=temp->next;
	temp->next=newnode;
	newnode->prev=temp;
	newnode->next->prev=newnode;
}
void del()
{
	struct node *temp;
	int ele;
    if(head==NULL)
    {
        printf("List is empty!!\n");
        return;
    }
	printf("Enter the element to be deleted: ");
	scanf("%d",&ele);
	temp=head;
	while(temp->data!=ele)
	{
		temp=temp->next;
		if(temp==NULL)
		{
		 printf("Element not in list\n");
		 break;
		}
	 }
	 if(temp==head)
	 {
		 head=head->next;
	 }
	 else if(temp->next==NULL)
	 {
			temp=temp->prev;
			temp->next=NULL;
	 }

	 else
	 {
		 temp->prev->next=temp->next;
		 temp->next->prev=temp->prev;
	 }
}
void display()
{
	 struct node *temp;
	 temp=head;
	 while(temp!=NULL)
	 {
		 printf("%d\t",temp->data);
		 temp=temp->next;
	 }
	 printf("\n");
}
int main()
{
    int ch;
    printf("Choose from the following: \n");
    do{
        printf("1.Insert at the beginning\n2.Insert at the end\n3.Insert in between\n4.Delete a number\n5.Display list\n6.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            ins_left();
            break;
        case 2:
            ins_end();
            break;
        case 3:
            ins_ran();
            break;
        case 4:
            del();
            break;
        case 5:
            display();
            break;
        case 6:
            break;
        default:
            printf("Invalid choice!!/n");
        }
    }while(ch!=6);
    return 0;
}
