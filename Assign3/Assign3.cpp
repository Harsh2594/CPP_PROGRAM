#include<iostream>
using namespace std;

//Find average of 3 number:

void average()
{
  int a,b,c;
  float avg;
  cout<<"Enter three number ";
  cin>>a>>b>>c;
  avg = (a+b+c)/3.0;
  cout<<"Average of "<<a<<", "<<b<<", "<<c<<" is "<<avg;
}
//find square of a number
void square()
{
  int a;
  cout<<"Enter a number ";
  cin>>a;
  cout<<"Square of "<<a<<" is "<<a*a;
}
//swap two variable without using third variable:
void swap()
{
  int a,b;
  cout<<"Enter value of a ";
  cin>>a;
  cout<<"Enter value of b ";
  cin>>b;
  a=a+b;
  b = a-b;
  a = a-b;
  cout<<"After swaping value of a is "<<a<<" value of b is "<<b;
}

// WAP to add all the numbers of an array of size 10:

void sum_array()
{
  int i,sum=0;
  int a[10];
  cout<<"Enter 10 numbers ";
  for(i=0;i<10;i++)
    cin>>a[i];
  for(i=0;i<10;i++)
    sum=sum+a[i];
  cout<<"Sum of array of integer is "<<sum;  
  cout<<endl;
}
int main()
{
  // average();
  // cout<<endl;
  // square();
  // cout<<endl;
  // swap();
  // sum_array();
  return 0;
}