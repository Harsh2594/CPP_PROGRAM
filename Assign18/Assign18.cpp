#include<iostream>
using namespace std;
#include<string.h>
#include<cmath>
/*Define a class person with name and age as instance variables as private members. provide stters and getters 
as protected methods.Derive a class Employee from Person class with private instance varible salary.Provide
public methods setEmployee() and showEmployee().*/

class Person
{
  private:
    char name[20];
    int age;
  protected:
    void setName(const char name[]){strcpy(this->name,name);}  
    void setAge(int age){this->age=age;}
    char* getName(){return this->name;}
    int getAge(){return this->age;}
};
 class Employee:private Person
 {
    private:
      float empSalary;
    public:
      void setEmployee(const char name[],int age,int empSalary)
      {
        setName(name);
        setAge(age);
        this->empSalary = empSalary;
      }  
      void showEmployee()
      {
        cout<<"Emp_Name = "<<getName()<<","<<"Age = "<<getAge()<<","<<"Salary = "<<this->empSalary;
      }
 };

//  int main()
//  {
//   Employee e1;
//   e1.setEmployee("Harsh",30,10000.0);
//   e1.showEmployee();
//   return 0;
//  }

/*Define a class Circle with radius as private instance varibles and setRadius(), getRadius,getArea()
as punlec instance methods. Define a class ThickCircle as a subclass of Circle with thickness as
private instance varbles and getThickness(),setThickness() as public instance methods.provide an 
overridden method getArea() to calculate area of thick portion of circle.*/

class Circle
{
  private:
    float radius;
  public:
      void setRadius(float r){this->radius=r;}
      float getRadius(){return this->radius;}
      float getArea(){return 3.14*radius*radius;}

};

class Tickcircle:public Circle
{
  private:
    float thickness;
  public:
       void setThickness(float t){this->thickness=t;}
       float getThickness(){return this->thickness;}
       float getArea(){return 3.14*(getRadius()+thickness)*(getRadius()+thickness)-3.14*getRadius()*getRadius();}
};

// int main()
// {
//   Tickcircle tc;
//   tc.setRadius(7.0);
//   tc.setThickness(2.0);
//   cout<<tc.getArea();
//   return 0;
// }

/*Define a class coordinate with x and y as instance variable.Define overloaded version of getDistance,first
with no argument calculating distance from origin,and second with one argument of coordinate type to calculate 
distance between two coordinates.Also define other methods if required.*/

class Coordinate
{
  private:
    int x,y;
  protected:
    void setCoordinate(int x,int y){this->x=x,this->y=y;}
    
  public:
    void showCoordinates(){cout<<"("<<x<<","<<y<<")";}

    float getDistance() //from origin
    {
      return sqrt(x*x+y*y);
    }

    float getDistance(Coordinate C)
    {
      return sqrt((x-C.x)*(x-C.x)+(y-C.y)*(y-C.y));
    }
    
};

/*Define a class shape with shapeName as instance variables.provide setter and getter.*/

class Shape
{
  private:
    char shapeName[20];
  public:
    void setShapeName(char n[])
    {
      strcpy(shapeName,n);
    }  
    char* getShapeName()
    {
      return shapeName;
    }
};

class StraightLine:public Shape
{
  private:
    Coordinate c1;
    Coordinate c2;
  public:
    void setLine(Coordinate c1,Coordinate c2)
    {
      this->c1 = c1;
      this->c2 = c2;
    }  
    
    double getDistance()
    {
      return c1.getDistance(c2);
    }
    
    void showLine()
    {
      c1.showCoordinates();
      c2.showCoordinates();
    }

};

