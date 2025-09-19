#include<iostream>
using namespace std;
#include<fstream>

/*Write a c++ program to copy content(read) of a file and store(write) in other file*/
int main()
{
  char ch;
  ifstream fin;
  ofstream fout;
  fin.open("file1.txt",ios::in);
  if(!fin)
  {
    cout<<"File not found";
  }
  else
  {
    fout.open("file2.txt");
    // while(!fin.eof())
    // {
    //   ch = fin.get();
    //   fout<<ch;
    // }
    /*When the file reaches EOF, fin.get() still returns a special EOF marker (often -1), which gets stored
     into char ch, and when you write it out, it turns into that junk character. */
    while(fin.get(ch))
    {
      fout<<ch;
    }
    fin.close();
    fout.close();
  }
  
  return 0;
}