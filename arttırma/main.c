#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    a=5;
    b,c=0;

    printf("a= %d\n",a); //a deðerini ekrana yazar.

    b= a++; //a'nýn ilk deðerini b'ye atayýp a'yý 1 arttýrýr.
    printf("a= %d , b= %d\n",a,b); //a,b deðerini ekrana yazar.

    c= ++a; //a'yý 1 arttýrýp yeni deðeri c'ye atar.
    printf("a= %d , b= %d , c=%d",a,b,c); //a,b,c deðerini ekrana yazar.

}
