#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i=0;i<=50;i++)// 0'dan 50'ye kadar döngü devam eder.
    {
        if(i%10==0)// i'nin 10'a bölümünden kalan 0 olup olmadýðýný kontrol eder.
            continue;// 10'un katý ise yazmadan sonraki iterasyona geçer.
        else
            printf("\n%d",i);//10'un katý deðil ise sayýyý bastýrýp alt satýra geçer.
    }
    return 0;
}
