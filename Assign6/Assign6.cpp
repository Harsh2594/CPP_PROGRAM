#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;

void sort(int[],int,bool=true);
void sort(char[],int,bool=true);
void rotate_array(int[],int,int=1,int=1);
int lcm(int,int,int);
/* Define a c++ function to sort an array in ascending or descending order depending upon bool type
 argument(true for ascending order and false for descending order) use default argument to implement it:*/

void sort(int arr[],int size,bool asc)
{
  int r,i,temp=0;
  for(r=1;r<size;r++)
    for(i=0;i<=size-r-1;i++)
      if(asc==true && arr[i]>arr[i+1])
      {
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
      }
      else if(asc==false && arr[i]<arr[i+1])
      {
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
      }
}

/* Define a c++ function to sort an array of string in ascending or descending order depending upon bool type
 argument(true for ascending order and false for descending order) use default argument to implement it:*/
void sort(char arr[],int size,bool asc)
{
  int r,i,temp=0;
  for(r=1;r<size;r++)
    for(i=0;i<=size-r-1;i++)
      if(asc==true && arr[i]>arr[i+1])
      {
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
      }
      else if(asc==false && arr[i]<arr[i+1])
      {
        temp=arr[i];
        arr[i]=arr[i+1];
        arr[i+1]=temp;
      }
}

/*Define a function to rotate an array by n positions in the d directon Implement position and direction using
default argument. Argument d can be -1 or 1 denoting left or right direction. Argument n should be the last argument
with default value 1.ex: arr[]={4,3,7,9,3,1,5}------>{3,7,9,3,1,5,4}*/

void rotate_array(int arr[],int size,int d,int n)
{
  int i,r,t;
  if(d==1)
  {
    for(r=1;r<=n;r++)
      t = arr[size-1];
      for(i=size-1;i>0;i--)
        arr[i]=arr[i-1];
      arr[0]=t; 
  }    
  else if(d==-1)
  {
    for(r=1;r<=n;r++)
      t = arr[0];
      for(i=0;i<size-1;i++)
        arr[i]=arr[i+1];
      arr[size-1]=t; 
  }
}

//GCD(HCF of two number)
int gcd(int a,int b)
{
  int temp;
  while(b!=0)
  {
    temp=b;
    b = a%b;
    a =temp;
  }
  return a;
}
//LCM of two number:
int lcm(int a,int b)
{
  return (a*b)/gcd(a,b);
}

//WAF to calculate lcm of three numbers using HCF:
int lcm_of_three(int a,int b,int c)
{
  return lcm(lcm(a,b),c);
}

////WAF to calculate lcm of three numbers:
int lcm_of_three_without_gcd(int a,int b,int c)
{
  int L;
  for(L=(a>b)?(a>c?a:c):(b>c?b:c);L<=a*b*c;L++)
    if(L%a==0&&L%b==0&&L%c==0)
      return L;
}

//Define a function to print all prime_factor of a number:
void prime_factor(int n)
{
  int i;
  for(i=2;i<=n;i++)
  {
    while(n%i==0)
    {
      n = n/i;
      cout<<i<<",";
    }
    if(n==1)
      break;
  }
}


int main()
{
  char arr[]="harshpratap",i;
  sort(arr,sizeof(arr));
  for(i=0;i<sizeof(arr);i++)
    cout<<arr[i]<<" ";
}