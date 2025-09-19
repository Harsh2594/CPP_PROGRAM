#include<iostream>
using namespace std;

//Operator Overloading,friend function:

class Complex
{
  private:
    int a,b;
  public:
    Complex()
    {
      //default constructor:
    }
    Complex(int a,int b)
    {
      this->a=a;
      this->b=b;
    }

    friend Complex operator+(Complex ,Complex);
    friend Complex operator-(Complex ,Complex);
    friend Complex operator*(Complex ,Complex);
};

Complex operator+(Complex X,Complex Y)
{
  Complex temp;
  temp.a = X.a+Y.a;
  temp.b = X.a+Y.b;
  return temp;
}
Complex operator-(Complex X,Complex Y)
{
  Complex temp;
  temp.a = X.a-Y.a;
  temp.b = X.a-Y.b;
  return temp;
}
Complex operator*(Complex X,Complex Y)
{
  Complex temp;
  temp.a = (X.a*Y.a)-(X.b*Y.b);
  temp.b = (X.a*Y.a)+(X.b*Y.b);
  return temp;
}

//Define Time class and implement operator overloading for insertion operator(<<) and exsertion operator(>>):

class Time
{
  private:
    int hour,min,sec;
  public:
    Time()
    {

    }

    Time(int hour,int min,int sec)
    {
      this->hour=hour;
      this->min=min;
      this->sec=sec;
    }  

    Time& operator=(Time &T)
    {
      hour = T.hour;
      min = T.min;
      sec = T.min;
      return *this;
    }


    friend istream& operator>>(istream&,Time&);
    friend ostream& operator<<(ostream&,Time&);
    
};

istream& operator>>(istream &din,Time &T)
{
  din>>T.hour>>T.min>>T.sec;
  return din;
}

ostream& operator<<(ostream &dout,Time &T)
{
  dout<<T.hour<<":"<<T.min<<":"<<T.sec;
}

//define array:

class Array
{
  int *p;
  int size;
  public:
    Array(int s)  
    {
      size=s;
      p = new int[size];
    }

    ~Array()
    {
      delete []p;
    }

    Array operator=(const Array arr)
    {
      size=arr.size;
      p = new int[size];
      for(int i=0;i<size;i++)
        p[i]=arr.p[i];
      return *this;  
    }

    friend Array operator+(Array&,Array&);
    

};

Array operator+(Array &a1,Array& a2)
{
  Array temp(a1.size+a2.size);
  for(int i = 0;i<a1.size;i++)
    temp.p[i]=a1.p[i];
  for(int i = 0;i<a2.size;i++)
    temp.p[a1.size+i]=a2.p[i];
  return temp;    
}



int main()
{
  // Time t2;
  // Time t1;
  // cout<<"Enter time ";
  // operator>>(cin,t1);
  // operator<<(cout,t1);
  // t2=t1
  // t2.operator=(t1);
}