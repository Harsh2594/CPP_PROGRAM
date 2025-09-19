#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
#include<fstream>

class Employee
{
  private:
    int empId;
    char name[20];
    float salary;
  public:
    void setEmployee(int id,char n[],float s)
    {
      empId=id;
      strcpy(name,n);
      salary=s;
    }

    void showEmployee(){cout<<empId<<" "<<name<<" "<<salary<<endl;}
    
    /*Write employee data in a file*/
    void save(const char filename[])
    {
      ofstream fout;
      fout.open(filename,ios::app);
      fout.write((char*)this,sizeof(*this));
      fout.close();
    }
    /*Read empployee data from file and show records*/
    void viewallEmployee(char filename[])
    {
      ifstream fin;
      fin.open(filename,ios::in);
      if(!fin)
        cout<<"File Not found!";
      else  
      {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
          this->showEmployee();
          fin.read((char*)this,sizeof(*this));
        }
      }
      fin.close();  
    }    
     void find_employee(int id)
    {
      ifstream fin;
      fin.open("file.txt",ios::binary|ios::in);
      if(!fin)
      {
        cout<<"file not found!";
      }
      else
      {
        fin.read((char*)this,sizeof(*this));
        while(!fin.eof())
        {
          if(empId==id)
          {
            cout<<endl<<"Employee found"<<endl;
            this->showEmployee();
            break;
          }  
          fin.read((char*)this,sizeof(*this));
        }
        if(empId!=id)
          cout<<"search failed!";
      }
      fin.close();

    }
   

      
};
int main()
{
  Employee emp;
  // emp.setEmployee(1,"ajay",20000);
  // emp.save("file.txt");
  // emp.setEmployee(2,"vijay",40000);
  // emp.save("file.txt");
  // emp.setEmployee(3,"sachin",200000);
  // emp.save("file.txt");
  // emp.setEmployee(4,"abhi",400000);
  // emp.save("file.txt");
  // emp.setEmployee(5,"sujit",300000);
  // emp.save("file.txt");
  emp.viewallEmployee("file.txt");
  emp.viewallEmployee("file.txt");
  cout<<endl;
  return 0;
}