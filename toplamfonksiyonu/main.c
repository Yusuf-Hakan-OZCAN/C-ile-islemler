#include <stdio.h>
#include <stdlib.h>


int topla(int a,int b) // topla isimli bir fonk. acilir ve iki tane integer deger almasi gerekir.
{
    int toplam;
    toplam=a+b;
    return toplam; // en son olarak toplam degeri dondurur.
}

int main()
{
    int a,b;
    printf("Lutfen toplanacak 2 deger giriniz: ");
    scanf("%d %d",&a,&b);

    printf("%d + %d = %d",a,b,topla(a,b));
    return 0;
}
