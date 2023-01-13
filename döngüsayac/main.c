#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main()
{

    for(int d=0;d<=59;d++)
    {
        for(int s=0;s<=59;s++)
        {
            printf("%02d.%02d\r",d,s);
            Sleep(1000);
        }
    }



    return 0;
}
