#include <stdio.h>
#include <stdlib.h>

int main()
{
    char dizi[100];
    int i;
    printf("Lutfen bir cumle giriniz: ");
    gets(dizi);// gets ile karakter dizisini alýr.

    for(i=strlen(dizi);i>=0;i--)// sondan baþa doðru dizi iterasyona girer.
    {
        printf("%c",dizi[i]);
    }


    return 0;

}
