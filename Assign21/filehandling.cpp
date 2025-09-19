#include<iostream>
using namespace std;
#include<fstream>

/*Write a c++ program to read and display content of file*/
int main()
{
  ifstream fin;
  string line;
  fin.open("file1.txt");
  if(!fin)
  {
    cout<<"File Not found!";
  }
  else
  {
    while(getline(fin,line))
    {
      cout<<line<<endl;
    }
  }
  fin.close();
}


