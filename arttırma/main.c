#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    a=5;
    b,c=0;

    printf("a= %d\n",a); //a de�erini ekrana yazar.

    b= a++; //a'n�n ilk de�erini b'ye atay�p a'y� 1 artt�r�r.
    printf("a= %d , b= %d\n",a,b); //a,b de�erini ekrana yazar.

    c= ++a; //a'y� 1 artt�r�p yeni de�eri c'ye atar.
    printf("a= %d , b= %d , c=%d",a,b,c); //a,b,c de�erini ekrana yazar.

}
