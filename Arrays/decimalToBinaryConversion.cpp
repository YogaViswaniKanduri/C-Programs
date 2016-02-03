#include<stdio.h>

void main()
{
  long int m,no=0,a=1;
  int n,rem;
  clrscr();
  printf("Enter any decimal number->");
  scanf("%d",&n);
  m=n;
  while(n!=0)
  {
          rem=n%2;
          no=no+rem*a;
          n=n/2;
          a=a*10;
  }
  printf("The value %ld in binary is->",m);
  printf("%ld",no);
  getch();
}