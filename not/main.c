#include <stdio.h>
#include <stdlib.h>

int main()
{
   float odev1,odev2,odev3,quiz1,quiz2,quiz3,sinav1,sinav2,final1,asilnot;

   printf("birinci odev notunu giriniz: ");
   scanf("%f",&odev1);
   printf("\nikinci odev notunu giriniz: ");
   scanf("%f",&odev2);
   printf("\nucuncu odev notunu giriniz: ");
   scanf("%f",&odev3);

   printf("\nbirinci quiz notunu giriniz: ");
   scanf("%f",&quiz1);
   printf("\nikinci quiz notunu giriniz: ");
   scanf("%f",&quiz2);
   printf("\nucuncu quiz notunu giriniz: ");
   scanf("%f",&quiz3);

   printf("\nbirinci ara sinav notunu giriniz: ");
   scanf("%f",&sinav1);
   printf("\nikinci ara sinav notunu giriniz: ");
   scanf("%f",&sinav2);

   printf("\nfinal notunu giriniz: ");
   scanf("%f",&final1);

   asilnot= ((odev1+odev2+odev3)*0.09)+((quiz1+quiz2+quiz3)*0.21)+((sinav1+sinav2)*0.30)+(final1*0.40);
   printf("Donem sonu notunuz: %.1f",asilnot);



}
