#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sayi,kalan=1;
    int i=2;
    printf("Lutfen bir sayi giriniz: "); //Kullan�c�dan bir tam sayi de�eri al�r.
    scanf("%d",&sayi); //Ald��� de�eri sayi de�i�kenine atar.

    for(i;i<sayi;i++){ //2'den ba�lay�p say�n�n kendisi dahil olmayacak �ekilde say�ya kadar d�ng� devam eder.
        if (sayi%i==0){ //sayi'nin i'ye b�l�m�nden kalan 0 ise (yani tam b�l�n�yor) sayi asal de�ildir.
            kalan=0;
            break;

        }
    }

    if (kalan==0 || sayi<=1) //kalan kontrolc�s� 0 ise say� asal de�ildir.
        printf("%d asal degildir.",sayi); //Sayi' ekrana bast�r�r.
    else //kalan kontrolc�s� 1 ise say� asald�r.
        printf("%d asaldir.",sayi); //Sayi' ekrana bast�r�r.


}
