#include<stdio.h>
#include<conio.h>
void main()
{
  clrscr();
  int i,j,k;
  for(i=1;i<=5;i++)
  {
    for(j=1;j<=5 - i;j++)
    {
      printf(" "); 
    }
    for(k = 1;k<=i;k++)
    {
      printf("* ");
    }
        printf("\n");
  }
  getch();
}
