#include <stdio.h>
#include <stdlib.h>

int main()
{
    float PI=3.14 ;
    int yaricap;
    float alan,cevre;

    printf("Lutfen bir yaricap degeri giriniz: ");// Kullanýcýdan bir yarýçap deðeri alýr.
    scanf("%d",&yaricap);// Kullanýcýdan alýnan deðeri yaricap degiskenine atar.

    cevre=(2*PI*yaricap);// Formül ile çevre ve alaný bulur.
    alan=(yaricap*yaricap*PI);

    printf("\nCEVRE: %.1f",cevre);// Çevre ve alaný ekrana yazdýrýr.
    printf("\nALAN: %.1f",alan);
}
