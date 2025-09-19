#include<iostream>
#include<cmath>
using namespace std;


// WAP to print all prime number between two number: a=4 b=10
void prime_number()
{
  int a,b,n,i;
  cout<<"Enter two number: "<<"\n";
  cin>>a>>b;
  n=a+1;
  while(n<b)
  {
    if(n==2)
      cout<<n<<" ";
    for(i=2;i<=n/2;i++)
    {
      if(n%i==0)
        break;
      else if(i==n/2)
        cout<<n<<" ";
    }
    n++;
  }
}

//WAF to find highest didgit in given number:n=274936,,,cout<<9:

void highest_digit(int n)
{
  int i,max=0;
  while (n>0)
  {
    if(n%10>max)
      max=n%10;
    n=n/10;  
  }
  cout<<"Highest digit is "<<max;
}

//WAF to calculate x raised to the power y:

void y_power_x(int x,int y)
{
  int result=1,i;
  for(i=1;i<=x;i++)
    result=result*y;
  cout<<"y to the power x is = "<<result;  
}

int fact(int n)
{
  int i,fac=1;
  for(i=n;i>=1;i--)
    fac=fac*i;
  return fac;  
}

int combination(int n ,int r)
{
  return fact(n)/fact(r)/fact(n-r);
}

//WAF to print pascal traingle upto N terms:

void pascal_traingle(int lines)
{
  int i,j;
  // cout<<"Enter the number of lines ";
  // cin>>lines;
  for (int i = 0; i < lines; i++)
    {
        // Print spaces
        for (int j = 0; j < lines - i - 1; j++)
            cout << "  ";

        for (int j = 0; j <= i; j++)
            cout << combination(i, j) << "   ";

        cout << endl;
    }
  
}

//// Function to check if x is perfect square
int isperfectSquare(int x)
{
  int s = (int)sqrt(x);
  return(s*s==x);
}

//Function to check if n is Fibonacci:
int isfabonacci(int n)
{
  return (isperfectSquare(5*n*n+4)||isperfectSquare(5*n*n-4));
}


int main()
{
  // prime_number();
  // highest_digit(43765);
  // pascal_traingle(5);
  // if(isfabonacci(21))
  //   cout<<"fabonacci number!";
  // else
  //   cout<<"Not a fabonacci number!";  
  return 0;
}