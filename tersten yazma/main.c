#include <stdio.h>
#include <stdlib.h>

int main()
{
    char dizi[100];
    int i;
    printf("Lutfen bir cumle giriniz: ");
    gets(dizi);// gets ile karakter dizisini al�r.

    for(i=strlen(dizi);i>=0;i--)// sondan ba�a do�ru dizi iterasyona girer.
    {
        printf("%c",dizi[i]);
    }


    return 0;

}
