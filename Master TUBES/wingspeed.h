#ifndef WINGSPEED_H_INCLUDED
#define WINGSPEED_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

#define info(P) (P)->info
#define next(P) (P)->next
#define prev(P) (P)->prev
#define nextBarang(P) (P)->nextBarang
#define first(L) ((L).first)
#define last(L) ((L).last)
#define nil NULL


typedef struct elmHari *adrHari;
typedef struct elmBarang *adrBarang;

/////////////////////////////////////////////////////////////// HARI

struct hari {
    string kodeH;
    string date;
    string tipeP;
};

struct elmHari {
    hari info;
    adrHari prev;
    adrHari next;
    adrBarang nextBarang;
};

struct mllHari {
    adrHari first;
    adrHari last;
};

/////////////////////////////////////////////////////////////// BARANG

struct barang {
    string resi;
    string tanggal;
    string jenis;
    float berat;
    string tipeP;
    string penerima;
    string alamat;
    string fragility;
    string pengirim;
    float biaya;
};

struct elmBarang {
    barang info;
    adrBarang next;
    adrBarang prev;
};

struct mllBarang {
    adrBarang first;
    adrBarang last;
};

/////////////////////////////////////////////////////////////// BAGIAN CREATE

void createListHari(mllHari &L);
adrHari createElemenHari(hari dataBaru, adrHari P);
void createListBarang(mllBarang &L);
adrBarang createElemenBarang(barang dataBaru, adrBarang P);

/////////////////////////////////////////////////////////////// BAGIAN HARI

hari newDataHari(string kodeH, string date, string tipeP);
void insertLastHari(mllHari &L, adrHari P);
void showDataHari (mllHari DataPengiriman);

adrHari deleteFirstHari(mllHari &L);
adrHari deleteLastHari(mllHari &L);
adrHari deleteAfterHari(adrHari prec);
void deleteHari(mllHari &L, adrHari prec);

/////////////////////////////////////////////////////////////// BAGIAN DELETE RELASI & CREATE RELASI

adrBarang deleteRelasi(mllHari &L, mllBarang &temp, adrHari S);
void createRelasi(mllHari &L, adrBarang P, adrHari S);

/////////////////////////////////////////////////////////////// BAGIAN BARANG

barang newDataBarang(string resi, string tanggal, string jenis, float berat, string tipeP, string penerima, string alamat, string fragility, string pengirim);
void insertLastBarang(mllHari &ListHari, mllBarang &ListBarang, adrBarang J);
void ShowDataBarang(mllHari L);
void insertBarang (mllBarang &L, adrBarang P);
void deleteFirstBarang(mllHari &L, adrBarang prec);
void deleteLastBarang(mllHari &L, adrBarang prec);
void deleteAfterBarang(mllHari &L, adrBarang prec);
void deleteBarang(mllHari &S ,adrBarang prec);

////////////////////////////////////////////////////////////// BAGIAN FUNGSI FIND

adrHari findParent (mllHari L, string kode);
adrHari findDataEntry(mllHari L ,string tanggal, string tipeP);
adrBarang findChild(mllHari L, string kode);
bool findDuplH(mllHari L, string kodeH);
bool findDuplB(mllHari L, string resi);
void findResi(mllHari L);
void findPaket(mllHari L);

////////////////////////////////////////////////////////////// BAGIAN UNIVERSAL

float hitungBiaya(float berat, string paket);
void ShowAllData(mllHari L);
void preLoadData(mllHari &ListHari, mllBarang &ListBarang);
void banyakBarang (mllHari L);

//////////////////////////////////////////////////////////////

void mainMenu();

//////////////////////////////////////////////////////////////

#endif // WINGSPEED_H_INCLUDED
