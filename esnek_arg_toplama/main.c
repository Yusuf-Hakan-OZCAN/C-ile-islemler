#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int topla(int n, ...)
{
    va_list listem; //va_list'ten sonra gelen bizim verilerimizin girileceði listenin adýdýr.

    int toplam=0;

    va_start(listem,n); // listem listesinin n. elemanýndan baþlar.

    for(int i=1;i<=n;i++)
    {
        toplam+=va_arg(listem,int); // listemdeki int elemanlari alir.Kullanilmaz ise dongu 1'den baslar n'in sayi degerine kadar gider ve onlari toplama atar.
    }
    va_end(listem); //listem listesini bosaltir.
    return toplam; //maindeki printf yukaridaki topla fonksiyonunu yapar ve return olarak toplami yazdirir yani son durumda **printf("%d",return toplam)** gibi olur.
}



int main()
{
    printf("topla(2,11,12)= %d",topla(2,11,12)); //2 degeri kaç tane sayi toplanacagini belirtir arkasindan gelen sayilar ise toplanir.
    return 0;
}
