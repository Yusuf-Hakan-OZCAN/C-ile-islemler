#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,toplam=0;

    while (i!=0){// while dongusu ile i=0 olana kadar sayi almaya devam eder.
    printf("Bir sayi giriniz: ");
    scanf("%d",&i);
    toplam+=i;// her iterasyonda aldigi sayilari toplam degiskeni ile toplar.
    }

    printf("Toplaminiz: %d",toplam);// toplami yazdirir.

    return 0;
}
