#include<iostream>
using namespace std;

class Complex
{
  int real_part;
  int imaginary_part;

  public:
    void set_values(int x,int y)
    {
      real_part = x;
      imaginary_part = y;
    }
    
    void get_values()
    {
      cout<<real_part<<"+"<<imaginary_part<<"i";
    }
};

class Time
{
  private:
    int hrs;
    int min;
    int sec;
  
  public:
    void set_values(int h,int m,int s)
    {
      hrs=h;
      min=m;
      sec=s;
    }
    void show_time()
    {
      cout<<hrs<<":"<<min<<":"<<sec;
    }
};

class Date
{
  private:
    int date,month,year;

    char* get_month_name(int m)
    {
      if(m==1)
        return "Jan";
      else if(m==2)
        return "Feb";
      else if(m==3)
        return "Mar";
      else if(m==4)
        return "Apr";
      else if(m==5)
        return "May";
      else if(m==6)
        return "June";
      else if(m==7)
        return "Jul";
      else if(m==8)
        return "Aug";
      else if(m==9)
        return "Sept";
      else if(m==10)
        return "Oct";
      else if(m==11)
        return "Nav";
      else if(m==12)
        return "Dec";                   
    }

  public:
    void set_date(int d,int m,int y)
    {
      date=d;
      month=m;
      year=y;    
    }  

    void get_date(int format=1)
    {
      if(format==1)
        cout<<date<<"-"<<month<<"-"<<year;
      else if(format==2)
        cout<<date<<"-"<<get_month_name(month)<<"-"<<year;

    }
};













int main()
{
  Date d1;
  d1.set_date(13,3,1994);
  d1.get_date(1);
  cout<<endl;
  d1.get_date(2);
  // Time t1;
  // t1.set_values(2,30,45);
  // t1.show_time();
//   Complex c1;
//   c1.set_values(2,3);
//   c1.get_values();

}