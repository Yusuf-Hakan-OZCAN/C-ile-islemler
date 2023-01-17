#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ay[10];
    printf("Lutfen ayin ismini giriniz:");
    gets(ay);// gets komutu ile char dizisini for kullanmadan aliriz.

    if(!strcmp(ay,"Ocak"))// strcmp iki stringi karsilastirir. Ayný ise 0 ; farklý ise 1 degeri dondurur. Bu yüzden basina "!" konularak tam tersi alinir.
        printf("Ocak 31 gundur.");
    else if(!strcmp(ay,"Subat"))
        printf("Subat 28 gundur.");
    else if(!strcmp(ay,"Mart"))
        printf("Mart 31 gundur.");
    else if(!strcmp(ay,"Nisan"))
        printf("Nisan 30 gundur.");
    else if(!strcmp(ay,"Mayis"))
        printf("Mayis 31 gundur.");
    else if(!strcmp(ay,"Haziran"))
        printf("Haziran 30 gundur.");
    else if(!strcmp(ay,"Temmuz"))
        printf("Temmuz 31 gundur.");
    else if(!strcmp(ay,"Agustos"))
        printf("Agustos 31 gundur.");
    else if(!strcmp(ay,"Eylul"))
        printf("Eylul 30 gundur.");
    else if(!strcmp(ay,"Ekim"))
        printf("Ekim 31 gundur.");
    else if(!strcmp(ay,"Kasim"))
        printf("Kasim 30 gundur.");
    else if(!strcmp(ay,"Aralik"))
        printf("Aralik 31 gundur.");
    return 0;
}
