#include "wingspeed.h"

void createListHari(mllHari &L) {
    first(L) = nil;
    last(L) = nil;
}

void createListBarang(mllBarang &L) {
    first(L) = nil;
    last(L) = nil;
}

////////////////////////////////////////////// BAGIAN HARI

hari newDataHari(string kodeH, string date, string tipeP) {
    hari data;

    data.kodeH = kodeH;
    data.date = date;
    data.tipeP = tipeP;

    return data;
}

adrHari createElemenHari(hari dataBaru, adrHari P) {
    P = new elmHari;

    info(P).kodeH = dataBaru.kodeH;
    info(P).date = dataBaru.date;
    info(P).tipeP = dataBaru.tipeP;
    next(P) = nil;
    prev(P) = nil;
    nextBarang(P) = nil;

    return P;
}

void showDataHari (mllHari DataPengiriman){
    adrHari P;

    P = first(DataPengiriman);

    if (P != nil) {
        while(P != nil) {
            cout << "Kode Hari       : "<< info(P).kodeH << endl;
            cout << "Tanggal         : "<< info(P).date << endl;
            cout << "Tipe Pengiriman : " << info(P).tipeP << endl;
            P = next(P);
            cout << endl;
        }
    } else {
        cout << "             Data Kosong            " << endl;
    }

}

void insertLastHari(mllHari &ListHari, adrHari P){
    if (first(ListHari) == nil) {
        first(ListHari) = P;
        last(ListHari) = P;
    } else {
        next(last(ListHari)) = P;
        prev(P) = last(ListHari);
        last(ListHari) = P;
    }
}

adrHari deleteFirstHari(mllHari &ListHari) {
    adrHari P;

    P = first(ListHari);
    if (next(first(ListHari)) == nil) {
        first(ListHari) = nil;
        last(ListHari) = nil;
    } else {
        first(ListHari) = next(first(ListHari));
        prev(first(ListHari)) = nil;
        next(P) = nil;
    }

    return P;
}

adrHari deleteLastHari(mllHari &ListHari) {
    adrHari P;

    P = last(ListHari);

    if (prev(last(ListHari)) != nil) {
        last(ListHari) = prev(last(ListHari));
        prev(P) = nil;
        next(last(ListHari)) = nil;
    } else {
        first(ListHari) = nil;
        last(ListHari) = nil;
    }
}

adrHari deleteAfterHari(adrHari prec) {
    adrHari P;

    P = next(prec);
    next(prec) = next(P);
    prev(next(P)) = prec;
    prev(P) = nil;
    next(P) = nil;

    return P;
}

void deleteHari(mllHari &ListHari, adrHari prec) {
    adrHari P;
    adrHari Q;

    P = nil;
    Q = first(ListHari);
    while (Q != nil){
        if (Q == prec){
            P = Q;
        }
        Q = next(Q);
    }
    if (P != nil){
        if (P == first(ListHari)){
            deleteFirstHari(ListHari);
        } else if (next(P) == nil){
            deleteLastHari(ListHari);
        } else {
            prec = first(ListHari);
            while (next(prec) != P){
                prec = next(prec);
            }
            deleteAfterHari(prec);
        }
    }
}


adrBarang deleteRelasi(mllHari &ListHari, mllBarang &temp, adrHari S) {
    adrBarang P, R;
    adrHari Q = first(ListHari);
    bool cek;

    cek = findDuplH(ListHari, info(S).kodeH);

    if (cek) {
        while (Q != nil) {
            if (Q == S) {
                R = first(temp);
                P = nextBarang(Q);
                R = P;
                nextBarang(Q) = nil;
            }
            Q = next(Q);
        }
        cout << "============================================" << endl;
        cout << "          Relasi Berhasil Dihapus           " << endl;

    } else {
        cout << "============================================" << endl;
        cout << "            Relasi Gagal Dihapus            " << endl;

    }

    return R;
}

void createRelasi(mllHari &ListHari, adrBarang P, adrHari S) {
    adrHari Q = first(ListHari);
    bool cek;

    cek = findDuplH(ListHari, info(S).kodeH);

    if (cek) {
        while (Q != nil) {
            if (Q == S) {
                nextBarang(Q) = P;
            }
            Q = next(Q);
        }
        cout << "============================================" << endl;
        cout << "           Relasi Berhasil Dibuat           " << endl;

    } else {
        cout << "============================================" << endl;
        cout << "            Relasi Gagal Dibuat             " << endl;

    }
}

////////////////////////////////////////////// BAGIAN BARANG

barang newDataBarang(string resi, string tanggal, string jenis, float berat, string tipeP, string penerima, string alamat, string fragility, string pengirim) {
    barang data;

    data.resi = resi;
    data.tanggal = tanggal;
    data.jenis = jenis;
    data.berat = berat;
    data.tipeP = tipeP;
    data.penerima = penerima;
    data.alamat = alamat;
    data.fragility = fragility;
    data.pengirim = pengirim;

    return data;
}

adrBarang createElemenBarang(barang dataBaru, adrBarang P) {
    P = new elmBarang;

    info(P).resi = dataBaru.resi;
    info(P).tanggal = dataBaru.tanggal;
    info(P).jenis = dataBaru.jenis;
    info(P).berat = dataBaru.berat;
    info(P).tipeP = dataBaru.tipeP;
    info(P).penerima = dataBaru.penerima;
    info(P).alamat = dataBaru.alamat;
    info(P).fragility = dataBaru.fragility;
    info(P).pengirim = dataBaru.pengirim;

    next(P) = nil;
    prev(P) = nil;

    return P;
}

void deleteFirstBarang(mllHari &ListHari, adrBarang prec) {
    adrBarang P;
    adrBarang S;
    adrHari Q;

    Q = first(ListHari);
    while (Q != nil){
        P = nextBarang(Q);
        while (P != nil){
            if (P == prec) {
                nextBarang(Q) = next(P);
                next(P) = nil;
                prev(P) = nil;

            }
            P = next(P);
        }
        Q = next(Q);
    }

}

void deleteLastBarang(mllHari &ListHari, adrBarang prec) {
    adrBarang P;
    adrBarang R;
    adrHari Q;

    Q = first(ListHari);
    while (Q != nil){
        P = nextBarang(Q);
        while (P != nil){
            if (P != prec) {
                if (next(P) == prec) {
                    R = next(P);
                    next(P) = nil;
                    prev(R) = nil;
                    next(R) = nil;

                }
            }
            P = next(P);
        }
        Q = next(Q);
    }
}

void deleteAfterBarang(mllHari &ListHari, adrBarang prec) {
    adrBarang P;
    adrBarang R;
    adrBarang S;
    adrHari Q;

    Q = first(ListHari);
    while (Q != nil){
        P = nextBarang(Q);
        while (P != nil){
            if (P != prec) {
                if (next(P) == prec) {
                    R = next(P);
                    prev(next(P)) = prev(P);
                    next(P) = next(R);
                    prev(R) = nil;
                    next(R) = nil;

                }
            }
            P = next(P);
        }
        Q = next(Q);
    }

}

void deleteBarang(mllHari &ListHari ,adrBarang prec) {
    adrBarang P, R;
    adrHari Q = first(ListHari);

    while (Q != nil) {
        P = nextBarang(Q);
        while (P != nil) {
            if (P == prec) {
                if (P != nil) {
                    if (P == nextBarang(Q)) {
                        deleteFirstBarang(ListHari, prec);
                    } else if (next(P) == nil) {
                        deleteLastBarang(ListHari, prec);
                    } else {
                        deleteAfterBarang(ListHari, prec);
                    }
                }
                break;
            }
            P = next(P);
        }
        Q = next(Q);
    }
}

void insertLastBarang(mllHari &ListHari, mllBarang &ListBarang, adrBarang J) {
    adrBarang P;

    adrHari S;

    S = findDataEntry(ListHari, info(J).tanggal, info(J).tipeP);

    P = nextBarang(S);

    if (nextBarang(S) == nil){
        nextBarang(S) = J;
    }else{
        while (next(P) != nil){
            P = next(P);
        }

        next(P) = J;
    }
}

void ShowDataBarang(mllHari L){
    adrBarang P;
    adrHari Q;
    int i = 1;

    Q = first(L);
    if (Q != nil) {
        while (Q != nil){
            P = nextBarang(Q);
            while (P != nil){
                cout << "============================================" << endl;
                cout << "Barang ke-" << i << endl;

                cout << "Resi             : " << info(P).resi << endl;
                cout << "Tanggal          : " << info(P).tanggal << endl;
                cout << "Jenis Barang     : " << info(P).jenis << endl;
                cout << "Berat Barang     : " << info(P).berat << " Kg" << endl;
                cout << "Tipe Pengiriman  : " << info(P).tipeP << endl;
                cout << "Nama Penerima    : " << info(P).penerima << endl;
                cout << "Alamat Tujuan    : " << info(P).alamat << endl;
                cout << "Fragility        : " << info(P).fragility << endl;
                cout << "Nama Pengirim    : " << info(P).pengirim << endl;

                info(P).biaya = hitungBiaya(info(P).berat, info(P).tipeP);
                cout << "Biaya Pengiriman : " << "Rp. " << info(P).biaya << endl;

                P = next(P);
                i++;
            }
            Q = next(Q);
        }
        cout << endl;
    } else {
        cout << "                Data Kosong               " << endl;
    }
}

////////////////////////////////////////////// BAGIAN UNIVERSAL


float hitungBiaya(float berat, string paket) {
    int beratA = berat;

    if (paket == "Low Speed") {
        if (berat <= 1) {
            return 8000;
        } else {
            return (8000 * beratA);
        }
    } else if (paket == "Normal Speed") {
        if (berat <= 1) {
            return 10000;
        } else {
            return (10000 * beratA);
        }
    } else if (paket == "High Speed") {
        if (berat <= 1) {
            return 12000;
        } else {
            return (12000 * beratA);
        }
    }

}

void ShowAllData(mllHari L){
    adrBarang P;
    adrHari Q;
    int i = 1;

    cout << "                 DATABASE                 " << endl;

    Q = first(L);
    if (Q != nil) {
        while (Q != nil){
            cout << "============================================" << endl;
            cout << "Kode Hari         : " << info(Q).kodeH << endl;
            cout << "Tanggal           : " << info(Q).date << endl;
            cout << "Tipe Pengiriman   : " << info(Q).tipeP << endl;

            P = nextBarang(Q);
            i = 1;
            while (P != nil){
                cout << "--------------------------------------------" << endl;
                cout << "Barang ke-" << i << endl;

                cout << "Resi             : " << info(P).resi << endl;
                cout << "Tanggal          : " << info(P).tanggal << endl;
                cout << "Jenis Barang     : " << info(P).jenis << endl;
                cout << "Berat Barang     : " << info(P).berat << " Kg" << endl;
                cout << "Tipe Pengiriman  : " << info(P).tipeP << endl;
                cout << "Nama Penerima    : " << info(P).penerima << endl;
                cout << "Alamat Tujuan    : " << info(P).alamat << endl;
                cout << "Fragility        : " << info(P).fragility << endl;
                cout << "Nama Pengirim    : " << info(P).pengirim << endl;

                info(P).biaya = hitungBiaya(info(P).berat, info(P).tipeP);
                cout << "Biaya Pengiriman : " << "Rp. " << info(P).biaya << endl;

                P = next(P);
                i++;
            }
            cout << endl << endl;
            Q = next(Q);
        }
    } else {
        cout << "============================================" << endl;
        cout << "                Data Kosong               " << endl;
    }
}


void banyakBarang (mllHari L){
    adrBarang P;
    adrHari Q, S;
    string diCari;
    int totalB = 0;
    int totalBiaya = 0;

    cout << "Masukkan Kode Hari    : ";
    cin >> diCari;
    cout << "============================================" << endl;
    S = findParent(L, diCari);

    Q = first(L);
    if (Q != nil) {
        while (Q != nil){
            if(Q == S){
                cout << "Kode Hari       : " << info(Q).kodeH << endl;
                cout << "Tanggal         : " << info(Q).date << endl;
                cout << "Tipe Pengiriman : " << info(Q).tipeP << endl;
                P = nextBarang(Q);
                while (P != nil){
                    totalB++;
                    info(P).biaya = hitungBiaya(info(P).berat, info(P).tipeP);
                    totalBiaya = totalBiaya + info(P).biaya;
                    P = next(P);
                }
                cout << "Banyak Barang   : " << totalB << endl;
                cout << "Total Harga     : " <<  "Rp."<<totalBiaya << endl;
                break;
            }
            Q = next(Q);
        }
        if (Q != S) {
            cout << "           Data Tidak Ditemukan             " << endl;
        }
    } else {
        cout << "                Data Kosong               " << endl;
    }

}

////////////////////////////////////////////// BAGIAN FIND

adrHari findParent (mllHari ListHari, string kode) {
    adrHari P = first(ListHari);
    adrHari Q;

    while (P != nil) {
        if (info(P).kodeH == kode) {
            Q = P;
        }
        P = next(P);
    }
    return Q;
}

adrBarang findChild(mllHari ListHari, string kode) {
    adrBarang P;
    adrBarang S;
    adrHari Q;

    Q = first(ListHari);
    while (Q != nil){
        P = nextBarang(Q);
        while (P != nil){
            if (info(P).resi == kode) {
                S = P;
            }
            P = next(P);
        }
        Q = next(Q);
    }

    return S;
}

adrHari findDataEntry(mllHari L ,string tanggal, string tipeP) {
    adrHari P = first(L);
    adrHari data;

    if (P != nil) {
        while (P != nil) {
            if (tanggal == info(P).date && tipeP == info(P).tipeP) {
                data = P;
            }
            P = next(P);
        }
    }
    return data;
}

void findPaket(mllHari L){
    adrBarang P, S;
    adrHari Q;
    bool tipeP;
    string diCari;

    cout << "Masukkan Resi    : ";
    cin >> diCari;
    cout << "============================================" << endl;
    S = findChild(L, diCari);

    tipeP = findDuplB(L, diCari);

    if (tipeP) {
        Q = first(L);
        while (Q != nil){
            P = nextBarang(Q);
            while (P != nil){
                if (S == P) {
                    cout << "Kode Hari        : " << info(Q).kodeH << endl;
                    cout << "Tanggal          : " << info(Q).date << endl;
                    cout << "Tipe Pengiriman  : " << info(Q).tipeP << endl << endl;

                    cout << "Resi             : " << info(P).resi << endl;
                    cout << "Tanggal          : " << info(P).tanggal << endl;
                    cout << "Jenis Barang     : " << info(P).jenis << endl;
                    cout << "Berat Barang     : " << info(P).berat << " Kg" << endl;
                    cout << "Nama Penerima    : " << info(P).penerima << endl;
                    cout << "Alamat Tujuan    : " << info(P).alamat << endl;
                    cout << "Fragility        : " << info(P).fragility << endl;
                    cout << "Nama Pengirim    : " << info(P).pengirim << endl;
                    info(P).biaya = hitungBiaya(info(P).berat, info(P).tipeP);
                    cout << "Biaya Pengiriman : " << "Rp. " << info(P).biaya << endl;
                }
                P = next(P);
            }
            Q = next(Q);
        }
    } else {
        cout << "             Barang Tidak ada             " << endl;
    }


}

bool findDuplH(mllHari L, string kodeH) {
    adrHari P;
    bool check = false;

    P = first(L);
    while(P != nil) {
        if(info(P).kodeH == kodeH) {
            check = true;
            return check;
        }
        P = next(P);
    }
    return check;
}

bool findDuplB(mllHari L, string resi) {
    adrBarang P, S;
    adrHari Q;
    bool check = false;

    S = findChild(L, resi);

    Q = first(L);
    while (Q != nil){
        P = nextBarang(Q);
        while (P != nil){
            if (S == P) {
                check = true;
                return check;
            }
            P = next(P);
        }
        Q = next(Q);
    }
    return check;
}

void findResi(mllHari L){
    adrBarang P, S;
    adrHari Q;
    bool tipeP;
    string diCari;

    cout << "Masukkan Nomor Resi    : ";
    cin >> diCari;
    cout << "============================================" << endl;
    S = findChild(L, diCari);

    tipeP = findDuplB(L, diCari);

    if (tipeP) {
        Q = first(L);
        while (Q != nil){
            P = nextBarang(Q);
            while (P != nil){
                if (S == P) {
                    cout << "              Resi Ditemukan              " << endl;
                }
                P = next(P);
            }
            Q = next(Q);
        }
    } else {
        cout << "        Nomor Resi Tidak Ditemukan" << endl;
    }


}

//////////////////////////////////////////////

void preLoadData(mllHari &ListHari, mllBarang &ListBarang) {
    adrHari dataHari;

    adrBarang dataBarang;

    hari data;
    barang dataB;

    createListHari(ListHari);
    createListBarang(ListBarang);

    data = newDataHari("00121421", "12-14-2021", "Low Speed");
    dataHari = createElemenHari(data, dataHari);
    insertLastHari(ListHari, dataHari);

    data = newDataHari("01121421", "12-14-2021", "Normal Speed");
    dataHari = createElemenHari(data, dataHari);
    insertLastHari(ListHari, dataHari);

    data = newDataHari("02121421", "12-14-2021", "High Speed");
    dataHari = createElemenHari(data, dataHari);
    insertLastHari(ListHari, dataHari);

    dataB = newDataBarang("00121421001", "12-14-2021", "Baju", 0.5, "Low Speed", "Udin", "Bandung", "No", "Yayan");
    dataBarang = createElemenBarang(dataB, dataBarang);
    insertLastBarang(ListHari, ListBarang, dataBarang);

    dataB = newDataBarang("00121421002", "12-14-2021", "Laptop", 5, "Low Speed", "Tatang", "Jakarta", "Yes", "Yayan");
    dataBarang = createElemenBarang(dataB, dataBarang);
    insertLastBarang(ListHari, ListBarang, dataBarang);

    dataB = newDataBarang("00121421003", "12-14-2021", "Monitor", 6, "Low Speed", "Yayan", "Surabaya", "Yes", "Babang");
    dataBarang = createElemenBarang(dataB, dataBarang);
    insertLastBarang(ListHari, ListBarang, dataBarang);

    dataB = newDataBarang("00121421004", "12-14-2021", "Mainan", 0.7, "Low Speed", "Atsal", "Cirebon", "Nos", "Yanto");
    dataBarang = createElemenBarang(dataB, dataBarang);
    insertLastBarang(ListHari, ListBarang, dataBarang);

    dataB = newDataBarang("01121421001", "12-14-2021", "Vas", 4, "Normal Speed", "Ruhian", "Depok", "Yes", "Yayan");
    dataBarang = createElemenBarang(dataB, dataBarang);
    insertLastBarang(ListHari, ListBarang, dataBarang);

    dataB = newDataBarang("01121421002", "12-14-2021", "Bass", 4, "Normal Speed", "Ruhian", "Bandung", "Yes", "Yayan");
    dataBarang = createElemenBarang(dataB, dataBarang);
    insertLastBarang(ListHari, ListBarang, dataBarang);

    dataB = newDataBarang("01121421003", "12-14-2021", "Gitar", 4, "Normal Speed", "Ruhian", "Cilegon", "Yes", "Tatang");
    dataBarang = createElemenBarang(dataB, dataBarang);
    insertLastBarang(ListHari, ListBarang, dataBarang);

    dataB = newDataBarang("02121421001", "12-14-2021", "Violin", 4, "High Speed", "Ruhian", "Pekanbaru", "Yes", "Yayan");
    dataBarang = createElemenBarang(dataB, dataBarang);
    insertLastBarang(ListHari, ListBarang, dataBarang);

    dataB = newDataBarang("02121421002", "12-14-2021", "Mainan", 4, "High Speed", "Ruhian", "Palembang", "Yes", "Tatang");
    dataBarang = createElemenBarang(dataB, dataBarang);
    insertLastBarang(ListHari, ListBarang, dataBarang);
}

void mainMenu() {
    mllHari ListHari;

    mllBarang ListBarang;
    mllBarang temp;

    createListHari(ListHari);
    createListBarang(temp);
    createListBarang(ListBarang);

    adrHari dataHari;
    adrHari checkDupl;
    adrHari cariDataResi;
    adrHari cariDataHari;
    adrHari cariH;

    adrBarang dataBarang;
    adrBarang tempB;
    adrBarang tempE;

    hari data;
    barang dataB;

    int menu;
    string Back = "Y" ;

    string kodeH, date , tipePengiriman;
    int tipePengirimanPil;
    bool tipeP;
    adrHari cariHari;

    string resi, jenis, penerima, pengirim, fragility;
    string alamat;
    float berat;
    string resiP;
    string kodeSlow = "00";
    string kodeNorm = "01";
    string kodeFast = "02";

    int intResi;

    string hariMM, hariDD, year;

    cout << "     ****WINGSPEED****     " << endl;
    while (Back != "N" || Back != "n") {
        if (Back == "Y" || Back == "y") {
                cout << "        ---Menu---         " << endl;
                cout << "1.  Insert Data Hari       " << endl;
                cout << "2.  Delete Data Hari       " << endl;
                cout << "3.  Show Data Hari         " << endl;
                cout << "4.  Find Hari              " << endl;
                cout << "5.  Insert Paket           " << endl;
                cout << "6.  Delete Paket           " << endl;
                cout << "7.  Show Data Paket        " << endl;
                cout << "8.  Find Paket             " << endl;
                cout << "9.  Delete Relation        " << endl;
                cout << "10. Create Relation        " << endl;
                cout << "11. Banyak barang perhari  " << endl;
                cout << "12. Cari Resi              " << endl;
                cout << "13. Load Preloaded Data    " << endl;
                cout << "14. Show All Data          " << endl;
                cout << "0.  Exit                   " << endl;
                cout << "============================================" << endl;

                cout << "Masukkan menu : ";
                cin >> menu;
                cout << "============================================" << endl;
                if (menu == 1) {
                    cout << "          TIPE PENGIRIMAN           " << endl;
                    cout << "1. Low Speed       " << endl;
                    cout << "2. Normal Speed    " << endl;
                    cout << "3. High Speed      " << endl;
                    cout << "============================================" << endl;

                    cout << "Masukkan Tanggal (MM-DD-YYYY): ";
                    cin >> date;

                    cout << "Masukkan Tipe Pengiriman     : ";
                    cin >> tipePengirimanPil;

                    if (tipePengirimanPil == 1) {
                        tipePengiriman = "Low Speed";

                    } else if (tipePengirimanPil == 2) {
                        tipePengiriman = "Normal Speed";

                    } else if (tipePengirimanPil == 3) {
                        tipePengiriman = "High Speed";

                    }

                    hariMM = date.substr(0,2);
                    hariDD = date.substr(3, 2);
                    year = date.substr(8, 2);

                    kodeH = hariMM + hariDD + year;

                    if (tipePengirimanPil == 1) {
                        kodeH = kodeSlow + kodeH;

                    } else if (tipePengirimanPil == 2) {
                        kodeH = kodeNorm + kodeH;

                    } else if (tipePengirimanPil == 3) {
                        kodeH = kodeFast + kodeH;

                    }

                    tipeP = findDuplH(ListHari, kodeH);

                    if(!tipeP) {
                        data = newDataHari(kodeH, date, tipePengiriman);
                        dataHari = createElemenHari(data, dataHari);
                        insertLastHari(ListHari, dataHari);
                    } else {
                        cout << "============================================" << endl;
                        cout << "          Data Hari Sudah Ada        " << endl;
                    }

                } else if (menu == 2) {
                    cout << "Masukkan Kode Hari (XXMMDDYY): ";
                    cin >> kodeH;

                    tipeP = findDuplH(ListHari, kodeH);

                    if (tipeP) {
                        cariHari = findParent(ListHari, kodeH);

                        deleteHari(ListHari, cariHari);
                    } else {
                        cout << "============================================" << endl;
                        cout << "          Data Hari Tidak Ada        " << endl;
                    }

                } else if (menu == 3){
                    showDataHari(ListHari);

                } else if (menu == 4) {
                    cout << "Masukkan Kode Hari (XXMMDDYY): ";
                    cin >> kodeH;

                    tipeP = findDuplH(ListHari, kodeH);
                    cariHari = findParent(ListHari, kodeH);

                    if (tipeP) {
                        cout << "============================================" << endl;
                        cout << "Kode Hari       : " << info(cariHari).kodeH << endl;
                        cout << "Tanggal         : " << info(cariHari).date << endl;
                        cout << "Tipe Pengiriman : " << info(cariHari).tipeP << endl;

                    } else {
                        cout << "============================================" << endl;
                        cout << "         Data Hari Tidak Ada        " << endl;

                    }

                } else if (menu == 5) {
                    cout << "          TIPE PENGIRIMAN           " << endl;
                    cout << "1. Low Speed " << endl;
                    cout << "2. Normal Speed " << endl;
                    cout << "3. High Speed" << endl;
                    cout << "============================================" << endl;

                    cout << "Masukkan Tanggal (MM-DD-YYYY): ";
                    cin >> date;

                    cout << "Masukkan Jenis Barang        : ";
                    cin >> jenis;

                    cout << "Masukkan Berat Barang        : ";
                    cin >> berat;

                    cout << "Masukkan Tipe Pengiriman     : ";
                    cin >> tipePengirimanPil;

                    if (tipePengirimanPil == 1) {
                        tipePengiriman = "Low Speed";

                    } else if (tipePengirimanPil == 2) {
                        tipePengiriman = "Normal Speed";

                    } else if (tipePengirimanPil == 3) {
                        tipePengiriman = "High Speed";

                    }

                    cout << "Masukkan Nama Penerima       : ";
                    cin >> penerima;

                    cout << "Masukkan Alamat Tujuan       : ";
                    cin.ignore();
                    getline(cin, alamat);

                    cout << "Masukkan Fragility (Yes/No)  : ";
                    cin >> fragility;

                    cout << "Masukkan Nama Pengirim       : ";
                    cin >> pengirim;

                    cariDataResi = findDataEntry(ListHari, date, tipePengiriman);

                    if (info(cariDataResi).kodeH != "") {
                        resiP = info(cariDataResi).kodeH;
                        resi = resiP.substr(2, 6);
                        resi = resi + "000";
                        intResi = stoi(resi);
                        intResi = intResi + 1;

                        adrHari S = findDataEntry(ListHari, date, tipePengiriman);

                        if (tipePengirimanPil == 1) {
                            resi = kodeSlow + to_string(intResi);

                        } else if (tipePengirimanPil == 2) {
                            resi = kodeNorm + to_string(intResi);

                        } else if (tipePengirimanPil == 3) {
                            resi = kodeFast + to_string(intResi);

                        }

                        tipeP = findDuplB(ListHari, resi);

                        if (info(S).date == date && info(S).tipeP == tipePengiriman) {
                            if(!tipeP) {
                                dataB = newDataBarang(resi, date, jenis, berat, tipePengiriman, penerima, alamat, fragility, pengirim);
                                dataBarang = createElemenBarang(dataB, dataBarang);
                                insertLastBarang(ListHari, ListBarang, dataBarang);

                            } else {
                                while (tipeP) {
                                    intResi = stoi(resi);
                                    intResi = intResi + 1;

                                    if (tipePengirimanPil == 1) {
                                        resi = kodeSlow + to_string(intResi);

                                    } else if (tipePengirimanPil == 2) {
                                        resi = kodeNorm + to_string(intResi - 10000000);

                                    } else if (tipePengirimanPil == 3) {
                                        resi = kodeFast + to_string(intResi - 20000000);

                                    }

                                    tipeP = findDuplB(ListHari, resi);

                                }
                                dataB = newDataBarang(resi, date, jenis, berat, tipePengiriman, penerima, alamat, fragility, pengirim);
                                dataBarang = createElemenBarang(dataB, dataBarang);
                                insertLastBarang(ListHari, ListBarang, dataBarang);

                            }

                        } else {
                            cout << "============================================" << endl;
                            cout << "          Data Hari Belum Ada" << endl;
                        }
                    } else {
                            cout << "============================================" << endl;
                            cout << "          Data Hari Belum Ada" << endl;
                    }

                } else if (menu == 6) {
                    cout << "Masukkan Resi : ";
                    cin >> resi;

                    tipeP = findDuplB(ListHari, resi);

                    if (tipeP) {
                        dataBarang = findChild(ListHari, resi);

                        deleteBarang(ListHari, dataBarang);

                    } else {
                        cout << "============================================" << endl;
                        cout << "            Barang Tidak ada" << endl;

                    }

                } else if (menu == 7){
                    ShowDataBarang(ListHari);

                } else if (menu == 8){
                    findPaket(ListHari);

                } else if (menu == 9){
                    cout << "Masukkan Kode Hari (XXMMDDYY): ";
                    cin >> kodeH;

                    cariH = findParent(ListHari, kodeH);

                    tempB = deleteRelasi(ListHari, temp, cariH);

                } else if (menu == 10){
                    cout << "Masukkan Kode Hari (XXMMDDYY): ";
                    cin >> kodeH;

                    cariH = findParent(ListHari, kodeH);
                    createRelasi(ListHari, tempB, cariH);

                } else if (menu == 11){
                    banyakBarang(ListHari);

                } else if (menu == 12){
                    findResi(ListHari);

                } else if (menu == 13) {
                    preLoadData(ListHari, ListBarang);
                    cout << "                LOAD SUCCESS                " << endl;

                } else if (menu == 14) {
                    ShowAllData(ListHari);

                } else if (menu == 69) {
                    // Fungsi TESTING

                } else if (menu == 0) {
                    cout << endl;
                    cout << "ANDA KELUAR DARI PROGRAM!" << endl;
                    break;

                }  else {
                    cout << "     Input yang anda masukkan salah!" << endl;

                }

        } else {
            cout << "============================================" << endl;
            cout << "     Input yang anda masukkan salah!" << endl;

        }

        cout << "============================================" << endl;
        cout << "Kembali ke menu utama? (Y/N) : ";
        cin >> Back;
        cout << endl;

        if (Back == "N" || Back == "n") {
            cout << "============================================" << endl << endl;
            cout << "ANDA KELUAR DARI PROGRAM!" << endl;
            break;

        }
    }
}
