#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i=0;i<=50;i++)// 0'dan 50'ye kadar d�ng� devam eder.
    {
        if(i%10==0)// i'nin 10'a b�l�m�nden kalan 0 olup olmad���n� kontrol eder.
            continue;// 10'un kat� ise yazmadan sonraki iterasyona ge�er.
        else
            printf("\n%d",i);//10'un kat� de�il ise say�y� bast�r�p alt sat�ra ge�er.
    }
    return 0;
}
