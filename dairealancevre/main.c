#include <stdio.h>
#include <stdlib.h>

int main()
{
    float PI=3.14 ;
    int yaricap;
    float alan,cevre;

    printf("Lutfen bir yaricap degeri giriniz: ");// Kullan�c�dan bir yar��ap de�eri al�r.
    scanf("%d",&yaricap);// Kullan�c�dan al�nan de�eri yaricap degiskenine atar.

    cevre=(2*PI*yaricap);// Form�l ile �evre ve alan� bulur.
    alan=(yaricap*yaricap*PI);

    printf("\nCEVRE: %.1f",cevre);// �evre ve alan� ekrana yazd�r�r.
    printf("\nALAN: %.1f",alan);
}
