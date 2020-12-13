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
void ins_rear1(int ele)
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
void ins_rear2(int ele)
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
void del_front1()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(head1==NULL)
    {
        printf("List is empty!!\n");
    }
    else
    {
        temp=head1;
        head1=temp->next;
        printf("%d is removed front front!!\n",temp->data);
        free(temp);
    }
}
void del_front2()
{
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    if(head2==NULL)
    {
        printf("List is empty!!\n");
    }
    else
    {
        temp=head2;
        head2=temp->next;
        printf("%d is removed front front!!\n",temp->data);
        free(temp);
    }
}
void del_rear1()
{
    struct node *temp, *run;
    temp=(struct node *)malloc(sizeof(struct node));
    run=(struct node*)malloc(sizeof(struct node));
    temp=head1->next;
    if(run==NULL)
    {
        printf("List is empty!!\n");
    }
    else
    {
        while(temp->next!=NULL)
        {
            run=temp;
            temp=temp->next;
        }
        printf("%d is deleted from rear\n",temp->data);
        run->next=NULL;
        free(temp);
    }
}
void del_rear2()
{
    struct node *temp, *run;
    temp=(struct node *)malloc(sizeof(struct node));
    run=(struct node*)malloc(sizeof(struct node));
    temp=head2->next;
    run=head2;
    if(run==NULL)
    {
        printf("List is empty!!\n");
    }
    else
    {
        while(temp->next!=NULL)
        {
            run=temp;
            temp=temp->next;
        }
        printf("%d is deleted from rear\n",temp->data);
        run->next=NULL;
        free(temp);
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
void sort1(struct node *h)
{
    int i,j,a;

    struct node *temp1;
    struct node *temp2;

    for(temp1=h;temp1!=NULL;temp1=temp1->next)
      {
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
          { 
            if(temp2->data < temp1->data)
              {
                a = temp1->data;
                temp1->data = temp2->data;
                temp2->data = a;
              }
           }
       }
}
void sort2(struct node *h)
{
    int i,j,a;

    struct node *temp1;
    struct node *temp2;

    for(temp1=h;temp1!=NULL;temp1=temp1->next)
      {
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
          { 
            if(temp2->data < temp1->data)
              {
                a = temp1->data;
                temp1->data = temp2->data;
                temp2->data = a;
              }
           }
       }
}
void rev1(struct node *h)
{
    int i,j,a;

    struct node *temp1;
    struct node *temp2;

    for(temp1=h;temp1!=NULL;temp1=temp1->next)
    {
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
        {
            a = temp1->data;
            temp1->data = temp2->data;
            temp2->data = a;
        }
    }
}
void rev2(struct node *h)
{
    int i,j,a;

    struct node *temp1;
    struct node *temp2;

    for(temp1=h;temp1!=NULL;temp1=temp1->next)
    {
        for(temp2=temp1->next;temp2!=NULL;temp2=temp2->next)
        {
            a = temp1->data;
            temp1->data = temp2->data;
            temp2->data = a;
        }
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
    printf("Choose any option-");
    do{
        printf("\n1.Insert at rear in list 1\n2.Insert at rear in list 2\n3.Delete random from list 1\n4.Delete random from list 2\n5.Remove from front in list 1\n6.Remove from front in list 2\n7.Remove from rear in list 1\n8.Remove from rear in list 2\n9.Display list 1\n10.Display list 2\n11.Sort list 1\n12.Sort list 2\n13.Reverse list 1.\n14.Reverse list 2\n15.Concatenate list 1 and list 2\n16.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            printf("\nEnter the number to be inserted: ");
            scanf("%d",&item);
            printf("\n");
            ins_rear1(item);
            break;
        case 2:
            printf("\nEnter the number to be inserted: ");
            scanf("%d",&item);
            printf("\n");
            ins_rear2(item);
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
            del_front1();
            break;
        case 6:
            del_front2();
            break;
        case 7:
            del_rear1();
            break;
        case 8:
            del_rear2();
            break;    
        case 9:
            display1();
            break;
        case 10:
            display2();
            break;
        case 11:
            sort1(head1);
            break;
        case 12:
            sort2(head2);
            break;
        case 13:
            rev1(head1);
            break;
        case 14:
            rev2(head2);
            break;
        case 15:
            conc();
            break;
        case 16:
            break;
        default:
            printf("\nEnter a valid choice!!\n");
        }
    }while(ch!=16);
    return 0;
}
