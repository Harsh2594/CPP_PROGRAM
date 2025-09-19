//Operator Overloading,friend Function:
#include<iostream>
#include<string.h>
using namespace std;

//Define a complex class to negate real and imaginary part:
class Complex
{
  int real,imag;
  public:
    Complex(){}
    Complex(int real,int imag)
    {
      this->real=real;
      this->imag=imag;
    }

    friend Complex operator-(Complex C);
};
Complex operator-(Complex C)
{
  Complex temp;
  temp.real=-C.real;
  temp.imag=-C.imag;
  return temp;
}

//Defien a class integer 
class Integer
{
  private:
    int a;
  public:
    friend bool operator!(Integer I);  
    friend bool operator==(Integer,Integer);
};

bool operator!(Integer I)
{
  return !(I.a);
}
bool operator==(const Integer I1,const Integer I2)
{
  return I1.a==I2.a;
}

//Create Coordinate class with two instance variable:

class Coordinate
{
  private:
    int x,y;
  public:  
    Coordinate():x(0),y(0){}
    Coordinate(int x,int y):x(x),y(y){}

    Coordinate operator,(Coordinate C)
    {
      return C;  
    }
    
    friend ostream& operator<<(ostream&,Coordinate);
    friend istream& operator>>(istream&,Coordinate&);
    void show()
    {
      cout<<"\n("<<x<<","<<y<<")";
    }  
};
ostream& operator<<(ostream &dout,Coordinate C)
{
  cout<<"\n("<<C.x<<","<<C.y<<")";
  return dout;
}

istream& operator>>(istream&din,Coordinate &C)
{
  cout<<"Enter Coordinate x and y"<<endl;
  cin>>C.x>>C.y;
  return din;
}

//Define a class Student:

class Student
{
  int roll_no,age;
  char name[20];
  public:
    void setStudent(int roll_no,int age,char name[])
    {
      this->roll_no=roll_no;
      this->age = age;
      strcpy(this->name,name);
    }
    void showData()
    {
      cout<<"roll_no = "<<roll_no<<endl<<"name = "<<name<<endl<<"age = "<<age<<endl;
    }

    friend bool operator==(Student,Student);
};
bool operator==(Student s1,Student s2)
{
  return (s1.roll_no==s2.roll_no&&s1.age==s2.age && !(strcmp(s1.name,s2.name)));
}







int main()
{
// Coordinate c1(2,3),c2(5,-1),c3;
// c3 = (c1,c2);
// c3.show();
//   cin>>c3;
//   cout<<c3;
Student s1;
s1.setStudent(1,22,"harsh");
s1.showData();
return 0;
}