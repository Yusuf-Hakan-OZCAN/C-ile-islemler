#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi,kalan=1;
    int i=2;
    printf("Lutfen bir sayi giriniz: "); //Kullanýcýdan bir tam sayi deðeri alýr.
    scanf("%d",&sayi); //Aldýðý deðeri sayi deðiþkenine atar.

    for(i;i<sayi;i++){ //2'den baþlayýp sayýnýn kendisi dahil olmayacak þekilde sayýya kadar döngü devam eder.
        if (sayi%i==0){ //sayi'nin i'ye bölümünden kalan 0 ise (yani tam bölünüyor) sayi asal deðildir.
            kalan=0;
            break;

        }
    }

    if (kalan==0 || sayi<=1) //kalan kontrolcüsü 0 ise sayý asal deðildir.
        printf("%d asal degildir.",sayi); //Sayi' ekrana bastýrýr.
    else //kalan kontrolcüsü 1 ise sayý asaldýr.
        printf("%d asaldir.",sayi); //Sayi' ekrana bastýrýr.


}
