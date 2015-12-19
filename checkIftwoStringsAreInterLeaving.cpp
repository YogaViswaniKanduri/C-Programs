#include <iostream>
using namespace std;

// To execute C++, please define "int main()"
int isInterLeaving(const char *a,const char *b,const char *c)
{
  int res=0;
  if(!*c)
    return 1;
  if(*a && *a==*c)
    res=isInterLeaving(a+1,b,c+1);
  if(res==0 && *b && *b==*c)
    res=isInterLeaving(a,b+1,c+1);
  return res;
}

int main() {
  if(isInterLeaving("AB","CD","ACBD"))
  {
    printf("\n the given strings are interleaving");
    
  }
  else
    printf("\n the given strings are not interleaving");
  return 0;
}
