#include <iostream>
using namespace std;
#include<stdlib.h>
void sub_string(char[],int,int,int = -1);

// find hcf of two number:Remainder method:
int gcd(int a, int b)
{
  int temp;
  while (b != 0)
  {
    temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

int hcf(int a, int b)
{
  int S;
  for (S = (a < b ? a : b); S >= 2; S--)
    if (a % S == 0 && b % S == 0)
      return S;
}

//Define a function to print a substring from stratIndex(inclusive) and endIndex(exclusive).
//Define a function in way that if second argument is not provided,string will print till the last possibel Index:

void sub_string(char arr[],int size,int start_index,int end_index)
{
  int i;
  if(end_index==-1)
    end_index=sizeof(arr);
  for(i=start_index;i<end_index;i++)
    cout<<arr[i];
}

//Write a function to swap two array:
void swap_array(int a[],int b[],int size)
{ 
  int t;
  for(int i=0;i<size;i++)
  {
    t=a[i];
    a[i]=b[i];
    b[i]=t;
  }
}

//Define a function to merge two sorted arrays of same size;

int* merge_array(int a[],int b[],int size)
{
  int *arr = (int*)malloc(2*size*sizeof(int));
  int i,j,k;
  for(i=0,j=0,k=0;i<size&&j<size;k++)
  {
    if(a[i]<b[j])
    {
      arr[k]=a[i];
      i++;
      
    }
    else
    {
      arr[k]=b[j];
      j++;
      
    }
    
  }
  while(i<size)
  {
    arr[k]=a[i];
    i++;
    k++;
  }
  while(j<size)
  {
    arr[k]=a[j];
    j++;
    k++;
  }
}





int main()
{
  char arr[]="harshpratap singh";
  // cout<<gcd(12,18);
  sub_string(arr,sizeof(arr),4,10);
  return 0;
}