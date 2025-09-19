#include<iostream>
#include<string.h>
using namespace std;

class Numbers
{
  private:
    int size;
    int *arr;
  public:
    Numbers(int s)
    {
      size=s;
      //dynamically allocate array:
      arr = new int[s];
    }  

    //destructor to deallocate memory of array:
    ~Numbers()
    {
      delete []arr;
    }
    
    //Copy constructor(Deep copy):
    Numbers(Numbers &n){
      size=n.size;
       // Allocate new memory and copy the arr
      arr = new int[size];
      for(int i=0;i<size;i++)
        arr[i] = n.arr[i];

    }
};

class Student
{
  private:
    int roll_no;
    char name[20];
  private:
    Student()
    {
      cout<<"Enter roll number ";
      cin>>roll_no;
      cout<<"Enter name: ";
      cin.ignore();
      cin.getline(name,20);
    }
     void display()
     {
      cout<<"roll_no: "<<roll_no<<" "<<"name: "<<name;
     }
};

//create a Date class and initialise instance member using initialiser:

class Date
{
  private:
    int hour,min,sec;
  public:
    Date(int hour,int min, int sec):hour(hour),min(min),sec(sec)
    {}  
};

//define a class for hotel management project with room_number,room_tpye,is_AC,price as instance variable initialise 
//instance variable using constructor:

class Room
{
  private:
    int room_number;
    int room_type;
    bool is_AC;
    float room_pice;
  public:
    Room(int rno,int r_type,float r_price,bool ac)
    {
      room_number=rno;
      room_type=r_type;
      room_pice=r_price;
      is_AC = ac;
    }  
}; 

