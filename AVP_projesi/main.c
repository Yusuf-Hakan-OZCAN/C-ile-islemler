#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdarg.h>


void cevap_anahtari_uret(int S, char cevap_anahtari[])
{
    srand(time(0)); //sistem saatine gore rastgele bir sayi alir.
    for(int i=0;i<S;i++)
    {
        cevap_anahtari[i]= (rand()%5)+1; //Alinan rastgele sayinin 5'e gore modu alinip 1 eklenerek 1-5 araliginda olmasi saglanir ve cevap anahtarinin i indisli elemanina atanir.
        switch(cevap_anahtari[i])   //switch case ile atadigi sayiya göre elemani bir harfe donusturur.
        {
            case 1:
                cevap_anahtari[i]= 'A';
                break;
            case 2:
                cevap_anahtari[i]= 'B';
                break;
            case 3:
                cevap_anahtari[i]= 'C';
                break;
            case 4:
                cevap_anahtari[i]= 'D';
                break;
            default:
                cevap_anahtari[i]= 'E'; //Cevap anahtarinda bos soru birakilamayacagi icin X yoktur.
        }
    }
}
void cevap_anahtari_yazdir(int S, char cevap_anahtari[])
{
    printf("\nCevap anahtari: \n");
    for(int i=0;i<S;i++)
    {
        printf("%.3d: %c |",i+1,cevap_anahtari[i]);
    }
printf("\n\n");
}
void ogrenci_cevabini_yazdir(char ogrenci_cevaplari[][100], int ogrenci_ID, int S)
{
    printf("%.3d. ogrencinin cevaplari:\n",ogrenci_ID+1); //main'de actigimiz for dongusu ile ogrenci ID toplam ogrenci sayisina kadar gider.
    for(int z=0;z<S;z++)
    {
        printf("%.3ld: %c |",z+1,ogrenci_cevaplari[ogrenci_ID][z]); //ic dongu ile de ogrenci cevaplari yazdirilir.
    }
printf("\n");
}
void sinavi_uygula(char ogrenci_cevaplari[][100], char cevap_anahtari[], int N, int S, double B, double D)
{
 srand(time(0));// rastgele bir sayi alinir.
 int geri_kalan=100-100*D; //dogru yapma orani 100 ile carpilarak bir tam sayi olarak dusunulur.100'den cikarilarak da yanlis ve bos sayisi tam sayi olarak bulunabilir.
 for(int i=0;i<N;i++)//ogrenci cevaplari matrisinde satirlar yani ogrencileri temsil eder.Dis dongudur.
 {
     for(int j=0;j<S;j++)//ogrenci cevaplari matrisinde sutunlar yani soru cevaplarini temsil eder. Ic dongudur.
     {
    switch((rand()%6)+1)//Alinan rastgele sayinin 6'ya gore modu alinip 1 eklenir ve deger araligi 1-6 arasinda olur.Degerlere gore de ogrenci cevaplarina bir harf atanir.
        {
            case 1:
                ogrenci_cevaplari[i][j]= 'A';
                break;
            case 2:
                ogrenci_cevaplari[i][j]= 'B';
                break;
            case 3:
                ogrenci_cevaplari[i][j]= 'C';
                break;
            case 4:
                ogrenci_cevaplari[i][j]= 'D';
                break;
            case 5:
                ogrenci_cevaplari[i][j]= 'E';
                break;
            default:
                ogrenci_cevaplari[i][j]= 'X';//Ogrenciler sorulari bos birakabileceginden cevap anahtarindan farkli olarak X de eklenmelidir.
        }
        if((rand()%100)+1<=D*100)//rastgele alinan sayinin 100'e gore modunun bir fazlasi ile 1-100 arasinda bir deger alinir. Dogru yapma orani 100 ile carpilir. rastgele alinan sayi dogrudan kucuk veya esitse dogru gibi kabul edilir.
         {
             ogrenci_cevaplari[i][j]=cevap_anahtari[j];//if saglanir ise ogrenci cevaplari[i][j]'nin ne olduguna bakilmaksizin cevap anahtarindan dogru harf cekilir.Soru dogru yapilmis olur.
         }
        else if(rand()%geri_kalan<=B*100)//rastgele sayinin dogrulardan geri kalan sayi kadar modu alinir.Ornegin(100soru-60dogru=40).40 soru yanlis ve bos sayi toplamidir.Bu sayi 100 ile bos yapma oranindan kucukse o soru bosmus gibi kabul edilir.
        {
            ogrenci_cevaplari[i][j]='X';//Bos kabul edilen cevaba bos manasina gelen X harfi atanir.
        }
     }
 }
}
void ogrencileri_puanla(char ogrenci_cevaplari[][100], char cevap_anahtari[], double HBN[], int N, int S)
{
    int yanlis_sayisi=0;
    int bos_sayisi=0;
    double soru_puani=100.0/S;//Soru basina dusen soru puani bulunur.
    for(int i=0;i<N;i++)//her ogrencide farkli HBN olacagindan her dis donguye geri dondugunde yanlis ve bos sayisi sifirlanmalidir.Dis dongu ogrenci sayisi kadar calisir.
    {
        yanlis_sayisi=0;
        bos_sayisi=0;
        for(int j=0;j<S;j++)//ic dongu soru sayisi kadar calisir.
        {
            if(ogrenci_cevaplari[i][j]=='X')//Cevap X yani bos ise bos_sayisi sayacini arttirir dongunun sonunda bize o ogrencinin kac bosu oldugunu verir.
                bos_sayisi++;
            else if(ogrenci_cevaplari[i][j]!=cevap_anahtari[j] && ogrenci_cevaplari[i][j]!='X')//Cevap yanlis ise yanlis_sayisi sayacini arttırır.ogrencinin kac yanlisi oldugunu verir.
                yanlis_sayisi++;
        }
        HBN[i]= (S-((yanlis_sayisi*1.25)+bos_sayisi))*soru_puani;//yanlis sayisi ile 1.25'i carparsak bize yanlis netini verir onu bos ile toplayip toplam soru sayisindan cikarirsak bize dogru net sayisini verir.
        if (HBN[i]<0)                                           //En son olarak dogru sayisi ile soru puani carpilarak HBN bulunur.
            HBN[i]=0;// HBN'nin eksi deger cikmasi goz onunde bulundurulur ve eksi deger cikmasi halinde 0'a atanir.
    }
}
double sinif_ortalamasi_hesapla(double HBN[], int N)
{
    double ortalama=0.0;
    double toplam=0.0;
    for(int i=0;i<N;i++)
    {
        toplam+=HBN[i];//Butun ogrencilerin HBN'leri for dongusu kullanilarak bir degiskene double olarak atanir.
    }
    ortalama=toplam/N;//Double toplam ogrenci sayisina bolunerek tum sinifin ortalamasi bulunur.
    printf("\nSinif ortalamasi: %.2f\n",ortalama);
    return ortalama;
}
double standart_sapma_hesapla(double ortalama, double HBN[], int N)
{
    double std=0.0;
    double toplam=0.0;
    for(int i=0;i<N;i++)
    {
        toplam+=pow(HBN[i]-ortalama,2);//pow fonksiyonu ile  HBN[i]-ortalama'nin karesi alinir ve dongu ile toplam degiskenine atanir.
    }
    std=pow(toplam/N,0.5);//Toplam degeri ogrenci sayisina bolunerek karekoku alinir ve standart sapma hesaplanmis olur.
    printf("Standart sapma: %.2lf\n",std);
    if(ortalama<=100.0 && ortalama>80.0)//sinif ortalamasini bir araliga alarak sinif duzeyini belirler.
        printf("Sinif duzeyi: Ustun Basari\n");
    else if(ortalama<=80.0 && ortalama>70.0)
        printf("Sinif duzeyi: Mukemmel\n");
    else if(ortalama<=70.0 && ortalama>62.5)
        printf("Sinif duzeyi: Cok Iyi\n");
    else if(ortalama<=62.5 && ortalama>57.5)
        printf("Sinif duzeyi: Iyi\n");
    else if(ortalama<=57.5 && ortalama>52.5)
        printf("Sinif duzeyi: Ortanin Ustu\n");
    else if(ortalama<=52.5 && ortalama>47.5)
        printf("Sinif duzeyi: Orta\n");
    else if(ortalama<=47.5 && ortalama>42.5)
        printf("Sinif duzeyi: Zayif\n");
    else if(ortalama<=42.5 && ortalama>=0.0)
        printf("Sinif duzeyi: Kotu\n");
    return std;
}
void T_skoru_hesapla(double ortalama, double HBN[], int N, double std, double T_skoru[])
{
    for(int i=0;i<N;i++)
    {
        T_skoru[i]=(((HBN[i]-ortalama)/std)*10)+60;
    }
}
void ogrenci_harf_notu(double T_skoru[], double ortalama, char harf_notu[][3],int N)
{
    if(ortalama<=100.0 && ortalama>80.0) //ortalama degiskeninin degerine gore bir araliga girer ve ogrencilerin T skoruna gore icerisinde harf notlarinin tutulacagi bir char dizisine atanir.
        {
            for(int i=0;i<N;i++)//Her ogrenciye matriste 2 yer atanir. Misal 1. ogrenciye harf_notu[0][0] ve harf_notu[0][1].Sonrasinda ikisi de yazdirilarak ogrencinin harf notu bulunur.
            {
                if(T_skoru[i]<32){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="F";
                }
                else if(T_skoru[i]>=32 && T_skoru[i]<37){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=37 && T_skoru[i]<42){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=42 && T_skoru[i]<47){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=47 && T_skoru[i]<52){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=52 && T_skoru[i]<57){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=57 && T_skoru[i]<62){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=62 && T_skoru[i]<67){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="A";
                }
                else{
                    harf_notu[i][0]="A";
                    harf_notu[i][1]="A";
                }
            }
        }
    else if(ortalama<=80.0 && ortalama>70.0)
                {
            for(int i=0;i<N;i++)
            {
                if(T_skoru[i]<34){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="F";
                }
                else if(T_skoru[i]>=34 && T_skoru[i]<39){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=39 && T_skoru[i]<44){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=44 && T_skoru[i]<49){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=49 && T_skoru[i]<54){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=54 && T_skoru[i]<59){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=59 && T_skoru[i]<64){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=64 && T_skoru[i]<69){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="A";
                }
                else{
                    harf_notu[i][0]="A";
                    harf_notu[i][1]="A";
                }
            }
        }

    else if(ortalama<=70.0 && ortalama>62.5)
                {
            for(int i=0;i<N;i++)
            {
                if(T_skoru[i]<36){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="F";
                }
                else if(T_skoru[i]>=36 && T_skoru[i]<41){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=41 && T_skoru[i]<46){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=46 && T_skoru[i]<51){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=51 && T_skoru[i]<56){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=56 && T_skoru[i]<61){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=61 && T_skoru[i]<66){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=66 && T_skoru[i]<71){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="A";
                }
                else{
                    harf_notu[i][0]="A";
                    harf_notu[i][1]="A";
                }
            }
        }
    else if(ortalama<=62.5 && ortalama>57.5)
            {
            for(int i=0;i<N;i++)
            {
                if(T_skoru[i]<38){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="F";
                }
                else if(T_skoru[i]>=38 && T_skoru[i]<43){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=43 && T_skoru[i]<48){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=48 && T_skoru[i]<53){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=53 && T_skoru[i]<58){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=58 && T_skoru[i]<63){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=63 && T_skoru[i]<68){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=68 && T_skoru[i]<73){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="A";
                }
                else{
                    harf_notu[i][0]="A";
                    harf_notu[i][1]="A";
                }
            }
        }
    else if(ortalama<=57.5 && ortalama>52.5)
            {
            for(int i=0;i<N;i++)
            {
                if(T_skoru[i]<40){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="F";
                }
                else if(T_skoru[i]>=40 && T_skoru[i]<45){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=45 && T_skoru[i]<50){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=50 && T_skoru[i]<55){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=55 && T_skoru[i]<60){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=60 && T_skoru[i]<65){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=65 && T_skoru[i]<70){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=70 && T_skoru[i]<75){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="A";
                }
                else{
                    harf_notu[i][0]="A";
                    harf_notu[i][1]="A";
                }
            }
        }
    else if(ortalama<=52.5 && ortalama>47.5)
            {
            for(int i=0;i<N;i++)
            {
                if(T_skoru[i]<42){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="F";
                }
                else if(T_skoru[i]>=42 && T_skoru[i]<47){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=47 && T_skoru[i]<52){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=52 && T_skoru[i]<57){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=57 && T_skoru[i]<62){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=62 && T_skoru[i]<67){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=67 && T_skoru[i]<72){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=72 && T_skoru[i]<77){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="A";
                }
                else{
                    harf_notu[i][0]="A";
                    harf_notu[i][1]="A";
                }
            }
        }
    else if(ortalama<=47.5 && ortalama>42.5)
            {
            for(int i=0;i<N;i++)
            {
                if(T_skoru[i]<44){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="F";
                }
                else if(T_skoru[i]>=44 && T_skoru[i]<49){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=49 && T_skoru[i]<54){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=54 && T_skoru[i]<59){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=59 && T_skoru[i]<64){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=64 && T_skoru[i]<69){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=69 && T_skoru[i]<74){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=74 && T_skoru[i]<79){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="A";
                }
                else{
                    harf_notu[i][0]="A";
                    harf_notu[i][1]="A";
                }
            }
        }
    else if(ortalama<=42.5 && ortalama>=0.0)
            {
            for(int i=0;i<N;i++)
            {
                if(T_skoru[i]<46){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="F";
                }
                else if(T_skoru[i]>=46 && T_skoru[i]<51){
                    harf_notu[i][0]="F";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=51 && T_skoru[i]<56){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="D";
                }
                else if(T_skoru[i]>=56 && T_skoru[i]<61){
                    harf_notu[i][0]="D";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=61 && T_skoru[i]<66){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="C";
                }
                else if(T_skoru[i]>=66 && T_skoru[i]<71){
                    harf_notu[i][0]="C";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=71 && T_skoru[i]<76){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="B";
                }
                else if(T_skoru[i]>=76 && T_skoru[i]<81){
                    harf_notu[i][0]="B";
                    harf_notu[i][1]="A";
                }
                else{
                    harf_notu[i][0]="A";
                    harf_notu[i][1]="A";
                }
            }
        }
}
void ogrenci_istatistik_yazdir(double HBN[], double T_skoru[], char harf_notu[][3], int N)
{
    printf("\nOgrenci notlari:\n");
    for(int i=0;i<N;i++)
    {
        printf("%.3d. ogrencinin HBN: %.2lf, T-skoru: %.2lf, Harf notu: %c%c\n",i+1,HBN[i],T_skoru[i],harf_notu[i][0],harf_notu[i][1]);
    }
}
int main()
{
    int N,S;
    float B,D;

    printf("Ogrenci sayisi giriniz(max 100): ");
    scanf("%d",&N);
    if(N>100 || N<0)
    {
        printf("Yanlis ogrenci sayisi girdiniz!\n");
        return 1;
    }

    printf("Soru sayisi giriniz(max 100): ");
    scanf("%d",&S);
    if(S>100 || S<0)
    {
        printf("Yanlis soru sayisi girdiniz!\n");
        return 2;
    }

    printf("Sorunun bos birakilma ihtimali (0-1 araliginda): ");
    scanf("%f",&B);
    if(B<0 || B>1)
    {
        printf("Girdiginiz deger istenilen aralikta degil!");
        return 3;
    }
    printf("Sorunun dogru cevaplanma ihtimali (0-1 araliginda): ");
    scanf("%f",&D);
    if(D<0 || D>1)
    {
        printf("Girdiginiz deger istenilen aralikta degil!");
        return 4;
    }


    char CA[S]; //Cevap anahtari dizisi soru sayisi ile sinirlandirilacak sekilde tanimlanir.
    char o[100][100]; // Max 100'e 100luk bir matris alır ve satirlari ogrenci ,sutunlari ise ogrencilerin girdikleri cevaplar olacak sekilde bir matris olusturur.
    cevap_anahtari_uret(S,CA);
    cevap_anahtari_yazdir(S,CA);
    sinavi_uygula(o,CA,N,S,B,D);

    for(int i=0;i<N;i++)
    {
        ogrenci_cevabini_yazdir(o,i,S);// for dongusu ile ogrenci ID i'ymiş gibi dusunulur.Ogrenci sayisi kadar dongu doner.
    }
    double HBN[N];//Ham basari notu dizisi ogrenci sayisi ile sinirlandirilacak sekilde tanimlanir.
    double T_skoru[N];//T skoru dizisi ogrenci sayisi ile sinirlandirilacak sekilde tanimlanir.
    double ortalama;//sinif ortalamasinin atanacagi bir ortalama degiskeni tanimlanir.
    double std;//standart sapmanin atanacagi bir std degiskeni tanimlanir.
    char harf_notu[N][3];//harf notu matrisi ogrenci sayisi ile sinirlandirilacak sekilde ogrencilerin harf notunu tutar.
    ogrencileri_puanla(o,CA,HBN,N,S);
    ortalama=sinif_ortalamasi_hesapla(HBN,N); //ortalama hesaplama fonk ile dondurulen ort degerini ortalama degiskenine atar ve ekrana yazdirir.
    std=standart_sapma_hesapla(ortalama,HBN,N);//fonksiyon ile standart sapma hesaplanir ve std degiskenine atanir.
    T_skoru_hesapla(ortalama,HBN,N,std,T_skoru);//fonksiyonu ile t skoru hesaplanip fonksiyon icerisindeki T_skoru dizisine atanir.
    ogrenci_harf_notu(T_skoru,ortalama,harf_notu,N);
    ogrenci_istatistik_yazdir(HBN,T_skoru,harf_notu,N);//ogrencilerin hepsinin teker teker HBN,T skoru ve harf notu yazdirilir.
    return 0;
}
