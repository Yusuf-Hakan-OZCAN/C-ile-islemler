#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ay;
    printf("Kacinci ay?(1-12): ");// Hangi ay oldu�unu kullan�c�dan al�r.
    scanf("%d",&ay);

    if (ay>=1 && ay<=12)// Ay de�i�keninin istenilen aral�kta oldu�unu kontrol eder.
    {
        switch(ay)// switch-case yap�s� ile hangi ay oldu�unu kontrol ederek ka� g�n oldu�unu ekrana yazd�r�r.
        {
            case 2:
                printf("Sectiginiz ay 28 gundur.");
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                printf("Sectiginiz ay 30 gundur.");
                break;
            default:
                printf("Sectiginiz ay 31 gundur.");

        }
    }
    else
        printf("Girdiginiz sayi aralik disinda!");// Girilen de�er istenilen aral�kta de�il ise ekrana bast�r�r.
    return 0;
}
