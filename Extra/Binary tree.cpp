//Program to make a binary tree which keeps the insertion at the left node to be it's first priority

#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

struct node
{
    int data;
    struct node *left,*right;
}*root=NULL,*temp=NULL,*temp2;

int row_count=0,element_count=1;

void insertion()
{
    temp=new node;                  //This stores the data for the new node to be inserted
    cout<<"Enter data : ";
    cin>>temp->data;
                                    //Since it is the last data to be inserted it's left and right nodes are kept NULL
    temp->left=NULL;
    temp->right=NULL;

    if(root==NULL)                  //If it's the first node, it is inserted at the root
    {
        root= new node;
        root=temp;
        row_count++;
    }


    else{
        temp2=new node;
        temp2=root;
        int l=pow(2,row_count);
        int t=element_count;
        for(int k=0;k<row_count-1;k++)
        {
            if(t>(l/2))
            {
                temp2=temp2->right;                 //If the element belongs to second half of the row, pointer moves towards right.
                t=t-l/2;
            }
            else
            {
                temp2=temp2->left;                  //If the element belongs to first half of the row, pointer moves towards left.
            }
            l=l/2;
        }
        if(element_count%2!=0)
        {
            temp2->left=temp;
        }
        else
        {
            temp2->right=temp;
        }
        if(element_count==pow(2,row_count))     //Adding new row since all the elements of the current row are filled.
        {
            row_count++;
            element_count=1;
        }
        else
            element_count++;                    //Incrementing the position of element.
    }
}

void inorder(struct node *temp3)                //In-order Traverse.
{
    if(temp3!=NULL)
    {
        inorder(temp3->left);
        cout<<temp3->data<<"\t";
        inorder(temp3->right);
    }
}
void preorder(struct node *temp3)               //Pre-order Traverse.
{
    if(temp3!=NULL)
    {
        cout<<temp3->data<<"\t";
        preorder(temp3->left);
        preorder(temp3->right);
    }
}
void postorder(struct node *temp3)              //Post-order Traverse.
{
    if(temp3!=NULL)
    {
        postorder(temp3->left);
        postorder(temp3->right);
        cout<<temp3->data<<"\t";
    }
}

struct node* templevel=(struct node*)malloc(sizeof(struct node));
struct node* levelorder(struct node* t, int l)
{
    if (t==NULL)
        return NULL;

    if (l==1)
        cout<<t->data<<" ";

    else if (l>1)
    {
        templevel=levelorder(t->left,l-1);
        templevel=levelorder(t->right,l-1);
    }
    return templevel;
}

int main()
{
    int ch=0,j;
    struct node *temp4;
    while(ch!=6)
    {
        system("cls");
        cout<<"\nMENU\n";
        cout<<"Press 1 to add new node\n";
        cout<<"Press 2 to display the the tree in in-order form\n";
        cout<<"Press 3 to display the the tree in pre-order form\n";
        cout<<"Press 4 to display the the tree in post-order form\n";
        cout<<"Press 5 to display the the tree in level-order form\n";
        cout<<"Press 6 to exit\n";
        cout<<"Enter your choice : ";
        cin>>ch;
        switch(ch)
        {
            case 1 : insertion(); break;
            case 2 : inorder(root); getche(); break;
            case 3 : preorder(root); getche(); break;
            case 4 : postorder(root); getche(); break;
            case 5 : j=1;
                     temp4=new node;
                     templevel=root;
                     temp4=NULL;
                     do
                     {
                        temp4=levelorder(root,j++);
                     }while(temp4!=NULL);
                     getche(); break;
            default : break;
        }
    }
    return 0;

}
