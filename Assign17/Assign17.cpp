#include<iostream>
#include<string.h>
using namespace std;

//define a class Time:
class Time
{
  private: 
    int hour,min,sec;  
  public:
    void setTime(int hour,int min,int sec)
    {
      this->hour=hour;
      this->min=min;
      this->sec=sec;
    }

    void showTime()
    {
      cout<<hour<<":"<<min<<":"<<sec;
    }

    void setHour(int hour){this->hour=hour;}
    void setmin(int min){this->min=min;}
    void setsec(int sec){this->sec=sec;}

    int getHour(){return this->hour;}
    int getmin(){return this->min;}
    int getsec(){return this->sec;}

    bool operator>(Time T)
    {
      if(hour>T.hour)
        return true;
      else if(hour<T.hour)
        return false;
      else if(min>T.min)
        return true;
      else if(min<T.min)
        return false;    
      else if(sec>T.sec)
        return true;
      else
        return false;    
          
    }
};

Time* getTimeArray(int size)
{
    Time *ptr = new Time[size];
    return ptr;
}

void sortTimeArray(Time T[],int size)
{
  int r,i;
  Time t;
  for(r=1;r<size;i++)
  {
    for(i=0;i<=size-r-1;i++)
    {
      
      if(T[i]>T[i+1])
      {
        t=T[i];
        T[i]=T[i+1];
        T[i+1]=t;
      }
    }
  }
}

void showTime(Time T[])
{
  cout<<T->getHour()<<":"<<T->getmin()<<":"<<T->getsec()<<endl;
}

// Define a class string with char pointer and length of the string as instance member variables. 
// define a method to dynamically create an array of char type and hold the input string in such a way that
// the array length is just enough to accommodate the input string.
 
class String
{
  char *ptr;
  int length;
  public:
    String()
    {
      ptr = NULL;
      length=0;
    }
    void input_string()
    {
      char temp[1000];
      cout<<"Enter input string"<<endl;
      cin.ignore(); //Clear newline character from input buffer
      cin.getline(temp,1000);
      length = strlen(temp);
      ptr = new char[length+1];
      strcpy(ptr,temp);
    }

    void uppercase()
    {
      for(int i=0;ptr[i];i++)
      {
        if(ptr[i]>='a'&&ptr[i]<='z')
          ptr[i] = ptr[i]-32;
      }
    }

    void lowercase()
    {
      for(int i=0;ptr[i];i++)
      {
        if(ptr[i]>='A'&&ptr[i]<='Z')
          ptr[i] = ptr[i]+32;
      }
    }

    char* display()
    {
      cout<<"String: "<<ptr<<endl;
      cout<<"length: "<<sizeof(ptr)<<endl;
      return ptr;
    }
    ~String()
    {
      delete []ptr;
    }
};