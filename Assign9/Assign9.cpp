#include<iostream>
using namespace std;

class Complex
{
  private:
    int a,b;
  public:
    
    void setData(int x, int y)
    {
      a=x;
      b=y;
    }
    void showData()
    {
      cout<<"a = "<<a<<","<<"b = "<<b<<endl;
    }

    Complex add(Complex C)
    {
      Complex temp;
      temp.a = a+C.a;
      temp.b = b+C.b;
      return temp;
    }

    Complex subtract(Complex C)
    {
      Complex temp;
      temp.a = a-C.a;
      temp.b = b-C.b;
      return temp;
    }

    Complex multiply(Complex C)
    {
      Complex temp;
      temp.a = a*C.a;
      temp.b = b*C.b;
      return temp;
    }
};

class Time 
{
  private:
    int h,m,s;

  public:
    void setTime(int x, int y,int z)
    {
      h=x,m=y,z=s;
    }

    void showTime()
    {
      cout<<h<<":"<<m<<":"<<s<<endl;
    }

    void normalize()
    {
      if(s>=60)
        m = m+(s/60);  
      else if(m>=60)
        h = h+(m/60);
      showTime();  
    }

    Time add(Time T)
    {
      Time t;
      t.h = h+T.h;
      t.m = m+T.m;
      t.s = s+T.s;
      return t;
    }

    bool is_greater(Time t)
    {
      if(h>t.h)
        return true;
      else if (h<t.h)
        return false;  
      else if(m>t.m)
        return true;
      else if(m<t.m)
        return false;  
      else if(s>t.s)
        return true;   
      else
        return false;   
    }

};

class TestResult
{
  private:
    int roll_no,right,wrong, net_score;
    static int right_weightage,wrong_weightage;
  
  public:
    void set_roll_no(int r){roll_no=r;}
    void set_right(int r){right=r;}
    void set_wrong(int w){wrong=w;}
    void setNet_score(int n){net_score=n;}
    static void setRight_weightage(int rw){right_weightage=rw;}
    static void setWrong_weightage(int ww){wrong_weightage=ww;}
   

    int getRoll_no(){return roll_no;}
    int getRight(){return right;}
    int getWrong(){return wrong;}
    int getNet_score(){return net_score;}
    static int getRight_weightage(){return right_weightage;}
    static int getWrong_weightage(){return wrong_weightage;}
};

// Definition of static member outside the class
int TestResult::right_weightage;
int TestResult::wrong_weightage;

void setTestResult(TestResult &t,int r,int right,int wrong)
{
  t.set_roll_no(r);
  t.set_right(right);
  t.set_wrong(wrong);
  t.setNet_score(t.getRight()*t.getRight_weightage()-t.getWrong()*t.getWrong_weightage());
}

void sortbyNetScore(TestResult tr[],int size)
{
  int i,r;
  TestResult temp;
  for(r=1;r<size;r++)
  {
    for(i=0;i<=size-1-r;i++)
    {
      if(tr[i].getNet_score()>tr[i+1].getNet_score())
      {
        temp = tr[i];
        tr[i]=tr[i+1];
        tr[i+1]=temp;

      }
    }
  }
  
}

void display(TestResult tr[],int size)
{
  int i;
  cout<<"Roll_no"<<"  "<<"right"<<"  "<<"wrong"<<"  "<<"net_score"<<endl;
  for(i=0;i<size;i++)
    cout<<tr[i].getRoll_no()<<"  "<<tr[i].getRight()<<"  "<<tr[i].getWrong()<<"  "<<tr[i].getNet_score()<<endl;

}

int f1()
{
  int i,r,right,wrong;
  TestResult tr[5];
  TestResult::setRight_weightage(3);
  TestResult::setWrong_weightage(-1);
  for(i=0;i<5;i++)
  {
    cout<<"Enter details for test result "<<i+1;
    cout<<endl;
    cout<<"Enter roll no: ";
    cin>>r;
    cout<<endl;
    cout<<"How many right answer: ";
    cin>>right;
    cout<<endl;
    cout<<"How many wrong answer: ";
    cin>>wrong;
    setTestResult(tr[i],r,right,wrong);
  }
  
  sortbyNetScore(tr,5);
  display(tr,5);

  return 0;
}

//Define a class matrix of 3*3 provide appropriate  methods and properties of the class:

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
    }
    void showMatrix()
    {
      for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          cout<<A[i][j]<<" ";
        cout<<endl;  
    }  

    Matrix add_matrix(Matrix M)
    {
      Matrix m;
      for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          m.A[i][j] = A[i][j]+M.A[i][j]; 
      return m;    
    }

    Matrix sub_matrix(Matrix M)
    {
      Matrix m;
      for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
          m.A[i][j] = A[i][j]-M.A[i][j]; 
      return m;    
    }

    Matrix multiply_matrix(Matrix M)
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