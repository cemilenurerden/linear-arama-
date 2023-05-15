#include <stdio.h>

int dogrusalArama(int dizi[], int boyut, int aranan_eleman) {  //.fonksiyon tanýmladým. bu fonksiyon, bir dizide arama yapar ve aranan elemanýn dizideki indeksini döndürür.
    for (int i = 0; i < boyut; i++) {
        if (dizi[i] == aranan_eleman) {  // eðer dizimiz aradýðýmýz elemana eþitse
            return i;  // Aranan elemanýn indeksini döndürürüz
        }
    }
    return -1;  //  Eðer aranan eleman dizide bulunamazsa, -1 deðerini döndürür ve fonksiyon sonlanýr.
}



void secimSiralamasi(int dizi[], int boyut) {  // bir fonksiyon daha tanýmladýk. Bu fonksiyon, bir diziyi seçerek sýralama algoritmasýný kullanarak sýralar.
    for (int i = 0; i < boyut - 1; i++) {
        int enKucukIndeks = i;   // bu degisken döngü adýmýndaki minimum elemanýn dizideki indeksini temsil eder.
        for (int j = i + 1; j < boyut; j++) { //ic ice dongu yapýldý . j i den bir sonraki indeksten baslayarak dizinin sonuna kadar artar
            if (dizi[j] < dizi[enKucukIndeks]) {  // j indeksindeki eleman, mevcut minimum elemandan daha küçükse,çalýþýr.
               enKucukIndeks = j;
            }
        }
        int gecici = dizi[i];  //gecici deðiþkeni, mevcut döngü adýmýndaki elemaný geçici olarak saklar.
        dizi[i] = dizi[enKucukIndeks]; //i indeksindeki eleman, minimum elemanla yer deðiþtirir.
        dizi[enKucukIndeks] = gecici;  //Minimum elemanýn bulunduðu indeksteki eleman, geçici olarak saklanan elemanla yer deðiþtirir.
    }
}

int main() {
    int boyut;  //boyut degýskeni tanýmladým
    printf("Dizinin boyutunu girin: ");
    scanf("%d", &boyut);    // kullanýcýdan dizi boyutu girmesini istedim

    int dizi[boyut]; //kullanincinin girdigi boyuta gore dizi tanimladim
    printf("Elemanlarý girin:\n");
    for (int i = 0; i < boyut; i++) {
        scanf("%d", &dizi[i]); //kulanicinin girdigi sayilari okur
    }

    secimSiralamasi(dizi,boyut);  // fonksiyonu cagirdim

    int aranan;  //degirsken tanýmladým
    printf("Aranacak elemaný girin: ");
    scanf("%d", &aranan);  // aranacak elemaný yazmasý ýcýn kullanýcýdan istedim

    int sonuc = dogrusalArama(dizi,boyut, aranan);  // dogrusal fonksiyon dizisini cagirarak sonuc degikenine atadim

    if (sonuc == -1) {
        printf("Aranan eleman bulunamadi");
    }
     else {
        printf("Aranan eleman dizinin %d. indeksinde bulunuyor.\n", sonuc);
    }

    return 0;
}

// bu programda amac secim sýralama algoritmasýný kullanarak istenilen elemnalarý once sýralamak sonra linearSEarch u kullanarak arama yapýlmasýný saglamak
