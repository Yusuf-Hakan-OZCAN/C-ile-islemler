#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x,y,toplam,fark,carpim,bolum;

    printf("x giriniz: ");
    scanf("%f",&x);
    printf("y giriniz: ");
    scanf("%f",&y);

    toplam= (x+y);
    fark= (x-y);
    carpim= (x*y);
    bolum= (x/y);

    printf("\n%.2f + %.2f = %.2f \n",x,y,toplam);
    printf("%.2f - %.2f = %.2f \n",x,y,fark);
    printf("%.2f x %.2f = %.4f \n",x,y,carpim);
    printf("%.2f / %.2f = %.6f \n",x,y,bolum);

}
