#include<stdio.h>
struct _fraction
{
  int num,den;
};
typedef struct _fraction Fraction ;
int gcd(int a,int b)
  {
    int t;
    while (b!=0)
     {
       t=b;
       b=a%b;
       a=t;
     }
  return a;
  }
int input_n()
{
  int n;
  printf("enter n \n");
  scanf("%d", &n);
  return n;
}
Fraction input_fraction()
{
  Fraction f;
  printf("Input a fraction \n");
  scanf("%d%d", &f.num, &f.den);
  return f;
}
void input_n_fractions(int n, Fraction f[n])
{
  for(int i=0; i<n; i++)
    {
      f[i]=input_fraction();
    }
}
Fraction add_fraction(Fraction f1, Fraction f2)
{
  Fraction sum;
  sum.num=f1.num*f2.den+f2.num*f1.den;
  sum.den=f1.den*f2.den;
  int g=gcd(sum.num,sum.den);
  sum.num=sum.num/g;
  sum.den=sum.den/g;
  return sum;
  
}
Fraction add_n_fractions(int n, Fraction f[n])
{
  Fraction sum;
  sum=f[0];

  for(int i=1;i<n;i++)
    {
      sum=add_fraction(sum,f[i]);
    }
  return sum;
}
void output_n_fractions(int n,Fraction f[n], Fraction sum)
{
  int i;
  for( i=0; i<n-1; i++)
  {
   printf("%d/%d+", f[i].num,f[i].den);
  }
