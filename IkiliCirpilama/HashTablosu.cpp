#include "HashTablosu.hpp"

HashTablosu::HashTablosu()
{
    for (int i = 0; i < MAX; i++)
        elemanlar[i] = -1;
}


void HashTablosu::ekle(int veri)
{
    if (elemanSayisi >= MAX)
        return;

    int index = hash1(veri);
    if (elemanlar[index] != -1)
    {
        int adim = hash2(veri);
        int tur = 1;
        while (true)
        {
            int yeniIndex = (index + tur * adim) % MAX;
            if (elemanlar[yeniIndex] == -1)
            {
                elemanlar[yeniIndex] = veri;
                break;
            }
            tur++;
        }
    }
    else
    {
        elemanlar[index] = veri;
    }
    elemanSayisi++;
}
//...devamý gelecek
void HashTablosu::cikar(int veri)
{
    if (elemanSayisi == 0)
        return;
    int index = hash1(veri);
    //aradýðýmýz eleman direk ilgili indekste bulundu.
    if (elemanlar[index] == veri)
    {
        elemanlar[index] = -1;
        elemanSayisi--;

    }
    else
    {
        //aradýðýmýz eleman ilk indeksinde bulunamadý
        //ileri konumlara yerleþtirilmiþ olmalý.
        int adim = hash2(veri);
        int tur = 1;//bir elemaný zaten taradýk
        while (tur <= elemanSayisi)
        {
            int yeniIndex = (index + tur * adim) % MAX;
            if (elemanlar[yeniIndex] == veri)
            {
                elemanlar[yeniIndex] = -1;
                elemanSayisi--;
                break;
            }
            tur++;
        }
    }

}

bool HashTablosu::bul(int veri)
{
    return true;
}

int HashTablosu::hash1(int anahtar) {
    return anahtar % MAX;
}
int HashTablosu::hash2(int anahtar) {
    return YAKIN - (anahtar % YAKIN);
}
ostream& operator<<(ostream& os, HashTablosu& tablo)
{
    for (int i = 0; i < MAX; i++)
    {
        if (tablo.elemanlar[i] != -1)
            cout << "[" << i << "]\t:" << tablo.elemanlar[i] << endl;
        else
            cout << "[" << i << "]\t:" << endl;
    }
    return os;
}

int main()
{
    HashTablosu hash;
    hash.ekle(11);
    hash.ekle(77);
    hash.ekle(112);
    hash.ekle(33);
    hash.ekle(44);
    hash.ekle(213);
    hash.ekle(66);
    cout << hash;
    hash.cikar(11);
    hash.cikar(112);
    hash.cikar(213);
    hash.cikar(11);
    cout << hash;

}