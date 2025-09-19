#include<iostream>
using namespace std;
#include<string.h>
class A
{
  private:
    int a,b;
  public:
    void setData(int x,int y)
    {
      this->a=x;
      this->b=y;
    }  

    void showData()
    {
      cout<<"a = "<<a<<","<<"b = "<<b;     
    }

    void input()
    {
      int a,b;
      cout<<"Enter value of a "<<endl;
      cin>>a;
      cout<<"Enter value of b "<<endl;
      cin>>b;
      setData(a,b);
    }
};
class B:public A
{
  private:
    int c;
  public:
    void input()
    {
      int x,y,z;
      cout<<"Enter value of x "<<endl;
      cin>>x;
      cout<<"Enter value of y "<<endl;
      cin>>y;
      cout<<"Enter value of c "<<endl;
      cin>>c;
      setData(x,y);
    }  
    void showData()
    {
      cout<<"c = "<<c<<endl;
      A::showData();
    }
};

class Shape //Abstract class:
{
  private:
    char name[20];
  public:
    void setShape(char n[])
    {
      strcpy(this->name,n);
    }
    char* showShape(){return this->name;}

    virtual float area() = 0;//pure virtual funtion makes class abstract:
};

class rectangle:public Shape
{
  private:
    float length,breath;
  public:
    void setlength(int l){this->length=l;}
    void setbreath(int b){this->breath=b;}
    int getlength(){return this->length;}
    int getbreath(){return this->breath;}

    float area(){return getlength()*getbreath();}
    
};

class Square:public Shape
{
  private:
    int side;
  public:
    void setSide(int s){this->side=s;}
    int getSide(){return this->side;}  

    float area(){return side*side;}
};

int main()
{
  //this is runtime polymorphism:
  Shape* s;
  rectangle r1;
  s = &r1;
  r1.setlength(5);
  r1.setbreath(4);
  cout<<s->area();
}

/*Runtime polymorphism in C++ means that the decision about which function to call is made while the 
program is running, not while it is being compiled.
-->It is mainly achieved using virtual functions in inheritance.
-->Imagine you have a remote control (base class pointer/reference) that can control different TV brands 
    (derived classes).
-->Which TV brand’s function gets called is decided at runtime when you actually point the remote to the TV.

1.Without virtual keyword → It becomes compile-time polymorphism (function decided at compile time).

2.With virtual keyword → It becomes runtime polymorphism.

3.Needs inheritance + function overriding.

4.Uses vtable internally to decide which function to run.*/