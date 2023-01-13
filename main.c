#include <stdio.h>
#include <stdlib.h>

int main()
{
    int bassayi,bitsayi,sayac;
    int toplam=0;

    printf("Baslangic degerini giriniz: ");// baslangic degeri alir.
    scanf("%d",&bassayi);
    printf("Bitis degerini giriniz: ");// bitis degeri alir.
    scanf("%d",&bitsayi);

    for(sayac=bassayi ; sayac<=bitsayi ; sayac++){// dongu ile baslangictan sona kadar olan sayilari toplar.
        toplam= toplam+sayac;
    }
    printf("Toplam: %d\n",toplam);// toplami bastirir.
}
