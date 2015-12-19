#include <iostream>
using namespace std;

// To execute C++, please define "int main()"
void printParantheses(int left_count,int right_count,char * c,int index)
{
  if(left_count==0 && right_count==0){
    c[index]='\0';
    printf("%s\n",c);
    return;
  }
    
  if(left_count)
  {
    c[index]='(';
    printParantheses(left_count-1,right_count,c,index+1);
  }
  if(right_count>left_count)
  {
    c[index]=')';
    printParantheses(left_count,right_count-1,c,index+1);
  }
  
}

int main() {
  int num=3;
  int left_count=num;
  int right_count=num;
  char *c= new char[left_count+right_count];
  printParantheses(left_count,right_count,c,0);
  return 0;
}
