#include <iostream>
#include <string>
#include "book.h"
#include "author.h"
#include "relation.h"

using namespace std;

int main() {
    HeaderParent HP;
    createListParent(HP);
    
    HeaderChild HC;
    createListChild(HC);

    int pilihan;
    string namaPenulis, judulBuku, kategori;
    int tahun;
    
    adrParent P;
    adrChild C;
        cout << "\n+==========================================+" << endl;
        cout << "| NO |       APLIKASI PERPUSTAKAAN         |" << endl;
        cout << "+====+=====================================+" << endl;
        cout << "| 1  | Tambah Penulis                      |" << endl;
        cout << "| 2  | Tambah Buku                         |" << endl;
        cout << "| 3  | Hubungkan (Relasi)                  |" << endl;
        cout << "+----+-------------------------------------+" << endl;
        cout << "| 4  | Tampilkan Semua                     |" << endl;
        cout << "| 5  | Cari Buku Penulis                   |" << endl;
        cout << "| 8  | Tampilkan Top 3 Penulis             |" << endl;
        cout << "+----+-------------------------------------+" << endl;
        cout << "| 6  | Hapus Penulis                       |" << endl;
        cout << "| 7  | Hapus Relasi Buku                   |" << endl;
        cout << "+----+-------------------------------------+" << endl;
        cout << "| 0  | Keluar                              |" << endl;
        cout << "+==========================================+" << endl;
        cout << "Masukan Pilihan: ";
    cin >> pilihan;

    switch (pilihan) {
    case 1:
        cout << "Nama Penulis: ";
        cin >> namaPenulis;
        P = alokasiParent(namaPenulis);
        insertLastParent(HP, P);
        break;

    case 2:
        { 
            cout << "Judul Buku: "; 
            cin >> judulBuku;
            cout << "Tahun: "; 
            cin >> tahun;
            cout << "Kategori: "; 
            cin >> kategori;

            infotype_buku dataBuku;
            dataBuku.judul = judulBuku;
            dataBuku.tahunTerbit = tahun;
            dataBuku.kategori = kategori;

            C = alokasiChild(dataBuku);
            insertLastChild(HC, C);
        }
        break;

    case 3:
        cout << "Nama Penulis: "; 
        cin >> namaPenulis;
        cout << "Judul Buku: "; 
        cin >> judulBuku;
        P = searchPenulis(HP, namaPenulis);
        C = searchBuku(HC, judulBuku);
        if (P != NULL && C != NULL) {
            tambahRelasi(P, C);
        }
        break;

    case 4:
        tampilkanSemua(HP, HC);
        break;

    case 5:
        cout << "Nama Penulis: "; 
        cin >> namaPenulis;
        tampilkanBukuPenulis(HP, namaPenulis);
        break;

    case 6:
        cout << "Hapus Penulis: "; 
        cin >> namaPenulis;
        deletePenulis(HP, namaPenulis);
        break;

    case 7:
        cout << "Nama Penulis: "; 
        cin >> namaPenulis;
        cout << "Judul Buku: ";
         cin >> judulBuku;
        P = searchPenulis(HP, namaPenulis);
        if (P != NULL) {
            deleteRelasi(P, judulBuku);
        }
        break;

    case 8:
        topThree(HP);
        break;

    case 0:
        return 0;

    default:
        cout << "Pilihan salah." << endl;
    }

    return 0;
}