#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    printf("x degeri giriniz: ");
    scanf("%d",&x);

    if (x%2==0)
        printf("%d cifttir.",x);
    else
        printf("%d tektir.",x);

    return 0;
}
