#include <stdio.h>
int sum(int a, int b)
{
   if (a==b)
   {
      return (a+b)*3;
    } else {
      return (a+b);
    }
}

int main()
{
   int res = sum(1,2);
   printf("Result is %d\n", res);
   res = sum(3,3);
   printf("Result is %d\n", res);
}