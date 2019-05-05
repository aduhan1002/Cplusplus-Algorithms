#include <stdio.h>

using namespace std;
void prime(int,int);
int main()
{
    int n;
    scanf("%d",&n);
    prime(n,n);
    return 0;
}
void prime(int i,int x)
{
    if(i==1)
        printf("");
    else
    {
        int j=0;
        if(x%i==0)
        {
            for(int k=2;k<i;k++)
            {
                if(i%k==0)
                    j++;
            }
        }
        else
            j++;

        if(j==0)
            {
                printf("\t%d",i);
                prime(i-1,x);
            }
        else
            prime(i-1,x);
    }
}
