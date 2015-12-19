/*mergesort*/
#include <iostream>
using namespace std;

// To execute C++, please define "int main()"
void merge(int a[],int low, int mid, int high)
{
  int len=high-low+1;
  int *b=new int[len];
  int i=low;
  int j=mid+1;
  int k=low;
  while(i<=mid && j<=high)
  {
    if(a[i]<=a[j])
    {
      b[k]=a[i];
      i++;
    }
    else
    {
      b[k]=a[j];
      j++;
    }
    k++;
  }
  while(i<=mid)
  {
    b[k]=a[i];
    i++;
    k++;
  }
  while(j<=high)
  {
    b[k]=a[j];
    j++;
    k++;
  }
  for(int l=low;l<=high;l++)
  {
    a[l]=b[l];    
  }
}
void mergesort(int a[],int low, int high)
{
  if(low<high)
  {
    int mid=(low+high)/2;
    mergesort(a,low,mid);
    mergesort(a,mid+1,high);
    merge(a,low,mid,high);
  }
}
void printArray(int a[],int len)
{  
  
  for(int i=0;i<len;i++)
  {
    printf("%d\t",a[i]);
  }
}
int main() {
  int a[]={8,7,6,5,4,3};
  mergesort(a,0,5);
  int len=sizeof(a)/sizeof(a[0]);
  printArray(a,len);
  return 0;
}
