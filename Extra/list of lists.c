/* Create a list of list program having records of students Branch-wise and show topper of each branch */

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>

struct branch
{
    char b[5];
    struct branch *below;
    struct stud * next;
} *temp,*s1=NULL,*e1=NULL;
struct stud
{
    char name[20];
    int roll;
    double cg;
    struct stud *Next;
} *Temp;

void newbranch()
{
    temp=(struct branch *)malloc(sizeof(struct branch));
    if(s1==NULL)
    {
        printf("\nEnter name of branch\t");
        scanf("%s",temp->b);
        temp->below=NULL;
        temp->next=NULL;
        s1=temp;
        e1=temp;
    }
    else
    {
        printf("\nEnter name of branch\t");
        scanf("%s",temp->b);
        temp->below=NULL;
        temp->next=NULL;
        e1->below=temp;
        e1=temp;
    }
}

void newstud()
{
    char s[5];
    int p=0;
    printf("\n Enter name of branch\t");
    scanf("%s",s);
    struct branch *t=s1;
    while(t!=NULL)
    {
        if(strcmp(t->b,s)==0)
        {
            p++;
            struct stud *q=t->next;
            if(q==NULL)
            {
                Temp=(struct stud *)malloc(sizeof(struct stud));
                printf("\n Enter name\t");
                scanf("%s",Temp->name);
                printf("\n Enter roll no\t");
                scanf("%d",&Temp->roll);
                printf("\n Enter CG\t");
                scanf("%lf",&Temp->cg);
                Temp->Next=NULL;
                t->next=Temp;
            }
            else
            {
                while(q->Next!=NULL)
                    q=q->Next;
                Temp=(struct stud *)malloc(sizeof(struct stud));
                printf("\n Enter name\t");
                scanf("%s",Temp->name);
                printf("\n Enter roll no\t");
                scanf("%d",&Temp->roll);
                printf("\n Enter CG\t");
                scanf("%lf",&Temp->cg);
                Temp->Next=NULL;
                q->Next=Temp;
            }
        }
        t=t->below;
    }
    if(p==0)
        printf("\n NO SUCH BRANCH");
}
void topper()
{
    struct branch * l=s1;
    if(l==NULL)
    {
        printf("\n NO RECORDS");
    }
    else
    {
        while(l!=NULL)
        {
            struct stud *t=l->next;
            if(t==NULL)
                printf("\n No records in %s branch",l->b);
            else
            {
                double max=t->cg;
                while(t->Next!=NULL)
                {
                    t=t->Next;
                    if((t->cg)>max)
                        max=t->cg;
                }
                printf("\n Topper of %s branch has %f CG",l->b,max);
            }
            l=l->below;
        }
    }
}
void display()
{
    if(s1==NULL)
        printf("\n NO RECORDS\n");
    else
    {
        struct branch *t=s1;
        while(t!=NULL)
        {
            printf("\nBRANCH- %s",t->b);
            if(t->next==NULL)
                printf("\n\tNO RECORDS IN THIS BRANCH\n");
            else
            {
                struct stud * p=t->next;
                while(p!=NULL)
                {
                    printf("\n\t%s\t%d\t%lf",p->name,p->roll,p->cg);
                    p=p->Next;
                }
            }
            t=t->below;
        }
    }
}
int main()
{
    int i=-1;
    while(i!=5)
    {
        printf("\nMain Menu\n");
        printf("1- Add new branch\n");
        printf("2- Add new student\n");
        printf("3- Display topper of each branch\n");
        printf("4- Display all\n");
        printf("5- EXIT\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1: newbranch();
            break;
            case 2: newstud();
            break;
            case 3: topper();
            break;
            case 4: display();
                break;
                case 5: break;
            default: printf("\n INVALID OPTION \n");
            break;
        }
    }
    return 0;
}
