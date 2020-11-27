#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head1=NULL;
struct node *head2=NULL;
int length1=0;
int length2=0;
void ins1(int ele)
{
    struct node *newnode, *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=NULL;
    if(head1==NULL)
    {
        head1=newnode;
        length1=1;
    }
    else
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp=head1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        length1++;
    }
}
void ins2(int ele)
{
    struct node *newnode, *temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=ele;
    newnode->next=NULL;
    if(head2==NULL)
    {
        head2=newnode;
        length2=1;
    }
    else
    {
        temp=(struct node*)malloc(sizeof(struct node));
        temp=head2;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        length2++;
    }
}
void del1(int ele)
{
    struct node *temp, *del;
    temp=(struct node*)malloc(sizeof(struct node));
    del=(struct node*)malloc(sizeof(struct node));
    del=NULL;
    if(head1->data==ele)
    {
        del=head1;
        head1=head1->next;
        del->next=NULL;
    }
    else
    {
        temp=head1;
        while(temp!=NULL)
        {
            if(temp->next->data==ele)
            {
                del=temp->next;
                temp->next=del->next;
                del->next=NULL;
                length1--;
                break;
            }
            else
            {
                temp=temp->next;
            }
        }
    }
    if(del==NULL)
    {
        printf("\nElement not found!!\n");
    }
}
void del2(int ele)
{
    struct node *temp, *del;
    temp=(struct node*)malloc(sizeof(struct node));
    del=(struct node*)malloc(sizeof(struct node));
    del=NULL;
    if(head2->data==ele)
    {
        del=head2;
        head1=head2->next;
        del->next=NULL;
    }
    else
    {
        temp=head2;
        while(temp->next!=NULL)
        {
            if(temp->next->data==ele)
            {
                del=temp->next;
                temp->next=del->next;
                del->next=NULL;
                length2--;
                break;
            }
            else
            {
                temp=temp->next;
            }
        }
    }
    if(del==NULL)
    {
        printf("\nElement not found!!\n");
    }
}
void conc()
{
    struct node *temp, *run;
    temp=(struct node*)malloc(sizeof(struct node));
    run=(struct node*)malloc(sizeof(struct node));
    run=head1;
    if(length1==0 && length2==0)
    {
        printf("\nBoth lists empty\n");
    }
    else
    {
        temp=head1;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=head2;
    }
    printf("\nThe elements in the concatenated list is-\n");
    while(run!=NULL)
    {
        printf("%d\n",run->data);
        run=run->next;
    }
}
void display1()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head1;
    if(temp==NULL)
    {
        printf("\nList is empty!!\n");
    }
    else
    {
        printf("\nThe contents in list 1 are-\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
void display2()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head2;
    if(temp==NULL)
    {
        printf("\nList is empty!!\n");
    }
    else
    {
        printf("\nThe contents in list 2 are-\n");
        while(temp!=NULL)
        {
            printf("%d\n",temp->data);
            temp=temp->next;
        }
    }
}
int main()
{
    int ch, item;
    printf("Choose any option-\n");
    do{
        printf("1.Add to list 1\n2.Add to list 2\n3.Delete from list 1\n4.Delete from list 2\n5.Display list 1\n6.Display list 2\n7.Concatenate list 1 and list 2\n8.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the number to be inserted: ");
            scanf("%d",&item);
            printf("\n");
            ins1(item);
            break;
        case 2:
            printf("\nEnter the number to be inserted: ");
            scanf("%d",&item);
            printf("\n");
            ins2(item);
            break;
        case 3:
            printf("\nEnter the number to be deleted: ");
            scanf("%d",&item);
            printf("\n");
            del1(item);
            break;
        case 4:
            printf("\nEnter the number to be deleted: ");
            scanf("%d",&item);
            printf("\n");
            del2(item);
            break;
        case 5:
            display1();
            break;
        case 6:
            display2();
            break;
        case 7:
            conc();
            break;
        case 8:
            break;
        default:
            printf("\nEnter a valid choice!!\n");
        }
    }while(ch!=8);
    return 0;
}
