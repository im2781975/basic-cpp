#include<bits/stdc++.h>
using namespace std;
long long int powera(long long int a,long long int b)
{
    long long int x=1,i;
    for(i=1;i<=b;i++)
    {
        x*=a;
    }
    return x;
}
int main()
{
   long long int number, sum = 0, temp, remainder,n,i,x;

    cin>>n;
    while(n--)
    {
   scanf("%lld",&number);

   temp = number;
   sum=0;
   x=0;

   while(temp!=0)
   {
       x++;
       temp/=10;
   }
   temp=number;
   while( temp != 0 )
   {
      remainder = temp%10;
      sum = sum + powera(remainder,x);
      temp = temp/10;
   }

   if ( number == sum )
      printf("Armstrong\n");
   else
      printf("Not Armstrong\n");
    }
   return 0;
}
