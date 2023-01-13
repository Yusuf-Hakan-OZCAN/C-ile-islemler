#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ay;
    printf("Kacinci ay?(1-12): ");// Hangi ay olduðunu kullanýcýdan alýr.
    scanf("%d",&ay);

    if (ay>=1 && ay<=12)// Ay deðiþkeninin istenilen aralýkta olduðunu kontrol eder.
    {
        switch(ay)// switch-case yapýsý ile hangi ay olduðunu kontrol ederek kaç gün olduðunu ekrana yazdýrýr.
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
        printf("Girdiginiz sayi aralik disinda!");// Girilen deðer istenilen aralýkta deðil ise ekrana bastýrýr.
    return 0;
}
