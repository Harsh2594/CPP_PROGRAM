#include<iostream>
using namespace std;

void f1()
{
  cout<<"hello!World"<<"\n";
}

void f2()
{
  cout<<"Hello"<<"\n"<<"World!";
}

void sum()
{
  int a,b;
  cout<<"Enter value of a "; //cout is pre define object to print :
  cin>>a;
  cout<<"Enter value of b ";
  cin>>b;                    //cin is pre define object to take input from user :
  cout<<"Sum of "<<a<<" and "<<b<<" is "<<a+b;
}

int main()
{
  f1();
  cout<<endl;
  f2();
  cout<<endl;
  sum();
  return 0;
}