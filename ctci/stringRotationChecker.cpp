#include<iostream>
#include<string.h>

bool checkRotation(char str1[],char str2[])
{
    if(strlen(str1)!=strlen(str2))
        return false;
    str1=strcat(str1,str1);
    if(strstr(str1,str2))
        return true;
    return false;
}

int main()
{
    char str1[]="erbottlewat";
    char str2[]="waterbottle";
    printf("%s",checkRotation(str1,str2)?"true":"false");
    return 0;
}
/*Output:
true
*/