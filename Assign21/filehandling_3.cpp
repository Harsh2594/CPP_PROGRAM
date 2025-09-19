#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#include<fstream>

class Employee
{
  private:
    int empID;
    char name[20];
    float salary;
  public:
    void input()
    {
      cout<<"\nEnter employee id,name and salary";
      cin>>empID;
      cin.ignore();
      cin.getline(name,20);
      cin>>salary;
    }  
    void display()
    {
      cout<<empID<<" "<<name<<" "<<salary;
    }
    void store();
    void printAll();
    void search(int id);
    void edit(int id);
    void del(int id);
  };
void Employee::store()
{
  ofstream fout;
  fout.open("emp_file",ios::binary|ios::app);//after this write caller object
  fout.write((char*)this,sizeof(*this));
  fout.close();
}

void Employee::printAll()
{
  ifstream fin;
  fin.open("emp_file",ios::binary|ios::in);
  if(!fin)
  {
    cout<<"File Not found";
  }
  else
  {
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
      cout<<empID<<" "<<name<<" "<<salary<<endl;
      fin.read((char*)this,sizeof(*this));
    }
  }
  fin.close();
}

void Employee::search(int id)
{
  ifstream fin;
  fin.open("emp_file",ios::binary|ios::in);
  if(!fin)
  {
    cout<<"File Not found";
  }
  else
  {
    fin.read((char*)this,sizeof(*this));
    while(!fin.eof())
    {
      if(empID==id)
      {
        this->display();
        break;
      }
      fin.read((char*)this,sizeof(*this));  
    }
    if(empID!=id)
          cout<<"search failed!";
  }
  fin.close();  

}
void Employee::edit(int id)
{
  ifstream fin;
  ofstream fout;
  Employee e;
  fin.open("emp_file",ios::binary|ios::in);
  if(!fin)
  {
    cout<<"File not found";
  }
  else
  {
    fout.open("temp",ios::binary|ios::out);
    fin.read((char*)&e,sizeof(e));
    while(!fin.eof())
    {
      if(e.empID==id)
      {
        cout<<"Enter correct employee name ";
        cin.ignore();
        cin.getline(e.name,20);
        cout<<"Enter employee salary ";
        cin>>e.salary;
      }
      fout.write((char*)&e,sizeof(e));
      fin.read((char*)&e,sizeof(e));
    }
    fin.close();
    fout.close();
    remove("emp_file");
    rename("temp","emp_file");
  }
  
   
}

void Employee::del(int id)
{

  ifstream fin;
  ofstream fout;
  Employee e;
  fin.open("emp_file",ios::binary|ios::in);
  if(!fin)
  {
    cout<<"File not found";
  }
  else
  {
    fout.open("temp",ios::binary|ios::out);
    fin.read((char*)&e,sizeof(e));
    while(!fin.eof())
    {
      if(e.empID!=id)
      {
        fout.write((char*)&e,sizeof(e));
      }
      
      fin.read((char*)&e,sizeof(e));
    }
    fin.close();
    fout.close();
    remove("emp_file");
    rename("temp","emp_file");
  }
    
}

int menu()
{
  int choice;
  cout<<"\n1.New Record";
  cout<<"\n2.viewAll Record";
  cout<<"\n3.search Record";
  cout<<"\n4.Edit Record";
  cout<<"\n5.Delete Record";
  cout<<"\n6.Exit";
  cout<<"\n\nEnter your choice ";
  cin>>choice;
  return choice;
}
int main()
{
  int id;
  Employee emp;
  while(true)
  {
    switch(menu())
    {
      case 1:
        emp.input();
        emp.store();
        break;
      case 2:
        emp.printAll();
        break;
      case 3:
        cout<<"Enter Employee id to search ";
        cin>>id;
        emp.search(id);
        break;
      case 4:
        cout<<"Enter Employee id to edit ";
        cin>>id;
        emp.edit(id);
        break;
      case 5:
        cout<<"Enter Employee id to delete ";
        cin>>id;
        emp.del(id);
        break;
      case 6:
        exit(0);
      default:
        cout<<"Invalid choice";
      

    }
  }
}

    