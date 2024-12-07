#include<stdio.h>
int main()
{
    int i,j,t;
    printf("Enter the number:");
    scanf("%d",&t);
    for(i=1;i<=10;i++)
    {
        j=i*t;
        printf("%d X %d = %d \n",t,i,j);
    }
    return 0;
}