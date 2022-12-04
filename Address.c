#include<stdio.h>

int main()
{
    int no = 11;

    char ch = 'A';
    
    printf("%d",no);   // 11

    printf("Value of ch : %c\n",ch);   // A

    printf("Address of no is : %u\n",&no);  // 100

    printf("Address of ch is  : %u\n",&ch); // 200

    printf("Size of no is : %d\n",sizeof(no));  // 4

    printf("Size of ch is : %d\n",sizeof(ch));  // 1

    return 0;
}

// Format Specifiers
/*

%d      Signed integer in decimal format
%c      Character
%f      Float data
%u      Unsigned integer
%x      Hexadecimal data
%o      Octal data
%p      Pointer representation
%lf     double
%Lf     Long double
%s      String

*/












