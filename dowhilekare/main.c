#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi,kare;

    do{
            printf("Bir sayi degeri giriniz: ");
            scanf("%d",&sayi);
            kare=(sayi*sayi);
            printf("%d\n",kare);
    }while(sayi!=0);

    return 0;
}
