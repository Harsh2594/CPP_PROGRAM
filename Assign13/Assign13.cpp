//Operator Overloading//
#include<iostream>
using namespace std;

//Define a class Fraction in which an operator + to add two fraction object:

class Fraction
{
  private:
    long numerator;
    long denominator;
  public:
    Fraction(long n=0,long d=0):numerator(n),denominator(d)
    {}

    int LCM(long d1,long d2)
    {
      long d;
      for(d=(d1>d2?d1:d2);d<=d1*d2;d++)
        if(d%d1==0&&d%d2==0)
          return d;
    }

    int GCD(int x,int y)
    {
      while(y)
      {
        int t = y;
        y = x%y;
        x = t;

      }
      return x;
    }
//implement + operator to add two fraction ojbect;
    Fraction operator+(Fraction f)
    {
      Fraction temp;
      temp.denominator = LCM(denominator,f.denominator);
      temp.numerator = ((temp.denominator/denominator)*numerator)+((temp.denominator/f.denominator)*f.numerator);
      //simplification:
      int g = GCD(temp.numerator,temp.denominator);
      temp.numerator /= g;
      temp.denominator /= g;
      return temp;
    }
//Compare two fraction object:
    bool operator<(Fraction f)
    {
      int lcm = LCM(denominator,f.denominator);
      numerator = (lcm/denominator)*numerator;
      f.numerator = (lcm/f.denominator)*f.numerator; 
      if(numerator<f.numerator)
        return true;
      return false;  
    }

};

//Define a class distance overlaod the operator '+' to add two distance object:

class Distance 
{
  private:
    int km,m,cm;
  public:
    Distance(int km=0,int m=0,int cm=0):km(km),m(m),cm(cm)
    {}
    
    void show_Data()
    {
      cout<<"km="<<km<<","<<"m="<<m<<","<<"cm="<<cm<<endl;
    }

    Distance operator+(Distance D)
    {
      Distance temp;
      temp.cm = cm+D.cm;
      temp.m = m+D.m+(temp.cm/100);
      temp.cm = temp.cm%100;
      temp.km = km+D.km+(temp.m/1000);
      temp.m = temp.m%1000; 
      return temp;
    }

    //pre-Decrement distance by 1cm:

    Distance operator--()
    {
      --cm;
      m = m+cm/100;
      cm = cm%100;
      km +=m/1000;
      m = m%1000;
      return *this;

    }

    //post-Decrement distance by 1cm:

    Distance operator--(int)
    {

      Distance temp = *this;
      cm--;
      m = m+cm/100;
      cm = cm%100;
      km +=m/1000;
      m = m%1000;
      return temp;

    }

};

int main()
{
  Distance d1(3,800,80);
  Distance d2(3,300,30);
  Distance d3;
  d3 = d1+d2;
  d3.show_Data();
  return 0;
}

/*consider a class Array define constructor to allocate an array of given size(size is given through parameter)
 Define a subscript operator to access element at given index. Define Disctructor to deallocate the memory of
 array*/

class Array
{
  private:
    int *p;
    int size;
  public:
    Array(int s)
    {
      size = s;
      //allocate an array of given size:
      p = new int[size];
    }  

    ~Array()
    {
      delete []p;
    }
    /*Using & in operator[] is not mandatory, but it's essential when you want to support writing
     (obj[i] = value) or avoid unnecessary copies.Without &, you're returning a copy, which means
     you can only read the value, not modify it.*/
     
    int& operator[](int index)
    {
      if(index<0||index>=size)
      {
        cout<<"Index out of Range!";
        return p[0]; 
      } 
      return p[index];
    }

    void print()
    {
      for(int i=0;i<size;i++)
        cout<<p[i]<<" ";
      cout<<endl;  
    }
};


