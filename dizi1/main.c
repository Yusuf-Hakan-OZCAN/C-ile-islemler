#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i,j;
    printf("Lutfen dizi uzunlugu giriniz: ");//Kullanıcıdan bir dizi uzunluğu alır.
    scanf("%d",&n);
    int liste[n];//Listeyi alınan değere göre oluşturur.(codeblocksta çalışır diğer compilerlarda çalışmayabilir.)

    for(i=0;i<n;i++)// döngü ile dizi elemanları alır.
    {
        printf("Lutfen dizinin %d. elemanini giriniz: ",i+1);
        scanf("%d",&liste[i]);
    }
    printf("\n\n-----Tersten-----\n");



        for(i=n-1,j=0;i>-1,j<n;i--,j++)//döngü ile listeyi tersten bastırır.
    {
        printf("Yeni dizinin %d. elemani: %d\n",j+1,liste[i]);
    }


    return 0;
}
