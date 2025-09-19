#include<iostream>
using namespace std;

//Operator Overloading:

class Complex
{
  private:
    int a,b;
  public:
  
    Complex(){
      //Default constructor:
    }

    Complex(int a,int b):a(a),b(b)
    {

    }
    Complex operator+(Complex C)
    {
      Complex temp;
      temp.a = a+C.a;
      temp.b = b+C.b;
      return temp;
    }

    Complex operator*(Complex C)
    {
      Complex temp;
      temp.a = a*C.a;
      temp.b = b*C.b;
      return temp;
    }

    Complex operator-(Complex C)
    {
      Complex temp;
      temp.a = a-C.a;
      temp.b = b-C.b;
      return temp;
    }

    bool operator==(Complex C)
    {
      if(a==C.a && b==C.b)
        return true;
      return false;  
    }
};

//create a Time class which overload (>) operator to compare to time object:

class Time
{
  private:
    int hour,min,sec;
  public:
    void Set_value(int h,int m,int s)
    {
      hour=h;
      min=m;
      sec=s;
    }
    bool operator>(Time t)
    {
      if(hour>t.hour)
        return true;
      else if(hour<t.hour)
        return false; 
      if(min>t.min)
        return true;
      else if(min<t.min)
        return false;
      if(sec>t.sec)
        return true;
      else
        return false;     
    }

    //pre-increment:Return current object after increment:
    Time operator++()
    {
      ++sec;
      min+=sec/60;
      sec=sec%60;
      hour += min/60;
      min = min%60;
      return *this;
    }
    //post_increment:Return orignal value:
    //use dummy 'int' as argument to make compiler differenciate pre and post increment:
    //if we not use dummy int then Error: no matching function for call to ‘operator++(int) comes:’
    Time operator++(int)
    {
      Time temp =*this;//save current status:
      sec++;
      min+=sec/60;
      sec=sec%60;
      hour += min/60;
      min = min%60;
      return temp;//return orignal value 
    }

    Time operator+(Time T)
    {
      Time temp;
      int carray;
      temp.sec = sec+T.sec;
      carray = temp.sec/60;
      temp.sec = temp.sec%60;
      temp.min=min+T.min+carray;
      carray=temp.min/60;
      temp.min=temp.min%60;
      temp.hour=hour+T.hour+carray;
      return temp;
    }
};

//Class Matrix that's uses Operator overloading to add,subtract,multiply:
class Matrix
{
  private:
    int A[3][3];
  public:
    void input()
    {
      cout<<"Enter 9 matrix element in row wise:";
      for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          cin>>A[i][j]; 
        cout<<endl;  
    }
    void showMatrix()
    {
      for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          cout<<A[i][j]<<" ";
        cout<<endl;  
    }  

    Matrix operator+(Matrix M)
    {
      Matrix m;
      for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          m.A[i][j] = A[i][j]+M.A[i][j]; 
      return m;    
    }

    Matrix operator-(Matrix M)
    {
      Matrix m;
      for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          m.A[i][j] = A[i][j]-M.A[i][j]; 
      return m;    
    }

    Matrix operator*(Matrix M)
    {
      Matrix m;
      for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          for(int k=0;k<3;k++)
            m.A[i][j]+=A[i][k]*M.A[k][j];
      return m;     
    }

    Matrix transpose()
    {
      Matrix m;
      for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          m.A[j][i]=A[i][j];
      return m;    
    }
    bool is_singular()
    {
      int det;
      det = A[0][0]*(A[1][1]*A[2][2]-A[1][2]*A[2][1])-A[0][1]*(A[1][0]*A[2][2]-A[1][2]*A[2][0])-A[0][2]*(A[1][0]*A[2][1]-A[1][1]*A[2][0]);
      if(det==0)
        return true;
      return false;  
            
    }
};

