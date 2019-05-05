#include<stdio.h>

struct node
{
    int data;
    struct node* next;
}*start=NULL,*end=NULL,*temp;

void push()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter element\t");
    scanf("%d",&temp->data);
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
        end=temp;
    }
    else
    {
        end->next=temp;
        end=temp;
    }
}

void show()
{
    temp=start;
    while(temp!=NULL)
    {
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}

void reverse_list()
{
    if(start==NULL || start->next==NULL)
        ;
    else
    {
        struct node*a,*b,*c;
        a=start;
        end=a;
        b=start->next;
        c=start->next->next;
        a->next=NULL;
        while(c!=NULL)
        {
            b->next=a;
            a=b;
            b=c;
            c=c->next;
        }
        b->next=a;
        start=b;
    }
}
int main()
{
    int i=-1;
    while(i!=4)
    {
        printf("\nMAIN MENU\n");
        printf("1- Add element to list\n");
        printf("2- Show the list\n");
        printf("3- Reverse the list\n");
        printf("4 -Exit");
        printf("\nENTER YOUR CHOICE\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1:push();  break;
            case 2:show();  break;
            case 3:reverse_list();  break;
        }
    }
    return 0;
}
