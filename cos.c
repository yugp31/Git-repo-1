#include<stdio.h>
#include<conio.h>
void main()
{
  clrscr();
  int i,j,t;
  printf("Enter the number:");
  scanf("%d",&t);
  for(i=1;i<=10;i++)
  {
    j=i*t;
    printf("%d X %d = %d\n",t,i,j);
  }
  getch();
}