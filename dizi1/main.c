#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    printf("Lutfen dizi uzunlugu giriniz: ");//Kullan�c�dan bir dizi uzunlu�u al�r.
    scanf("%d",&n);
    int liste[n];//Listeyi al�nan de�ere g�re olu�turur.(codeblocksta �al���r di�er compilerlarda �al��mayabilir.)

    for(i=0;i<n;i++)// d�ng� ile dizi elemanlar� al�r.
    {
        printf("Lutfen dizinin %d. elemanini giriniz: ",i+1);
        scanf("%d",&liste[i]);
    }
    printf("\n\n-----Tersten-----\n");



        for(i=n-1,j=0;i>-1,j<n;i--,j++)//d�ng� ile listeyi tersten bast�r�r.
    {
        printf("Yeni dizinin %d. elemani: %d\n",j+1,liste[i]);
    }


    return 0;
}
