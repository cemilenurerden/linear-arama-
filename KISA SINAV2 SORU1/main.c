#include <stdio.h>

int dogrusalArama(int dizi[], int boyut, int aranan_eleman) {  //.fonksiyon tan�mlad�m. bu fonksiyon, bir dizide arama yapar ve aranan eleman�n dizideki indeksini d�nd�r�r.
    for (int i = 0; i < boyut; i++) {
        if (dizi[i] == aranan_eleman) {  // e�er dizimiz arad���m�z elemana e�itse
            return i;  // Aranan eleman�n indeksini d�nd�r�r�z
        }
    }
    return -1;  //  E�er aranan eleman dizide bulunamazsa, -1 de�erini d�nd�r�r ve fonksiyon sonlan�r.
}



void secimSiralamasi(int dizi[], int boyut) {  // bir fonksiyon daha tan�mlad�k. Bu fonksiyon, bir diziyi se�erek s�ralama algoritmas�n� kullanarak s�ralar.
    for (int i = 0; i < boyut - 1; i++) {
        int enKucukIndeks = i;   // bu degisken d�ng� ad�m�ndaki minimum eleman�n dizideki indeksini temsil eder.
        for (int j = i + 1; j < boyut; j++) { //ic ice dongu yap�ld� . j i den bir sonraki indeksten baslayarak dizinin sonuna kadar artar
            if (dizi[j] < dizi[enKucukIndeks]) {  // j indeksindeki eleman, mevcut minimum elemandan daha k���kse,�al���r.
               enKucukIndeks = j;
            }
        }
        int gecici = dizi[i];  //gecici de�i�keni, mevcut d�ng� ad�m�ndaki eleman� ge�ici olarak saklar.
        dizi[i] = dizi[enKucukIndeks]; //i indeksindeki eleman, minimum elemanla yer de�i�tirir.
        dizi[enKucukIndeks] = gecici;  //Minimum eleman�n bulundu�u indeksteki eleman, ge�ici olarak saklanan elemanla yer de�i�tirir.
    }
}

int main() {
    int boyut;  //boyut deg�skeni tan�mlad�m
    printf("Dizinin boyutunu girin: ");
    scanf("%d", &boyut);    // kullan�c�dan dizi boyutu girmesini istedim

    int dizi[boyut]; //kullanincinin girdigi boyuta gore dizi tanimladim
    printf("Elemanlar� girin:\n");
    for (int i = 0; i < boyut; i++) {
        scanf("%d", &dizi[i]); //kulanicinin girdigi sayilari okur
    }

    secimSiralamasi(dizi,boyut);  // fonksiyonu cagirdim

    int aranan;  //degirsken tan�mlad�m
    printf("Aranacak eleman� girin: ");
    scanf("%d", &aranan);  // aranacak eleman� yazmas� �c�n kullan�c�dan istedim

    int sonuc = dogrusalArama(dizi,boyut, aranan);  // dogrusal fonksiyon dizisini cagirarak sonuc degikenine atadim

    if (sonuc == -1) {
        printf("Aranan eleman bulunamadi");
    }
     else {
        printf("Aranan eleman dizinin %d. indeksinde bulunuyor.\n", sonuc);
    }

    return 0;
}

// bu programda amac secim s�ralama algoritmas�n� kullanarak istenilen elemnalar� once s�ralamak sonra linearSEarch u kullanarak arama yap�lmas�n� saglamak
