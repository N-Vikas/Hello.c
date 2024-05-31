#include<stdio.h>
#include<stdlib.h>
void create();
void display();
void insert();
void delete();
struct node
{
    int data;
    struct node *next;
};
struct node *head=NULL;
int main()
{
    int opt;
    while(1)
    {
        printf("\n \t MENU");
        printf("\n 1.create");
        printf("\n 2.display");
        printf("\n 3.Insert");
        printf("\n 4.Delete");
        printf("\n choose any option");
        scanf("%d",&opt);
        switch(opt)
        {
            case 1:create(); break;
            case 2:display(); break;
            case 3:insert(); break;
            case 4:delete(); break;
            case 5:printf("terminated by you"); exit(0);
            break;
        }// end of switch
    }// end of while
    return 0;
}// end of main
void create()
{
    int n,i,val;
    struct node *newnode;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    printf("Enter NODE DATA:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&val);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=val;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
        }
        else
        {
            newnode->next=head;
            head=newnode;
        }
    }
}
void display()
{
    struct node *temp;
    temp=head;
    if(head==NULL)
        printf("\n List is empty");
    else
    {
        printf("\n list is ");
        while(temp!=NULL)
        {
            printf("-->%d",temp->data);
            temp=temp->next;
        }
    }
}
void insert()
{
    struct node *newnode,*temp;
    int pos,i;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data to insert:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    printf("Enter position to insert:");
    scanf("%d",&pos);
    if(head==NULL)
    {
        head=newnode;
        newnode->next=head;
    }
    else
    {
        temp=head;
        if(pos==NULL)
        {
            newnode->next=head;
            head=newnode;
        }
        else
        {
            temp=head;
            for(i=1;i<pos-1;i++)
            {
                temp=temp->next;
                if(temp==head)
                {
                    printf("POSITION ENTERED IS OUT OF BONDS");
                    return ;
                }
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
}
void delete()
{
    struct node *curr,*prev;
    curr=head;
    int pos,i;
    printf("Position to delete:");
    scanf("%d",&pos);
    if(head==NULL)
    {
        printf("LIST IS EMPTY");
        return ;
    }
    if(pos==NULL)
    {
        if(head->next==head)
        {
            printf("List is empty");
            head=NULL;
            free(curr);
            return ;
        }
        prev=curr;
        while(curr->next!=head)
        {
            curr=curr->next;
        }
        curr->next=prev->next;
        head=head->next;
        printf("Deleting data is %d",prev->data);
        free(prev);
    }
    else
    {
        for(i=1;i<pos;i++)
        {
            prev=curr;
            curr=curr->next;
            if(curr==head)
            {
                printf("OUT OF BOUNDS");
                return ;
            }
        }
        prev->next=curr->next;
        printf("Deleting data is %d",curr->data);
        free(curr);
}
}
