// Pointer,this,DMA:
#include<iostream>
#include<string.h>
using namespace std;

class Person
{
  char name[20];
  int age;
  public:
    Person(char name[],int age)
    {
      strcpy(this->name,name);
      this->age=age;
    }
};

class Complex
{
  private:
    int a,b;
  public:
    void setData(int a,int b)
    {
      this->a=a;
      this->b=b;
    }  
    
    void showData()
    {
      cout<<"a = "<<this->a<<","<<"b = "<<this->b<<endl;
    }

};

//write a non member function in which instantiate complex class dynamically. initilise instance variables
// and display their values: 
void f1()
{
  Complex *p = new Complex();
  p->setData(3,4);
  p->showData();
}

int main()
{
  f1();
  return 0;
}

