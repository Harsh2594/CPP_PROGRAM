#include<iostream>
#include<string.h>
using namespace std;


class Cuboid
{
  private:
    int length,breath,height;
    //constructor
  public:  
    Cuboid()
    {
      length=0;
      breath=0;
      height=0;
    }

    Cuboid(int l,int b,int h)
    {
      length=l;
      breath=b;
      height=h;
    }  
    
};

class Customer
{
  private:
    int cust_id;
    char mob_no[10];
    char name[20],email[40];
  public:
    Customer()
    {
      cust_id=0;
      strcpy(mob_no,"7318024042");
      strcpy(name,"ABCD");
      strcpy(email,"ABCD@gmail.com");
    }  
      
    Customer(int id,char mo[],char na[],char em[])
    {
      cust_id =id;
      strcpy(mob_no,mo);
      strcpy(name,na);
      strcpy(email,em);
    }
};

class Complex
{
  private:
    int a,b;
  public:

    Complex(int x,int y)
    {
      a=x,b=y;
    }
    
    void show_data()
    {
      cout<<"a = "<<a<<","<<"b = "<<b<<endl;
    }

};

int main()
{
  //if we have not default constructor than how to initilize array of class object
  Complex c[5] = {Complex(1,2),Complex(3,4),Complex(5,6),Complex(8,9),Complex(10,11)};
  for(int i=0;i<5;i++)
    c[i].show_data();

}