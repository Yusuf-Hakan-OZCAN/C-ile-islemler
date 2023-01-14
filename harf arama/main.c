#include <stdio.h>
#include <stdlib.h>

int main()
{
    char dizi[100];
    int i;
    int sayac=0;
    char harf;

    printf("Lutfen bir cumle giriniz: ");
    gets(dizi);// gets ile bir char dizisi yani string kullanicidan alinir.

    printf("Aranacak harfi giriniz: ");
    scanf("%c",&harf);

    for(i=0;i<=strlen(dizi);i++)// for dongusu ile cumle icinde dolasir.
    {
        if(dizi[i]==harf)
        {
            sayac++;
            printf("\nAradiginiz harf %d. sirada",i+1);
        }
    }

    printf("\nToplam bulunan harf sayisi: %d",sayac);// sayaca gore istenilen harfin kac defa tekrarlandigini ekrana yazdirir.



    return 0;
}
