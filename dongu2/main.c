#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int i=1;
    int carpim=1;

    printf("Lutfen faktoriyeli alinacak sayiyi giriniz: ");
    scanf("%d",&n);

    while(i<=n)
    {
        carpim*=i;
        i++;
    }

    printf("%d",carpim);
    return 0;
}
