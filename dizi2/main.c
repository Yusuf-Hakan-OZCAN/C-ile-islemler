#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,i;
    int toplam=0;

    printf("Lutfen dizi uzunlugu giriniz: ");// dizi uzunlugu alir.
    scanf("%d",&n);
    int liste[n];// uzunluga göre liste olusturur.

    for(i=0;i<n;i++)// dongu ile listeye eleman atar.
    {
        printf("Dizinin %d. elemanini giriniz: ",i+1);
        scanf("%d",&liste[n]);
        toplam+=liste[n];// atanan elemanlari toplam adli degisken ile her iterasyonda toplar.
    }
    printf("\nToplam: %d",toplam);// toplami ekrana bastirir.
    return 0;
}
