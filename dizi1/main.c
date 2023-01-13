#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    printf("Lutfen dizi uzunlugu giriniz: ");//Kullanýcýdan bir dizi uzunluðu alýr.
    scanf("%d",&n);
    int liste[n];//Listeyi alýnan deðere göre oluþturur.(codeblocksta çalýþýr diðer compilerlarda çalýþmayabilir.)

    for(i=0;i<n;i++)// döngü ile dizi elemanlarý alýr.
    {
        printf("Lutfen dizinin %d. elemanini giriniz: ",i+1);
        scanf("%d",&liste[i]);
    }
    printf("\n\n-----Tersten-----\n");



        for(i=n-1,j=0;i>-1,j<n;i--,j++)//döngü ile listeyi tersten bastýrýr.
    {
        printf("Yeni dizinin %d. elemani: %d\n",j+1,liste[i]);
    }


    return 0;
}
