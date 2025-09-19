#include<iostream>
#include<cmath>
using namespace std;

//function deffination:

void swap(int &,int &);
int add(int,int,int=0);
float area(int);
float area(int ,int);
float area(int,int,int);
int max_number(int ,int);
double max_number(double,double);

int main()
{
  // int a,b;
  // cout<<"Enter two number a and b: ";
  // cin>>a>>b;
  // swap(a,b);
  // cout<<"a = "<<a<<","<<"b = "<<b;
  // cout<<endl;
  // cout<<"Add two number."<<endl;
  // cout<<"2+3="<<add(2,3)<<"\n";
  // cout<<"Add three number."<<endl;
  // cout<<"2+3+4="<<add(2,3,4);
  cout<<"Area of circle "<<area(5)<<endl;
  cout<<"Area of rectangle "<<area(4,5)<<endl;
  cout<<"Area of traingle "<<area(3,4,5)<<endl;
}
//WAF to swap two data of two int variable using call by reference:
void swap(int &x,int &y)
{
  x=x+y;
  y=x-y;
  x=x-y;
}

//WAF using the default argument that is able to add 2 or 3 number:
int add(int a,int b,int c)
{
  return a+b+c;
}

//define overloaded function to calculate area of circle, area of reactangle and area of traingle:

//function to calculate area of circle:

float area(int r)
{
  return (3.17*r*r);
}
//function to calculate area of rectangle:

float area(int x,int y)
{
  return (x*y);
}
//function to calculate area of traingle:

float area(int x,int y,int z)
{
  float s=(x+y+z)/2.0;
  int traingle_area = sqrt(s*(s-x)*(s-y)*(s-y));
  return traingle_area;
}

//USING function overloading find maximum of two number and both number can be integer or real:

int max_number(int x,int y)
{
  if(x>y)
    return x;
  else
    return y;  
}

double max_number(double x,double y)
{
  if(x>y)
    return x;
  else
    return y; 
}