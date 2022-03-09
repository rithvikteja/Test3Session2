#include<stdio.h>
struct _fraction
{
  int num,den;
};
typedef struct _fraction Fraction;
Fraction input_fraction()
{
  Fraction f1;
  printf("enter fraction in format a b\n");
  scanf("%d %d",&f1.num,&f1.den);
  return f1;
}
Fraction Smallest_fraction(Fraction f1,Fraction f2,Fraction f3)
{
  Fraction smallest;
  if(f1.num*f2.den<f2.num*f1.den)
  {
    if(f1.num*f3.den<f3.num*f1.den)
    {
      smallest.num=f1.num;
      smallest.den=f1.den;
    }
    else
    {
      smallest.num=f3.num;
      smallest.den=f3.den;
    } 
  }
  else
  {
    if(f2.num*f3.den<f3.num*f2.den)
    {
      smallest.num=f2.num;
      smallest.den=f2.den;
    }
    else
    {
      smallest.num=f3.num;
      smallest.den=f3.den;
    }
  }
  return smallest;
}
void output(Fraction f1,Fraction f2,Fraction f3,Fraction smallest)
{
  printf("the greatest among %d/%d,%d/%d and %d/%d is %d/%d",f1.num,f1.den,f2.num,f2.den,f3.num,f3.den,smallest.num,smallest.den);
}  
int main()
{
  Fraction f1,f2,f3,smallest;
  f1=input_fraction();
  f2=input_fraction();
  f3=input_fraction();
  smallest=Smallest_fraction(f1,f2,f3);
  output(f1,f2,f3,smallest);
  return 0;
}
